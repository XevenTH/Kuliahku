#include <stdio.h>
#include <string.h>

void CountArray(char *ary, int len, int *hasil)
{
    if (len >= 0)
    {
        CountArray(ary, len - 1, hasil);
        *hasil = *hasil + 1;
    }
}

int main()
{
    char Ary[20];
    printf("Masukan Angka (Tanpa Spasi!!!): ");
    scanf("%s", &Ary);

    int len = strlen(Ary), hasil = 0;
    CountArray(Ary, len - 1, &hasil);
    printf("Hasil: %d", hasil);

    return 0;
}
