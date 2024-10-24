#include <stdio.h>
#include <stdlib.h>

char converteChar(char c);

int main()
{
    int length = 6;
    char ac[length];
    fgets(ac, length, stdin);

    for (int i = 0; i < length; i++)
    {
        ac[i] = converteChar(ac[i]);
    }
    printf("%s\n", ac);

    return 0;
}

char converteChar(char c){
    int diferenca = c <= 90 ? 32 : -32;
    return c + diferenca;
}