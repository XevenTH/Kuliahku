#include <stdio.h>

struct segitiga
{
    float alas;
    float tinggi;
    float luas;
};

int main()
{
    int length;
    printf("Berapa segitiga : ");
    scanf("%d", &length);
    struct segitiga segitigaAry[length];

    for (int i = 0; i < length; i++)
    {
        struct segitiga newSegitiga;
        printf("\nSegitiga %d\n", i + 1);
        printf("Masukan Alas : ");
        scanf("%f", &newSegitiga.alas);
        printf("Masukan Tinggi : ");
        scanf("%f", &newSegitiga.tinggi);
        segitigaAry[i] = newSegitiga;
    }

    for (int i = 0; i < length; i++)
    {
        segitigaAry[i].luas = (segitigaAry[i].alas * segitigaAry[i].tinggi) / 2;
    }

    for (int i = 0; i < length; i++)
    {
        struct segitiga temp;
        for (int j = 0; j < length - 1 - i; j++)
        {
            if (segitigaAry[j].luas > segitigaAry[j + 1].luas)
            {
                temp = segitigaAry[j];
                segitigaAry[j] = segitigaAry[j+1];
                segitigaAry[j+1] = temp;
            }
        }
    }
    

    for (int i = 0; i < length; i++)
    {
        printf("(%.1f x %.1f) / 2 = %.1f\n", segitigaAry[i].alas, segitigaAry[i].tinggi, segitigaAry[i].luas);
    }

    return 0;
}