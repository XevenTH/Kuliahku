#include <stdio.h>
#include <stdbool.h>
#define size 6

void Sorting(int *ary, int opt)
{
    // If 2 Ascending, 3 Descending
    for (int i = 0; i < size; i++)
    {
        for (int k = 0; k < i; k++)
        {
            if (opt == 2)
            {
                if (ary[i] < ary[k])
                {
                    int tmp = ary[k];
                    ary[k] = ary[i];
                    ary[i] = tmp;
                }
            }
            else
            {
                if (ary[i] > ary[k])
                {
                    int tmp = ary[k];
                    ary[k] = ary[i];
                    ary[i] = tmp;
                }
            }
        }
    }
}

void ControlFlow(int *ary, int *tmp, int *opt, int *input)
{
    printf("Tahap Menjalankan Program:\n");
    printf("\n1.Masukan Nilai (6 Angka)\n\n");

    for (int i = 0; i < size; i++)
    {
        printf("Masukan Angka ke-%d: ", i);
        scanf("%d", tmp);
        ary[i] = *tmp;
    }

    printf("\n2.Ascending\n");
    printf("3.Descending\n");
    scanf("%d", opt);

    printf("4.Serching\n");
    scanf("%d", input);
}

int Searching(int input, int *ary)
{
    int left = 0;
    int right = size - 1;
    while (left <= right)
    {
        int mid = (left + right) / 2;
        if (input == ary[mid])
        {
            return mid;
        }
        if (input > ary[mid])
        {

            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        }
    }

    return -1;
}

int main()
{
    int ary[size] = {};
    int tmp = 0;
    int opt = 0;
    int input;

    ControlFlow(ary, &tmp, &opt, &input);
    Sorting(ary, opt);

    int output = Searching(input, ary);
    if (output == -1)
    {
        printf("Angka Tidak Ditemukan\n");
    }
    else {
        printf("%d\n", output);
    }

    for (int i = 0; i < size; i++)
    {
        printf("Angka di Index-%d ke-%d: %d\n", output, i, ary[i]);
    }

    return 0;
}
