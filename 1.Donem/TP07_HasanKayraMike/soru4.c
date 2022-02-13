#include <stdio.h>

int charCounter(char *c);
void stringPrinter(char *c, int n);

int main()
{
    char x[] = "introduction to C programming";
    int length = charCounter(x);
    stringPrinter(x, length);
    return 0;
}

int charCounter(char *c)
{
    int i;
    for (i = 0; c[i] != '\0'; i++);
    return i;
}

void stringPrinter(char *c, int size)
{
    for (int i = 0; i < size; i++)
    {
        if (c[i] == 32)
        {
            printf("space ");
        }
        else
        {
            printf("%c ", c[i]);
        }
    }
}