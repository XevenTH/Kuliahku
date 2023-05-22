#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Deklarasi secara global atau menyeluruh
char model[100][20];
char merk[100][20];
int harga[100];
int jumlah[100];
int total = 0;

// fungsi untuk menu
void menu()
{
    printf("1. Masukkan Informasi HP yang baru\n");
    printf("2. Perbarui Informasi Tentang HP\n");
    printf("3.Cari HP berdasarkan Model\n");
    printf("4. urutkan Hp berdasarkan Harga\n");
    printf("5. Keluar\n");
}

// opsi 1
void insert()
{
    printf("Masukkan Model Hp: ");
    fflush(stdin);
    gets(model[total]);
    printf("Masukkan Merk HP");
    fflush(stdin);
    gets(merk[total]);
    printf("Masukkan Harga HP: ");
    scanf("%d", &harga[total]);
    printf("Masukkan Jumlah HP: ");
    scanf("%d", &jumlah[total]);
    printf("\n");
}

// opsi 2
void update()
{
    char searchMode[20];
    int slebew;
    printf("Masukkan Model HP yang baru: ");
    scanf("%s", searchMode);
    for (int i = 0; i < total; i++)
    {
        if (strcmp(model[i], searchMode) == 0)
        {
            slebew = 1;
            break;
        }
    }
    
    printf("Masukkab Harga HP yang Baru: ");
    scanf("%d", &harga[slebew]);
}

// opsi 3
void search()
{
    char searchModel[20];
    int slebew;
    printf("Masukkan Modek HP untuk dicari: ");
    fflush(stdin);
    gets(searchModel);
    for (int i = 0; i < total; i++)
    {
        if (strcmp(model[i], searchModel) == 0)
        { // strcmp adalah fungsi untuk membandingkan string
            slebew = i;
            break;
        }
    }
    printf("Model: %s\n", model[slebew]);
    printf("merk: %s\n", merk[slebew]);
    printf("harga: %d\n", harga[slebew]);
    printf("jumlah: %d\n", jumlah[slebew]);
    printf("\n");
}

// opsi 4
void sort()
{
    for (int i = 0; i < total - 1; i++)
    {
        for (int j = 0; j < total - i - 1; j++)
        {
            if (harga[j] > harga[j + 1])
            {
                char tempModel[20];
                char tempmerek[20];
                int tempharga;
                int tempjumlah;
                strcpy(tempModel, model[j]); // strcpy adalah fungsi untuk mengcopy string
                strcpy(tempmerek, merk[j]);
                tempharga = harga[j];
                tempjumlah = jumlah[j];
                strcpy(model[j], model[j + 1]);
                strcpy(merk[j], merk[j + 1]);
                harga[j] = harga[j + 1];
                jumlah[j] = jumlah[j + 1];
                strcpy(model[j + 1], tempModel);
                strcpy(merk[j + 1], tempmerek);
                harga[j + 1] = tempharga;
                jumlah[j + 1] = tempjumlah;
            }
        }
    }
    for (int i = 0; i < total; i++)
    {
        printf("Model: %s\n", model[i]);
        printf("merk: %s\n", merk[i]);
        printf("harga: %d\n", harga[i]);
        printf("jumlah: %d\n", jumlah[i]);
        printf("\n");
    }
}

// opsi 5

int main()
{
    int choice;
    do
    {
        menu();
        printf("Ada yang bisa saya bantu? ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            insert();
            break;
        case 2:
            update();
            break;
        case 3:
            search();
            break;
        case 4:
            sort();
            break;
        case 5:
            printf("Maaciw :v\n");
            break;
        default:
            printf("pilihan tidak ada dalam menu\n");
        }
        printf("\n");
    } while (choice != 5);
    return 0;
}
