#include <stdio.h>

typedef struct
{
    char nama;
} Tiang;

void MenaraHanoi(int n, Tiang tiangAsal, Tiang tiangBantuan, Tiang tiangTujuan)
{
    if (n == 1)
    {
        printf("Pindahkan cincin 1 dari tiang %c ke tiang %c\n", tiangAsal.nama, tiangTujuan.nama);
        return;
    }
    
    MenaraHanoi(n - 1, tiangAsal, tiangTujuan, tiangBantuan);
    printf("Pindahkan cincin %d dari tiang %c ke tiang %c\n", n, tiangAsal.nama, tiangTujuan.nama);
    MenaraHanoi(n - 1, tiangBantuan, tiangAsal, tiangTujuan);
}

int main()
{
    int n = 3; // jumlah cincin
    Tiang A = {'A'};
    Tiang B = {'B'};
    Tiang C = {'C'};
    MenaraHanoi(n, A, B, C);
    return 0;
}
