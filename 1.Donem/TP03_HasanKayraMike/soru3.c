#include <stdio.h>

float leMax(float a, float b, float c)
{
    if ((a > b && a > c) || (a == b && a > c) || (a == c && a > b) || (b == c == a))
    {
        return a; 
    }
    else if (b < c && a < c)
    {
        return c;
    }
    else if ((b > a && b > c) || (b == c && b > a))
    {
        return b;
    }
}

float leMin(float a, float b, float c)
{
    if ((a < b && a < c) || (a == b && a < c) || (a == c && a < b) || (b == c == a))
    {
        return a; 
    }
    else if (b > c && a > c)
    {
        return c;
    }
    else if ((b < a && b < c) || (b == c && b < a))
    {
        return b;
    }
}

int main()
{
    float a, b, c, min, max;
    printf("Entrez 3 entiers reels: ");
    scanf("%f%f%f", &a, &b, &c);
    min = leMin(a, b, c);
    max = leMax(a, b, c);
    printf("Max: %.2f\n", max);
    printf("Min: %.2f\n", min);
    return 0;
}