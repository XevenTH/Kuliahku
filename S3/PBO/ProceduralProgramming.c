#include <stdio.h>

int Tambah(int a, int b)
{
    int hasil = a + b;
    return hasil;
}

int Kurang(int a, int b)
{
    int hasil = a - b;
    return hasil;
}

int main()
{
    /* 
        int a, b, c;
        scanf("%d", a);
        scanf("%d", b);
        scanf("%d", c);
    */

    int penjumlahan = Tambah(1, 2);
    int pengurangan = Kurang(7, 2);

    printf("hasil penjumlahan : %d\n", penjumlahan);
    printf("hasil pengurangan : %d", pengurangan);

    return 0;
}
