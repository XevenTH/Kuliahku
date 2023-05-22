#include <stdio.h>

void Sort1(int arr[], int size)
{
    for (int i = 1; i < size; i++)
    {
        int temp = arr[i];
        int check = i - 1;

        while (arr[check] > temp && check > 0)
        {
            arr[check + 1] = arr[check];
            check--;
        }

        arr[check + 1] = temp;
    }

    for (int k = 0; k < size; k++)
    {
        if (arr[k] > 6)
        {
            int temp = arr[k];
            int check = k - 1;

            while (arr[check] < temp && check > 9)
            {
                arr[check + 1] = arr[check];
                check--;
            }

            arr[check + 1] = temp;
        }
    }
}

int main()
{
    int arr[] = {1, 9, 4, 5, 6, 7, 2, 3, 8, 1, 9, 4, 5, 6, 7, 2, 3, 8};
    int size = sizeof(arr) / sizeof(int);

    Sort1(arr, size);

    for (int i = 0; i < size; i++)
    {
        printf("%d, ", arr[i]);
    }

    return 0;
}
