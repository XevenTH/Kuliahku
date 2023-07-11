#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void PalindromeCheck(char *word, char *palindromeWord, int len, int pal)
{
    // Melakukan rekursif sampai array panjang dari array tidak memnuhi
    if (len >= 0)
    {
        // Masukan satu persaru dari belakang ke dalam array satunya
        palindromeWord[pal] = word[len];
        // lakukan rekursif
        PalindromeCheck(word, palindromeWord, len - 1, pal + 1);
    }
}

int main()
{
    // Menyiapan beberapa bariabel menyimpan kata
    char Word[50];
    char PalindromeWord[50];

    // Meminta kata dari user
    printf("Masukan Kata: ");
    scanf("%s", &Word);

    // mencari panjang dari array
    int len = strlen(Word);

    PalindromeCheck(Word, PalindromeWord, len-1, 0);

    // Melakukan komparasi antara kedua array, jika true maka bukan palindrome
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
