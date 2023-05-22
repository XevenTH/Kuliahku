#include <stdio.h>

int main()
{
    char op[] = {"nama saya joko widodo, presiden indonesia ke-6 menang dua periode"};
    int test[2] = {1, 2};

    // printf("%f", op);
    // printf("%f\n", sizeof(int));
    // printf("%d\n", test);
    // printf("%d\n", &test[0]);
    // printf("%d\n", &test[1]);
    // printf("%d", &test[2]);

    int karakter = 0;
    int kata = 0;

    for (int i = 0; i < sizeof(op) - 1; i++)
    {
        if(op[i] == ' ') continue;
        karakter++;
    }

    for (int i = 0; i < sizeof(op) - 1; i++)
    {
        if(op[i] == ' ' || i == sizeof(op) - 2) kata++;
    }
    
    printf("%d\n", karakter);
    printf("%d", kata);

    return 0;
}
