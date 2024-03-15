#include "requests.h"
#include "json.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <dirent.h>
#include <stdbool.h>

void HandleFolderAndFile(char *mountPoint, char *folderName, char *fileName, char *text)
{
    if (access(mountPoint, F_OK) != -1)
    {
        char currentPath[50], path[80];

        getcwd(path, sizeof(path));

        // Menambahkan current Dir dengan MountPoint
        // sprintf(path, "%s/%s", currentPath, mountPoint);

        DIR *dir = opendir(path);
        if (dir)
        {
            struct dirent *entry;
            int found = false;

            while ((entry = readdir(dir)) != NULL)
            {
                if (entry->d_type == DT_DIR && strcmp(entry->d_name, folderName) == 0)
                {
                    found = true;
                    break;
                }
            }

            closedir(dir);

            if (found)
            {
                char tempOutput[256];
                snprintf(tempOutput, sizeof(tempOutput), "%s/%s/%s", path, folderName, fileName);

                FILE *outputFile = fopen(tempOutput, "a");

                if (outputFile == NULL)
                {
                    perror("freopen");
                    exit(EXIT_FAILURE);
                }

                fprintf(outputFile, "%s\n", text);

                fclose(outputFile);
            }
            else
            {
                char command[256];
                snprintf(command, sizeof(command), "mkdir -p %s/%s", path, folderName);

                int status = system(command);

                if (status == 0)
                {
                    char tempOutput[256];
                    snprintf(tempOutput, sizeof(tempOutput), "%s/%s/%s", path, folderName, fileName);

                    FILE *outputFile = fopen(tempOutput, "a");

                    if (outputFile == NULL)
                    {
                        perror("freopen");
                        exit(EXIT_FAILURE);
                    }

                    fprintf(outputFile, "%s\n", text);

                    fclose(outputFile);
                }
                else
                {
                    exit(EXIT_FAILURE);
                }
            }
        }
        else
        {
            perror("opendir");
        }
    }
    else
    {
        printf("No Access to Mount Point: %s\n", mountPoint);
    }
}

int main(int argc, char *argv[])
{
    req_t req;
    int ret = requests_init(&req);
    if (ret)
    {
        return 1;
    }

    char url[100];
    sprintf(url, "https://pokeapi.co/api/v2/pokemon/%s", argv[1]);
    requests_get(&req, url);

    char *stringifyJson = req.text;
    json_value *json = json_parse(stringifyJson, strlen(stringifyJson));

    printf("\nRequest URL: %s\n", req.url);
    printf("Response Code: %lu\n", req.code);
    printf("Pokemon : %s\n", json->u.object.values[2].value->u.array.values[0]->u.object.values[0].value->u.string.ptr);

    // Get Abilities
    for (int i = 0; i < json->u.object.values[0].value->u.array.length; i++)
    {
        HandleFolderAndFile(argv[2], json->u.object.values[0].name, json->u.object.values[0].value->u.array.values[i]->u.object.values[0].value->u.object.values[0].value->u.string.ptr, json->u.object.values[0].value->u.array.values[i]->u.object.values[0].value->u.object.values[1].value->u.string.ptr);
    }

    printf("\n");
    printf("Learned Moves: \n");

    for (int i = 0; i < json->u.object.values[9].value->u.array.length; i++)
    {
        printf("Move %d : %s\n", i + 1, json->u.object.values[9].value->u.array.values[i]->u.object.values[0].value->u.object.values[0].value->u.string.ptr);
    }

    requests_close(&req); /* clean up */
    return 0;
}