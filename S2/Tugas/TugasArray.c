#include <stdio.h>

void NomorSatu();
void NomorDua();
void NomorTiga();
void NomorEmpat();
void NomorLima();

int main()
{
    printf("Nomor 1 : \n");
    NomorSatu();

    printf("\nNomor 2 : ");
    NomorDua();

    printf("\nNomor 3 : \n");
    NomorTiga();

    printf("\nNomor 4 : ");
    NomorEmpat();

    printf("\nNomor 5 : ");
    NomorLima();

    return 0;
}

void NomorSatu()
{
    // Lakukan inisialisasi untuk membaut array tanpa data apapun
    int arr[3][2];

    // Lakukan looping pada array yang sudah dibuat, array dibuat melebihi satu agar indeks terakhir bisa digunakan untuk sampah array
    for (int i = 0; i <= sizeof(arr) / sizeof(arr[0]) - 1; i++)
    {
        for (int j = 0; j <= sizeof(arr[0]) / sizeof(int) - 1; j++)
        {
            int x;
            printf("Masukan Nilai Dari Matrix[%d][%d] : ", i, j);
            scanf("%d", &arr[i][j]);
        }
    }

    // print hasil array yang sudah diisi saat program berjalan tadi
    for (int i = 0; i <= sizeof(arr) / sizeof(arr[0]) - 1; i++)
    {
        for (int j = 0; j <= sizeof(arr[0]) / sizeof(int) - 1; j++)
        {
            printf("Nilai Dari Matrix[%d][%d] : %d\n", i, j, arr[i][j]);
        }
    }
}

void NomorDua()
{
    // buat array dan isi array dengan angka yang berbeda
    int x[5] = {15, 21, 4, 6, 2};

    // Melakukan print kepada semua elemnt yang ada di dalam array sebelum melakukan sorting
    for (size_t i = 0; i < sizeof(x) / sizeof(int); i++)
    {
        printf("Nilai Awal Dari Matrix[%d] : %d", i, x[i]);
    }

    // dengan menggunakan algoritma selection sort, kita akan melakukan sorting kepada array yang sudah dibuat.
    for (int i = 0; i < sizeof(x) / sizeof(int) - 1; i++)
    {
        for (int j = i + 1; j < sizeof(x) / sizeof(int); j++)
        {
            if (x[j] < x[i])
            {
                int temp = x[i];
                x[i] = x[j];
                x[j] = temp;
            }
        }
    }

    // Print semua element yang ada di dalam array yang sudah di sorint gdengan menggunakan selection sort.
    printf("\nHasil Sort\n");
    for (int i = 0; i <= sizeof(x) / sizeof(x[0]) - 1; i++)
    {
        printf("Nilai Dari Matrix[%d] : %d\n", i, x[i]);
    }
}

void NomorTiga()
{
    // Buat array 2 dimensi dengan nilai yang diinginkan
    int arr[3][2] = {{3, 6}, {9, 8}, {15, 10}};

    // variabel "cari" akan digunakan untuk menyimpan input user yang berisi angkan yang ingin dicari
    int cari;

    printf("Masukan Nilai Yang Ingin Dicari : ");
    scanf("%d", &cari);

    // Lakukan perulangan kepada array yang sudah dibuat, karena kita menggunakan array 2 dimensi kita harus melakukan nested loop untuk mencari nilai didalam array yang sudah ada.
    for (int i = 0; i <= sizeof(arr) / sizeof(arr[0]) - 1; i++)
    {
        for (int j = 0; j <= sizeof(arr[0]) / sizeof(int) - 1; j++)
        {
            if (arr[i][j] == cari)
            {
                printf("\nElemen %d Berada Di Indeks[%d][%d]\n", cari, i, j);
                return;
            }
        }
    }

    // Jika tidak ketemu maka program akan mengeluarkan output seperti yang ada di bawah ini
    printf("Tidak ada Element Tersebut Di dalam Array\n");
}

void NomorEmpat()
{
    // inisialisasi array
    int arr[71];
    float jumlah;

    // isi array dengan angka +1 dari angka sebelumnya sampai 70
    for (int i = 0; i <= 70; i++)
    {
        arr[i] = i + 1;
    }

    // tambahkan semua elemen dengan variabel "jumlah" sampai indeks terakhir
    for (int i = 0; i < sizeof(arr) / sizeof(int) - 1; i++)
    {
        jumlah += arr[i];
    }

    // Hitung rata - rata dengan rumus mencari rata - rata biasa
    float rata = jumlah / (sizeof(arr) / sizeof(int) - 1);

    // print output dari rata - rata
    printf("\nHasil Rata - Rata : %0.2f\n", rata);
}

void NomorLima()
{
    // buar array dengan daftar nomor lantai yang ada (1 - 10)
    int lantai[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int size = sizeof(lantai) / sizeof(int);

    // Buat variabel untuk menyimpan input dari user di "cari", dengan variabel "indeks" untuk menyimpan di indeks mana nilai yang user cari tersimpan
    int cari, indeks;

    printf("\nMau Menuju Ke Lantai Mana : ");
    scanf("%d", &cari);

    // cari lantai yang dicari user dengan menggunakan sequential search
    for (int i = 0; i < size; i++)
    {
        if (lantai[i] == cari)
        {
            indeks = i;
            break;
        }
    }

    // melakukan loop yang dimulai dari indeks dengan value yang dicari user, lalu lakukan loop 2 indeks ke belakang. Dan mengecek apakah loop lebih besar dari besar array yang ada
    for (int j = indeks - 2; j < indeks; j++)
    {
        if (lantai[j] != cari) printf("%d\n", lantai[j]);
    }

    // melakukan loop yang dimulai dari indeks dengan value yang dicari user, lalu lakukan loop 2 indeks ke depan. Dan mengecek apakah loop lebih besar dari besar array yang ada
    for (int k = indeks; k <= indeks + 2 && k < size; k++)
    {
        printf("%d\n", lantai[k]);
    }
}