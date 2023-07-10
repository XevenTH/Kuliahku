#include <stdio.h>

void RekursifHello(int cycle)
{
    if(cycle == 0) return;

    printf("Hello World\n");
    RekursifHello(cycle - 1);
}

int main()
{
    RekursifHello(10);

    return 0;
}
