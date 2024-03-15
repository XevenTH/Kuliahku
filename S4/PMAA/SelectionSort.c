#include <stdio.h>
#include <string.h>

#define MAKSIMAL_KARAKTER 101
#define JUMLAH_KATA 100

void selection_sort(char arr[][MAKSIMAL_KARAKTER], int n)
{
    int i, j, min;
    for (i = 0; i < n - 1; i++)
    {
        min = i;
        for (j = i + 1; j < n; j++)
        {
            if (strcmp(arr[j], arr[min]) < 0)
            {
                min = j;
            }
        }

        char temp[MAKSIMAL_KARAKTER];
        strcpy(temp, arr[min]);
        strcpy(arr[min], arr[i]);
        strcpy(arr[i], temp);
    }
}

int main()
{
    char arr[JUMLAH_KATA][MAKSIMAL_KARAKTER];

    printf("Masukan %d kata:\n", JUMLAH_KATA);
    for (int i = 0; i < JUMLAH_KATA; i++)
    {
        printf("Kata ke-%d: ", i + 1);
        scanf("%s", arr[i]);
    }

    selection_sort(arr, JUMLAH_KATA);

    
    printf("\n");
    printf("array yang sudah diurutkan :\n");
    for (int i = 0; i < JUMLAH_KATA; i++)
    {
        printf("%s\n", arr[i]);
    }

    return 0;
}