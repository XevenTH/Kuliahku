#include <stdio.h>

int main()
{
    int ary[] = {89, 100, 18, 1, 81, 2, 120, 98};
    int size = sizeof(ary) / sizeof(int);

    int min;

    for (int i = 0; i < size; i++)
    {
        min = i;
        for (int j = i + 1; j < size; j++)
        {
            if (ary[j] > ary[min])
            {
                min = j;
            }
        }
        int temp = ary[i];
        ary[i] = ary[min];
        ary[min] = temp;
    }

    for (int i = 0; i < size; i++)
    {
        printf("%d\n", ary[i]);
    }

    return 0;
}
