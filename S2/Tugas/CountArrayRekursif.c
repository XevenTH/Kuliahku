#include <stdio.h>
#include <string.h>

void CountArray(char *ary, int len, int *hasil)
{
    // lakukan rekursif sampai panjang dari array memenuhi
    if (len >= 0)
    {
        CountArray(ary, len - 1, hasil);
        // Tambah hasilnya saat di dalam proses rekusif
        *hasil = *hasil + 1;
    }
}

int main()
{
    // Menyiapkan array untuk menyimpan angka
    char Ary[20];
    printf("Masukan Angka (Tanpa Spasi!!!): ");
    // meminta kata dari user
    scanf("%s", &Ary);

    // menyiapkan beberapa variabel untuk menghitung banyak angka di dalam array
    int len = strlen(Ary), hasil = 0;
    CountArray(Ary, len - 1, &hasil);
    printf("Hasil: %d", hasil);

    return 0;
}
