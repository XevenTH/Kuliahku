#include <stdio.h>
#include <string.h>

void SubsekuenCheck(char *strAry, char *current, int idx)
{
    if (idx == strlen(strAry))
    {
        if (strlen(current) > 0)
        {
            printf("\"%s\" ", current);
        }
        return;
    }

    SubsekuenCheck(strAry, current, idx + 1);

    int len = strlen(current);
    current[idx] = strAry[idx];
    current[idx + 1] = '\0';
    SubsekuenCheck(strAry, current, idx + 1);

    current[idx] = '\0';
}

int main()
{
    char Ary[50];

    // Meminta string kepada user
    printf("Masukkan string: ");
    scanf("%s", Ary);

    // menteapkan nilai awal
    char current[50] = "";

    printf("Subsekuen dari string %s adalah:\n", Ary);
    //Menjalankan proses subsekuense
    SubsekuenCheck(Ary, current, 0);

    return 0;
}
