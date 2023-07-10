#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void PalindromeCheck(char *word, char *palindromeWord, int len, int pal)
{
    if (len >= 0)
    {
        palindromeWord[pal] = word[len];
        PalindromeCheck(word, palindromeWord, len - 1, pal + 1);
    }
}

int main()
{
    char Word[50];
    char PalindromeWord[50];

    printf("Masukan Kata: ");
    scanf("%s", &Word);

    int len = strlen(Word);

    PalindromeCheck(Word, PalindromeWord, len-1, 0);

    if (strcmp(Word, PalindromeWord))
    {
        printf("Bukan Palaindrome");
    }
    else
    {
        printf("Ini Palaindrome");
    }
    

    return 0;
}
