#include <stdio.h>

int Kelipatan(int a, int b, int c)
{
    int hasil;
    int kelipatan = 1;
    int jumlah = 0;

    do
    {
        hasil = a * kelipatan;

        if(hasil % c == 0)
        {
            if(hasil % b != 0)
            {
                jumlah++;
                printf("%d\n", hasil);
            }
        }

        kelipatan++;

    } while (hasil <= 100);

    printf("%d\n ", jumlah);
}

void Hasil()
{
    Kelipatan(4, 5, 3);
}

int main()
{
    Hasil();

    return 0;
}