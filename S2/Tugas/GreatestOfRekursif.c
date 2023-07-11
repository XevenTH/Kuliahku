#include <stdio.h>

void GreatestOfCheck(int *ary, int len, int *max)
{
    // Melakukan rekursif sampai batas panjang array
    if (len >= 0)
    {
        // Jika angka yang dirunjuk indeks lebih besar dari variabel max, maka ganti nilai max nya
        if (ary[len] > *max) *max = ary[len];
        
        // Lakukan rekusif
        GreatestOfCheck(ary, len - 1, max);
    }
}

int main()
{
    // Karena besar dari array nantinya akan dari user, maka kita perlu beberapa persiapan untuk melakukannya contohnya menyiapkan variabel untuk menyimpan valuenya
    int len = 0;
    printf("Masukan Besar Array: ");
    scanf("%d", &len);

    // Melakukan deklarasi Array dengan besar array sesuai denga yang di inputkan user sebelumnya
    int IntAry[len];

    // Meminta angka ke user untuk dimasukan ke dalam array
    for (int i = 0; i < len; i++)
    {
        printf("Masukan Angka ke-%d: ", i + 1);
        scanf("%d", &IntAry[i]);
    }

    // deklarasi variabel untuk menyimpan hasil terbesar nilai dari sebuah array
    int hasil = 0;
    GreatestOfCheck(IntAry, len - 1, &hasil);

    printf("hasil: %d", hasil);

    return 0;
}
