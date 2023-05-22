#include <stdio.h>
#define longString = 100

int main()
{
    int a, b, c;
    int jumlahTeam;
    char tempName[100];
    char tempAry[100];
    int tempInt[jumlahTeam];

    int count = 0;
    int lineNumber = 2;

    FILE *newFile;

    newFile = fopen("data/output.txt", "w");

    printf("Masukan Jumlah Team: ");
    scanf("%d", &jumlahTeam);

    for (int i = 1; i <= jumlahTeam; i++)
    {
        printf("Masukan Nama Team Ke-%d: ", i);
        scanf("%s", tempName);

        printf("Masukan Skor Team %s :", tempName);
        scanf("%d %d %d", &a, &b, &c);

        fprintf(newFile, "%s %d %d %d\n", tempName, a, b, c);
    }

    fclose(newFile);

    FILE *newReadFile;

    newReadFile = fopen("data/output.txt", "r");

    while (fgets(tempAry, sizeof(tempAry), newReadFile))
    {
        if (count == lineNumber)
        {
            printf("%s", tempAry);
        }
        else
        {
            count++;
        }
    }
    fclose(newReadFile);

    // printf("Skor Team %s : %d %d %d", nameAry, a, b, c);

    return 0;
}
