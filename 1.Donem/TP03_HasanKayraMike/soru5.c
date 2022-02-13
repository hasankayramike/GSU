#include <stdio.h>

void afficheMultiple(int x, int limit)
{
    int output = x;
    while (output <= limit)
    {
        if (output % x == 0)
        {
            printf("%d ", output);
        }
        output += 1;
    }
}

int main()
{
    int x, limit;
    printf("Entrez un entier positif et un nombre limite: ");
    scanf("%d%d", &x, &limit);
    afficheMultiple(x, limit);
    return 0;
}