#include <stdio.h>

int ReskursifMultiply(int x, int y)
{
    int hasil = 0;
    if (hasil < 0)
    {
        hasil++;
        return ReskursifMultiply(x, y);
    }
    else
    {
        return x * y * 1;
    }
}

void RekursifUrut(int x)
{
    if (x > 0)
    {
        RekursifUrut(x - 1);
        printf("%d ", x);
    }
    else
        return;
}

int main()
{
    int result = ReskursifMultiply(5, 0);
    printf("Hasil : %d\n", result);

    RekursifUrut(29);

    return 0;
}
