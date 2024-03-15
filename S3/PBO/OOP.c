#include <stdio.h>

typedef struct angka
{
    int pertama;
    int kedua;
} Angka;

int Tambah(Angka angka)
{
    int hasil = angka.pertama + angka.kedua;
    return hasil;
}

int main()
{
    /*
        Angka user3, user4, user5;
        
        scanf("%d", user3.pertama);
        scanf("%d", user3.kedua);

        scanf("%d", user4.pertama);
        scanf("%d", user4.kedua);
    */

    Angka user1 = {1, 2};
    Angka user2 = {4, 7};

    printf("Hasil user 1 : %d\n", Tambah(user1));
    printf("Hasil user 2 : %d", Tambah(user2));

    return 0;
}
