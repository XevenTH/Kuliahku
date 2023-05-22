#include <stdio.h>


int main()
{

    char nilai[3][4] = { "yes", "ok", "Nice" };

    // printf("%s", nilai[2]);

    // for(int i = 0; i < 2; i++) 
    // {
    //     for(int j = 0; j < 2; j++) 
    //     {
    //         int var1;
    //         int var2;

    //         printf("masukan Angka Pertama: ");
    //         scanf("%d", &var1);
    //         printf("masukan Angka Kedua: ");
    //         scanf("%d", &var2);

    //         int test[2] = {var1, var2};
    //         nilai[i][j] = test;
    //     }
    // }

    for(int i = 0; i < 3; i++) 
    {
        // printf("%s\n", nilai[i]);
        int size;

        for(int j = 0; j < 4; j++) 
        {
            size = sizeof(nilai[i][j]) / sizeof(char);
            for(int z = 0; z < size; z++)
            {
                printf("\n%c", nilai[i][j]);
            }
        }
    }

    // printf("\nNew Value:\n");

    // for(int i = 0; i < 5; i++) 
    // {
    //   printf("Nilai Index ke %d adalah %d\n", i, nilai[i]);
    // }

    return 0;
}