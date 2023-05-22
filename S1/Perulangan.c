#include <stdio.h>
#include <stdbool.h>

float sum(float a, float t)
{
    float hasil = (a * t) / 2;
    return hasil;
}

int main()
{
    float a, t;

    printf("Masukan Nilai Alas: ");
    scanf("%f", &a);
    printf("Masukan Nilai Tinggi: ");
    scanf("%f\n", &t);

    float hasil = sum(a,t);
    printf("%.2f", hasil);

    return 0;
}