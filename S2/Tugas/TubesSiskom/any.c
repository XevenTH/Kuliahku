// Compile command:
// gcc main.c -o main -Wall `pkg-config fuse --cflags` `pkg-config fuse --libs` -L. -lrequests -lcurl json.c -lm
#include "requests.h"
#include "json.h"

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdbool.h>
#include <string.h>
#include <fcntl.h>
#include <dirent.h>
#include <errno.h>

static const char *mount_dir = "/home/starcr/Documents";
struct stat st = {0};
char data_dir[255];

// Mengambil data dari API
json_value *get_data(char *api_url, json_value *data_object)
{
    req_t req;                     // req, untuk menyimpan hasil request data
    int ret = requests_init(&req); // Menyiapkan req
    if (ret)
    {
        return NULL; // Keluar, jika req gagal/tidak siap menyimpan hasil request
    }

    requests_get(&req, api_url); // Mengirim GET Request ke url sekaligus menyimpan hasilnya di req
    printf("Request URL: %s\n", req.url);
    printf("Request Code: %lu\n", req.code);
    data_object = json_parse(req.text, req.size); // Mengubah text yang didapat menjadi JSON

    requests_close(&req); // Membersihkan req

    return data_object;
}

// Membuat folder/directory
int make_directory(char *path)
{
    if (stat(path, &st) == -1)
    {
        if (mkdir(path, 0777) == 0)
        {
            printf("\n--> Direktori [%s] berhasil dibuat\n", path);
            return 0;
        }
        else
        {
            printf("\n--> Direktori [%s] gagal dibuat\n", path);
            return -1;
        }
    }

    return 1;
}

void download_image(char *url, char *cwd, char *name, char *format)
{
    pid_t child_id;
    int status;

    child_id = fork();
    wait(&status);

    if (child_id == 0)
    {
        CURL *curl;
        FILE *fptr;
        int result;
        char path[64];

        strcpy(path, cwd);
        strcat(path, "/");
        strcat(path, name);
        strcat(path, format);

        fptr = fopen(path, "wb");

        curl = curl_easy_init();

        curl_easy_setopt(curl, CURLOPT_URL, url);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, fptr);
        curl_easy_setopt(curl, CURLOPT_FAILONERROR, 1L);

        result = curl_easy_perform(curl);

        if (result == CURLE_OK)
            printf("\nDownload [%s] berhasil\n\n", path);
        else
            printf("\nGagal Download Gambar: %s\n\n", curl_easy_strerror(result));

        kill((int)getpid(), SIGKILL);
    }
}

static void collect_form_sprites(char *api_url, char *cwd)
{
    json_value *jsonForm;
    jsonForm = get_data(api_url, jsonForm);

    if (jsonForm != NULL)
    {
        int len = jsonForm->u.object.length;

        for (int x = 0; x < len; x++)
        {
            if (strcmp(jsonForm->u.object.values[x].name, "sprites") == 0)
            {
                int sprites_num = jsonForm->u.object.values[x].value->u.object.length;
                for (int y = 0; y < sprites_num; y++)
                {
                    switch (jsonForm->u.object.values[x].value->u.object.values[y].value->type)
                    {
                    case json_string:
                        download_image(jsonForm->u.object.values[x].value->u.object.values[y].value->u.string.ptr, cwd, jsonForm->u.object.values[x].value->u.object.values[y].name, ".png");
                        break;
                    default:
                        break;
                    }
                }

                break;
            }
        }
        json_value_free(jsonForm);
    }
}

static void process_value(json_value *value, char *cwd);

static void process_object(json_value *value, char *cwd)
{
    int length, x, is_dir, isFileExists = 0, fileNameExists = 0; 
    char temp_dir[512];

    char infofile_old[64] = "additional_information.txt"; // Nama default untuk file text
    char info_dir[512];
    char info_dir_new[512];
    FILE *fptr;

    if (value == NULL)
    {
        return;
    }

    length = value->u.object.length;

    for (x = 0; x < length; x++)
    {
        is_dir = 0;
        switch (value->u.object.values[x].value->type)
        {
        case json_object:
            is_dir = 1;
            break;
        case json_array:
            is_dir = 1;
            break;
        }

        if (is_dir == 1)
        {
            strcpy(temp_dir, cwd);
            strcat(temp_dir, "/");
            strcat(temp_dir, value->u.object.values[x].name);
            make_directory(temp_dir);
            printf("object[%d].name = %s\n", x, value->u.object.values[x].name);

            process_value(value->u.object.values[x].value, temp_dir);
        }
        else if (is_dir == 0)
        {
            if (isFileExists == 0)
            {
                strcpy(info_dir, cwd);
                strcat(info_dir, "/");
                strcat(info_dir, infofile_old);
                fptr = fopen(info_dir, "w");
                isFileExists = 1;
            }
            if (isFileExists == 1)
            {
                switch (value->u.object.values[x].value->type)
                {
                case json_integer:
                    fprintf(fptr, "%s: %ld\n", value->u.object.values[x].name, value->u.object.values[x].value->u.integer);
                    break;
                case json_double:
                    fprintf(fptr, "%s: %f\n", value->u.object.values[x].name, value->u.object.values[x].value->u.dbl);
                    break;
                case json_string:
                    fprintf(fptr, "%s: %s\n", value->u.object.values[x].name, value->u.object.values[x].value->u.string.ptr);

                    if (strcmp(value->u.object.values[x].name, "name") == 0)
                    {
                        strcpy(info_dir_new, cwd);
                        strcat(info_dir_new, "/");
                        strcat(info_dir_new, value->u.object.values[x].value->u.string.ptr);
                        fileNameExists = 1;
                    }
                    if (strstr(value->u.object.values[x].value->u.string.ptr, ".png") != NULL)
                    {
                        download_image(value->u.object.values[x].value->u.string.ptr, cwd, value->u.object.values[x].name, ".png");
                    }

                    if (strstr(value->u.object.values[x].value->u.string.ptr, ".svg") != NULL)
                    {
                        download_image(value->u.object.values[x].value->u.string.ptr, cwd, value->u.object.values[x].name, ".svg");
                    }

                    break;
                case json_boolean:
                    fprintf(fptr, "%s: %d\n", value->u.object.values[x].name, value->u.object.values[x].value->u.boolean);
                    break;
                }
            }
        }

        if (strstr(cwd, "forms/") != NULL)
        {
            if (strcmp(value->u.object.values[x].name, "url") == 0)
            {
                collect_form_sprites(value->u.object.values[x].value->u.string.ptr, cwd);
            }
        }
    }

    if (isFileExists == 1)
    {
        fclose(fptr);
        if (fileNameExists == 1)
        {
            strcat(info_dir_new, ".txt");
            rename(info_dir, info_dir_new);
        }
    }
}

static void process_array(json_value *value, char *cwd)
{
    int length, x, prop_num, prop_prop_num, folder_name_ext = 0;
    char temp_dir[512], str_index[5];
    char folder_name[64];

    if (value == NULL)
    {
        return;
    }

    length = value->u.array.length;

    for (x = 0; x < length; x++)
    {
        folder_name_ext = 0;
        prop_num = value->u.array.values[x]->u.object.length;
        for (int y = 0; y < prop_num; y++)
        {
            if (folder_name_ext == 1)
            {
                break;
            }
            if (strcmp(value->u.array.values[x]->u.object.values[y].name, "name") == 0)
            {
                strcpy(folder_name, value->u.array.values[x]->u.object.values[y].value->u.string.ptr);
                folder_name_ext = 1;                                                    
                break;
            }
            switch (value->u.array.values[x]->u.object.values[y].value->type)
            {
            case json_object:
                prop_prop_num = value->u.array.values[x]->u.object.values[y].value->u.object.length;
                for (int z = 0; z < prop_prop_num; y++)
                {
                    if (strcmp(value->u.array.values[x]->u.object.values[y].value->u.object.values[z].name, "name") == 0)
                    {
                        strcpy(folder_name, value->u.array.values[x]->u.object.values[y].value->u.object.values[z].value->u.string.ptr); // simpan isi "nama"
                        folder_name_ext = 1;
                        break;
                    }
                }
                break;

            default:
                break;
            }
        }

        strcpy(temp_dir, cwd);
        strcat(temp_dir, "/");
        if (folder_name_ext == 1)
        {
            strcat(temp_dir, folder_name);
        }
        else
        {
            sprintf(str_index, "%d", x);
            strcat(temp_dir, str_index);
        }
        make_directory(temp_dir);

        process_value(value->u.array.values[x], temp_dir);
    }
}

static void process_value(json_value *value, char *cwd)
{
    if (value == NULL)
    {
        return;
    }
    switch (value->type)
    {
    case json_object:
        process_object(value, cwd);
        break;
    case json_array:
        process_array(value, cwd);
        break;
    default:
        break;
    }
}

int main(int argc, char *argv[])
{
    char api_url[255] = "https://pokeapi.co/api/v2/pokemon/";
    strcat(api_url, argv[1]);
    sprintf(data_dir, "%s/%s", mount_dir, argv[1]);

    if (stat(data_dir, &st) == 0)
    {
        printf("PERINGATAN: Data pokemon [%s] sudah tersedia dalam [%s].\n", argv[1], data_dir);
        return 0;
    }

    json_value *pokemon;
    pokemon = get_data(api_url, pokemon);

    if (pokemon != NULL)
    {
        make_directory(data_dir);

        process_value(pokemon, data_dir);

        json_value_free(pokemon);
    }
    else
    {
        printf("GAGAL: Data pokemon [%s] tidak bisa ditemukan atau didapatkan dari [%s].\n", argv[2], api_url);
    }


    switch (expression)
    {
    case /* constant-expression */:
        /* code */
        break;
    
    default:
        break;
    }
    return 0;
}
