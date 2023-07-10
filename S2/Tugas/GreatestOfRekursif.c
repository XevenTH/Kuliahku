#include <stdio.h>

void GreatestOfCheck(int *ary, int len, int *max)
{
    if (len >= 0)
    {
        if (ary[len] > *max) *max = ary[len];
        
        GreatestOfCheck(ary, len - 1, max);
    }
}

int main()
{
    int len = 0;
    printf("Masukan Besar Array: ");
    scanf("%d", &len);

    int IntAry[len];

    for (int i = 0; i < len; i++)
    {
        printf("Masukan Angka ke-%d: ", i + 1);
        scanf("%d", &IntAry[i]);
    }

    int hasil = 0;
    GreatestOfCheck(IntAry, len - 1, &hasil);

    printf("hasil: %d", hasil);

    return 0;
}
