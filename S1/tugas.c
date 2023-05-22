#include <stdio.h>
#include <string.h>

void main()
{
    int input;

    // Nomer 1
    printf("No. 1\n");
    do
    {
        printf("1. Ulang\n");
        printf("2. Keluar\n");
        printf("Pilih 1 atau 2: ");

        scanf("%d", &input);
    } while (input == 1);
    printf("Anda Pilih Keluar\n\nNo. 2\n");

    /* ============================ */
    
    // Nomer 2
    int Var;

    printf("Berapa Kali Loop: ");
    scanf("%d", &Var);

    char baris[15];

    for (int i = 1; i <= 6; i++)
    {
        strcat(baris, "* ");
        printf("%s\n", baris);
    }
}
