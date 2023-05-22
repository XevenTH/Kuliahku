#include <stdio.h>

struct Poli
{
    int id;
    char namaPoli[50];
    char namaDokter[100];
    int harga;
};

int main(int argc, char const *argv[])
{
    struct Poli poli[4] =
        {
            {1, "Poli THT", "Dokter Jordan Sp.T", 200000},
            {2, "Poli Gigi", "Dokter Angga Sp.G", 1000000},
            {3, "Poli Anak", "Dokter Handy Sp.A", 400000},
            {4, "Poli Hewan", "Dokter Syarif Sp.F", 5000000},
        };

    for (int i = 0; i < 4; i++)
    {
        printf("Harga : %d\n", poli[i].harga);
    }
    printf("\n\n");

    // SortingPasien(jumlahPasien);
    // Sorting Pasien Dilakukan secara Ascending Menurut harga Poli yang Dipilih Pasien
    for (int i = 0; i < 4; i++)
    {
        int min = i;

        for (int j = i + 1; j < 4; j++)
        {
            if (poli[j].harga < poli[min].harga)
            {
                min = j;
            }
        }

        struct Poli temp = poli[i];
        poli[i] = poli[min];
        poli[min] = temp;
    }

    for (int i = 0; i < 4; i++)
    {
        printf("Harga : %d\n", poli[i].harga);
    }
    printf("\n\n");

    return 0;
}
