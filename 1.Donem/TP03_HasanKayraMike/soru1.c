#include <stdio.h>

int laSomme(int n)
{
    int output = 0;
    int add = 0;
    while (add <= n)
    {
        output += add;
        add += 1;
    }
    return output;
}

int main()
{
    int n, sum;
    printf("Entrez un entier positive: ");
    scanf("%d", &n);
    sum = laSomme(n);
    printf("La somme est %d\n", sum);
    return 0;
}