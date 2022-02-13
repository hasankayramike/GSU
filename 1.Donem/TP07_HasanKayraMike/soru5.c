#include <stdio.h>

int charCounter(char *c);
char *strMinus3(char *c, int size);

int main()
{
    char x[] = "Wdqulp#qh#ndgdu#gd#vdkdqh#elu#ghuv$";
    int length = charCounter(x);
    char *xnew = strMinus3(x, length);
    printf("%s\n", xnew);
    return 0;
}

int charCounter(char *c)
{
    int i;
    for (i = 0; c[i] != '\0'; i++);
    return i;
}

char *strMinus3(char *c, int size)
{
    for (int i = 0; i < size; i++)
    {
        c[i] -= 3;
    }
    return c;
}