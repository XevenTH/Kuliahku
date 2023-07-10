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
    char Ary[100];

    printf("Masukkan string: ");
    scanf("%s", Ary);

    char current[100] = "";

    printf("Subsekuen dari string %s adalah:\n", Ary);
    SubsekuenCheck(Ary, current, 0);

    return 0;
}
