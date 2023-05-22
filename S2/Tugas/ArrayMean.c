#include <stdio.h>

float ArrayMean(float *arr, int size)
{
    float value;

    for (int i = 0; i < size; i++)
    {
        value += arr[i];
    }

    return value/size;
}

int main()
{
    int size;

    printf("Berapa Angka Yang Ingin Dimasukan: ");
    scanf("%d", &size);
    float arr[size];
    printf("Masukan Angka: ");

    for (int i = 0; i < size; i++)
    {
        scanf("%f", &arr[i]);
    }
    
    printf("%.2f", ArrayMean(arr, size));

    return 0;
}
