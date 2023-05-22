#include <stdio.h>

typedef struct barang{
    char nama[15];
    int modal;
    int jual;
} Barang;

int main()
{
    Barang newBarang;

    printf("Masukan Nama : ");
    scanf("%s", &newBarang.nama);
    printf("Masukan Modal : ");
    scanf("%d", &newBarang.modal);
    printf("Masukan Jual : ");
    scanf("%d", &newBarang.jual);

    printf("Margin (%s) adalah : %d", newBarang.nama, newBarang.jual - newBarang.modal);

    return 0;
}
