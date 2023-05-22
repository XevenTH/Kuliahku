#include <stdio.h>

void Rekursif(int startIndex, int lastIndex, int *ary)
{
    int aryDummy[10] = ary;
    int start = startIndex;
    int finish = lastIndex;
    int pivot = lastIndex;

    if (start <= finish)
    {
        while (start < finish)
        {
            while (aryDummy[start] <= aryDummy[pivot])
            {
                start++;
            }
            while (aryDummy[finish] > aryDummy[pivot])
            {
                finish--;
            }
            if (start < finish)
            {
                int temp = aryDummy[finish];
                aryDummy[finish] = aryDummy[start];
                aryDummy[start] = temp;
            }
        }
        int temp = aryDummy[start];
        aryDummy[start] = aryDummy[finish];
        aryDummy[finish] = temp;
    }

    Rekursif(startIndex, finish - 1, aryDummy);
    Rekursif(finish + 1, lastIndex, aryDummy);
}

int main()
{
    int values[11];

    printf("Enter 10 integers: ");

    for (int i = 0; i < 10; ++i)
    {
        scanf("%d", &values[i]);
    }

    Rekursif(0, 10, &values);

    for (int i = 0; i < 10; ++i)
    {
        printf("%d\n", values[i]);
    }
    return 0;
}
