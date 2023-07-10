#include <stdio.h>

int RekursifInt(int n, int pangkat)
{
    if (pangkat > 0) return n * RekursifInt(n, pangkat - 1);

    return 1;
}

int main()
{
    int angka, pangkat;

    printf("Masukan Angka: ");
    scanf("%d", &angka);
    printf("Masukan Pangkat: ");
    scanf("%d", &pangkat);

    int result = RekursifInt(angka, pangkat);

    printf("Hasil: %d", result);

    return 0;
}
