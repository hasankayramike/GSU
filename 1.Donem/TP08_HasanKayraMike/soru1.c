#include <stdio.h>

int main(int argc, char *argv[])
{
    printf("argc = %i\n", argc);
    for (int i = 0, n = argc; i < n; i++)
    {
        printf("argv[%i] = %s\n", i, argv[i]);
    }
    return 0;
}