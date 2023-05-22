#include <stdio.h>

int main()
{
    // Nomor 3
    float jamLembur;
    float gaji;

    printf("Masukan Jam Lebur: ");
    scanf("%f", &jamLembur);

    if(jamLembur < 12) {
        gaji = 100;
    }
    if(jamLembur > 12) {
        gaji = 300;
    }
    printf("Rp %.3f", gaji);

    /* =============================================================== */

    // Nomor 4
    char text[40] = "fakultas teknologi informasi dan bisnis";
    int count = 0;

    for (int i = 0; i < sizeof(text); i++)
    {
        if(text[i] == 'a' || text[i] == 'i' || text[i] == 'u' || text[i] == 'e' || text[i] == 'o') 
        {
            count++;
        }
    }

    printf("Total huruf vokal pada \"fakultas teknologi informasi dan bisnis\" sejumlah %i huruf", count);

    return 0;
}
