#include <stdio.h>
#include <stdlib.h>

int main()
{
    // FILE *file;
    // char string[20];

    // file = fopen("data/data1.txt", "a");

    // if (file == NULL)
    // {
    //     printf("Error");
    //     exit(1);
    // }

    // printf("Masukan Nilai String: ");
    // scanf("%[^\n]s", string);

    // fprintf(file, "%s \n", string);
    // fclose(file);

    /* =========================================== */

    // FILE *file;
    // char fileData[200];

    // file = fopen("Data/data1.txt", "r");

    // if (file == NULL)
    // {
    //     printf("Error");
    //     exit(1);
    // }

    // while(fgets(fileData, sizeof(fileData), file)) {
    //     printf(fileData);
    // }
    // fclose(file);

    // FILE *fileGanjil;
    // FILE *fileGenap;
    // int number;

    // fileGanjil = fopen("Data/ganjil.txt", "a");
    // fileGenap = fopen("Data/genap.txt", "a");

    // for(int i = 1; i <= 5; i++) {
    //     printf("Angka %d: ", i);
    //     scanf("%d", &number);
    //     if(number % 2 == 0) {
    //         fprintf(fileGenap, "%i \n", number);
    //     }
    //     else {
    //         fprintf(fileGanjil, "%i \n", number);
    //     }
    // }

    // fclose(fileGenap);
    // fclose(fileGanjil);

    FILE *file;
    FILE *readFile;
    char readFileData[50];
    char readData[4][50];

    file = fopen("Data/data_diri.txt", "w");
    readFile = fopen("Data/data_diri.txt", "r");

    printf("1. Masukan Nama Lengkap.\n");
    printf("2. Masukan NIM.\n");
    printf("3. Masukan Prodi.\n");
    printf("4. Masukan Nama Kampus.\n\n");

    for (int i = 0; i < 4; i++)
    {
        printf("Data ke-%d: ", i + 1);
        scanf("%s", &readData[i]);
        fprintf(file, "%s \n", readData[i]);
    }

    fclose(file);
    
    while(fgets(readFileData, sizeof(readFileData), readFile))
    {
        printf("%s", readFileData);
    }

    fclose(readFile);
    return 0;
}
