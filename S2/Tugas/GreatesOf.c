#include <stdio.h>

int greatestOf(int a, int b, int c, int d)
{
    int arr[4] = {a, b, c, d};
    int maxIndex = 0;

    for (int i = 0; i < 4 - 1; i++)
    {
        for (int j = i + 1; j < 4; j++)
        {
            if (arr[j] > arr[maxIndex])
            {
                maxIndex = j;
            }
        }
    }

    return arr[maxIndex];
}

int main()
{
    int a, b, c, d;

    printf("Masukan Nilai: ");
    scanf("%d %d %d %d", &a, &b, &c, &d);

    printf("%d", greatestOf(a, b, c, d));

    return 0;
}
