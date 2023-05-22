#include <stdio.h>
#include <stdbool.h>
#define JUMLAHPOLI 4

struct Poli
{
    int id;
    char namaPoli[50];
    char namaDokter[100];
    int harga;
};

struct Pasien
{
    char nama[100];
    int umur;
    bool bpjs;
    struct Poli poli;
};

struct Pasien pasien[10];
struct Poli poli[JUMLAHPOLI] =
    {
        {1, "Poli THT", "Dokter Jordan Sp.T", 200000},
        {2, "Poli Gigi", "Dokter Angga Sp.G", 1000000},
        {3, "Poli Anak", "Dokter Handy Sp.A", 400000},
        {4, "Poli Hewan", "Dokter Syarif Sp.F", 5000000},
};

// Prosedur Untuk Meminta Input Data Dari user
void InputDataPasien(int jumlahPasien, char pilihanBpjs)
{
    for (int i = 0; i < jumlahPasien; i++)
    {
        printf("Masukan Nama Pasien Ke-%d : ", i + 1);
        scanf("%s", &pasien[i].nama);

        printf("Masukan Umur Pasien Ke-%d (Mohon Masukan Angka) : ", i + 1);
        scanf("%d", &pasien[i].umur);

        printf("Apakah Anda Memakai Bpjs (y/n) : ");
        scanf(" %c", &pilihanBpjs);

        if (pilihanBpjs == 'y')
        {
            pasien[i].bpjs = true;
        }
        else
        {
            pasien[i].bpjs = false;
        }

        printf("\n");
    }
}

// Prosedur Untukk Menentukan Pilihan Poli Pasien
void SetPoliPasien(int jumlahPasien, int pilihanPoli)
{
    for (int i = 0; i < jumlahPasien; i++)
    {
        // Memilih Poli
        printf("Masukan Nomor Poli yang Diinginkan Untuk Pasien \"%s\" : ", pasien[i].nama);
        scanf("%d", &pilihanPoli);

        // Sequential Search
        for (int j = 0; j < JUMLAHPOLI; j++)
        {
            if (pilihanPoli == poli[j].id)
            {
                // Jika index j itu poli.id sama dengan pilihanPoli dari input, maka set variabel poli pasien sama dengan poli di array index j.
                pasien[i].poli = poli[j];
                break;
            }
        }
    }
}

// Prosedur Untuk Check Apakah Pasien Menggunakan Bpjs
void CheckBpjs(int jumlahPasien)
{
    for (int i = 0; i < jumlahPasien; i++)
    {
        if (pasien[i].bpjs)
        {
            int jumlahDiskon = pasien[i].poli.harga * 0.9;
            pasien[i].poli.harga -= jumlahDiskon;
        }
    }
}

// Prosedur Untuk Sorting Pasien Menurut Poli Yang Dipilih
void SortingPasien(int jumlahPasien)
{
    // Sorting Pasien Dilakukan secara Ascending Menurut harga Poli yang Dipilih Pasien
    for (int i = 0; i < jumlahPasien; i++)
    {
        int min = i;

        for (int j = i + 1; j < jumlahPasien; j++)
        {
            if (pasien[j].poli.harga < pasien[min].poli.harga)
            {
                min = j;
            }
        }

        struct Pasien temp = pasien[i];
        pasien[i] = pasien[min];
        pasien[min] = temp;
    }
}

// Prosedur Untuk Menghitung Total Harga
void HitungTotalHarga(int jumlahPasien)
{
    int totalHarga = 0;

    for (int i = 0; i < jumlahPasien; i++)
    {
        totalHarga += pasien[i].poli.harga;
    }

    printf("\n\n\tTotal harga Dari %d Pasien Diatas Sebesar Rp. %d\n", jumlahPasien, totalHarga);
}

int main()
{
    int jumlahPasien = 0;
    char pilihanBpjs;
    int pilihanPoli = 0;
    int pilihanPasien = 0;

    printf("=======================================================================\n");
    printf("\t\t\t RUMAH SAKIT SUGIH WARAS\n\n");
    printf("\t\t\tAnda Sugih, Dijamin Waras");
    printf("\n=======================================================================\n\n");

    printf("WAHAI NETIZEN BUDIMAN, MOHON IKUTI PROSEDUR DENGAN TEPAT. JIKA TIDAK MAKA PROGRAM AKAN ERROR\n\n");

    printf("Masukan Jumlah Pasien Yang Ingin Dirawat\n\n");
    printf("Masukan Jumlah Pasien: ");
    scanf("%d", &jumlahPasien);
    printf("\n");

    // Proses Input Data Pasien
    // Data akan disimpan dalam bentuk Struct(Objek) dan akan disimpan kedalam global variabel array
    InputDataPasien(jumlahPasien, pilihanBpjs);

    // Menampilkan Macam-Macam Poli Yang Ada
    // loop global array(poli) dan tampilkan namanya
    printf("\nMohon Untuk Memilih Poli yang Diinginkan....\n\n");
    printf("Macam - Macam Poli: \n");
    for (int i = 0; i < JUMLAHPOLI; i++)
    {
        printf("%d. %s\n", i + 1, poli[i].namaPoli);
    }

    // Menampilkan Data Pasien Yang sudah Di Input
    // loop global array(pasien) dan tampilkan nama serta umurnya
    printf("\nDaftar Pasien Yang Ada: \n");
    for (int i = 0; i < jumlahPasien; i++)
    {
        printf("%d. Nama\t: %s\n   Umur\t: %d\n\n", i + 1, pasien[i].nama, pasien[i].umur);
    }

    printf("\nPilih Nomor Poli Untuk Pasien Berikut....\n\n");

    // Atur Poli dari semua pasien yang ada dengan cara melakukan loop di global array(pasien), lalu akses struct(pasien) dan set struct(poli)
    SetPoliPasien(jumlahPasien, pilihanPoli);

    // Check Bpjs
    CheckBpjs(jumlahPasien);

    // Sebelum Menghitung Harga Total, Sorting Global Array(pasien) Menggunakan Selection Sort
    // Sorting Dilakukan Hanya Jika Jumlah Pasien Lebih Dari Satu
    if (jumlahPasien > 1)
    {
        SortingPasien(jumlahPasien);
    }

    // Print Bond
    for (int i = 0; i < jumlahPasien; i++)
    {
        printf("\nPasien Ke-%d ", i + 1);
    
        if (pasien[i].bpjs)
        {
            printf("(Menggunakan Bpjs)");
        }

        // Check Apakah Pasien Menggunakan BPJS
        // Jika iya, maka harga yang harus dibayarkan oleh pasien akan diber diskon sebesar 90%

        printf("\nNama : %s,\nUmur : %d,\nPilihan Poli : %s\nDokter Pemeriksa : %s\nDengan Harga : Rp. %d\n", pasien[i].nama, pasien[i].umur, pasien[i].poli.namaPoli, pasien[i].poli.namaDokter, pasien[i].poli.harga);
    }

    // TUGAS KUUUUUUU
    char keputusan;

    printf("\nApakah Anda Yakin Dengan Data Ini (y/n) : ");
    scanf(" %c", &keputusan);
    while (keputusan == 'n')
    {
        int idPasien;

        printf("Pasien Mana Yang Ingin Dihapus (Masukan Angka) : ");
        scanf("%d", &idPasien);

        for (int i = idPasien - 1; i < jumlahPasien - 1; i++)
        {
            pasien[i] = pasien[i + 1];
        }

        jumlahPasien--;

        for (int i = 0; i < jumlahPasien; i++)
        {
            printf("\nPasien Ke-%d ", i + 1);
            printf("\nNama : %s,\nUmur : %d,\nPilihan Poli : %s\nDokter Pemeriksa : %s\nDengan Harga : Rp. %d\n", pasien[i].nama, pasien[i].umur, pasien[i].poli.namaPoli, pasien[i].poli.namaDokter, pasien[i].poli.harga);
        }

        printf("\nApakah Anda Yakin Dengan Data Ini (y/n) : ");
        scanf(" %c", &keputusan);
        // END OF TUGAS KUUUUUUU
    }

    // Total harga dihitung berdasarkan semua pasien yang ada di global array(pasien) menurut harga poli yang dipilih masing-masing pasien.
    HitungTotalHarga(jumlahPasien);

    return 0;
}