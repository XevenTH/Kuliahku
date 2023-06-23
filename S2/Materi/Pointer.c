#include <stdio.h>
#include <stdbool.h>

void func(int *x, int size)
{
    for (int i = 0; i < size - 1; i++)
    {
        printf("%d\n", *(x + i));
        printf("%d\n", (x + i));
    }
}

int main()
{
    int arr[11] = {1, 2, 12, 4, 5, 6, 7, 8, 9, 10};
    int size = sizeof(arr) / sizeof(int);
    func(arr, size);

    return 0;
}
