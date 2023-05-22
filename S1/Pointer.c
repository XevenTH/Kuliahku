#include <stdio.h>

void Swap(char a[], char b[], int i)
{
    char c[i];

    for (int j = i; j < 10; j++)
    {
        char *ptr1 = &a[j];
        char *ptr2 = &b[j];
        for (int k = 0; k < j; k++)
        {
            c[k] = *ptr1++;
            b[j] = *ptr2++;
        }

        printf("%s\n", c);
    }

    // printf("%s", b);
}

int main()
{
    // char str1[10] = "1234567890";
    // char str2[10] = "asdfhgjktu";

    // Swap(str1, str2, 5);

    /* ================================ */

    // int y = 10;
    // int* ptr = &y;

    // printf("\nNilai y disimpan di Memori: %p\nbernilai: %d", ptr, *ptr);
    // printf("\nPointer Disimpan Di Memori: %p\n", &ptr);

    /* ================================ */

    // int x = 10;
    // int* ptr = &x;
    // int** y = &ptr;

    // **y = 15;

    // printf("%p\n", ptr);
    // printf("%d\n", x);
    // printf("%d\n", **y);

    /* ================================ */

    int array[5] = {1, 2, 3, 4, 5};
    int* p;
    p = &array[0];

    for (int i = 0; i < 5; i++)
    {
        printf("Isi dari *p[%d] = %d\n", i, &p[i]);
    }

    /* ================================ */

    return 0;
}
