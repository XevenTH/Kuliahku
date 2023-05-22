#include <stdio.h>

typedef struct pecahan
{
    int pembilang;
    int penyebut;
} Pecahan;

int main()
{
    Pecahan newPecahan;
    int i, kpk;
    printf("(pembilang, penyebut) : ");
    scanf("%d %d", &newPecahan.pembilang, &newPecahan.penyebut);

    for (int i = 1; i <= newPecahan.pembilang && i <= newPecahan.penyebut; ++i)
    {
        // Checks if i is factor of both integers
        if (newPecahan.pembilang % i == 0 && newPecahan.penyebut % i == 0)
            kpk = i;
    }

    printf("Pecahan Paling Sederhana : %d/%d", newPecahan.pembilang / kpk, newPecahan.penyebut / kpk);
    return 0;
}