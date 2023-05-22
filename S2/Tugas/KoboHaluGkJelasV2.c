#include <stdio.h>

typedef struct trapesium{
    int x;
    int y;
} Trapesium;

float CalculateTrapesium(Trapesium *trapAry)
{
    // [0] = A
    // [1] = B
    // [2] = C
    // [3] = D
    // [4] = E
    // [5] = F

    float DiffAB = trapAry[1].x - trapAry[0].x;
    float DiffCD = trapAry[3].x - trapAry[2].x;
    float High = trapAry[0].y - trapAry[2].y;

    float Hasil = (DiffAB + DiffCD) * High / 2;
    return Hasil;
}

int main()
{
    int length = 6;
    Trapesium trapAry[length];

    for (int i = 0; i < length; i++)
    {
        Trapesium newTrapesium;
        printf("Koordinat Titik %d : ", i + 1);
        scanf("%d", &newTrapesium.x);
        scanf("%d", &newTrapesium.y);
        trapAry[i] = newTrapesium;
    }

    printf("Luas Adalah : %.2f", CalculateTrapesium(trapAry));

    return 0;
}


