#include <stdio.h>

float Hitung(int a)
{
    float hasil;
    float penjumlahan;

    for (int i = a; i >= 0; i--)
    {
        if(i == 0) 
        {
            hasil = 1.0 / 1.0;
            penjumlahan += hasil;
            break;
        }

        hasil = (1.0 / i);
        penjumlahan += hasil;
    }

    return penjumlahan;
}

void Print()
{
    printf("%.6f", Hitung(1));
}

int main()
{
    Print();

    return 0;
}
