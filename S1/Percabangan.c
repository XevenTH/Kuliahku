#include <stdio.h>

int main()
{
    const int nilai = 90;

    if (nilai >= 90)
    {
        printf("A\n");
    }
    else if (nilai >= 80 && nilai < 90)
    {
        printf("B\n");
    }
    else if (nilai >= 70 && nilai < 80)
    {
        printf("C\n");
    }
    else if (nilai >= 60 && nilai < 70)
    {
        printf("D\n");
    }
    else 
    {
        printf("E\n");
    }

    switch (nilai)
    {
    case 90:
        printf("Amazing");
        break;
    case 80:
        printf("Pintar");
        break;
    case 70:
        printf("Good");
        break;
    case 60:
        printf("Mepet Bos");
        break;
    default:
        printf("Belajar Lagi");
        break;
    }

    return 0;
}