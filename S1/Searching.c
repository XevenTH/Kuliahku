#include <stdio.h>

int main()
{
    int ary[3][3] = {{1, 2, 3}, {4, 2, 6}, {7, 8, 9}};
    int search;
    int data = 0;

    printf("Masukan angka yang inging dicari: ");
    scanf("%d", &search);

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (ary[i][j] == search)
            {
                printf("Angka %d berada di Index[%d][%d]\n", search, i, j);
                data = 1;
            }
        }
    }

    if (data == 0)
    {
        printf("Angka %d tidak ditemukan", search);
    }

    return 0;
}
