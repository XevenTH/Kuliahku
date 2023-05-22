#include <stdio.h>

void Calculate(char *ary, int length)
{
    int datas = 0;

    for (char a = 'a'; a <= 'z'; a++)
    {
        for (int i = 0; i < length; i++)
        {
            if (ary[i] == a)
            {
                datas++;
            }
        }
        if (datas != 0)
        {
            printf("Huruf %c ada: %d \n", a, datas);
        }
        datas = 0;
    }
}

int main()
{
    char ary[] = "apa kabar semuanya, apakah semuanya baik baik saja";
    int arrLength = sizeof(ary);

    Calculate(ary, arrLength);

    return 0;
}
