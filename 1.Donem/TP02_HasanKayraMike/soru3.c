#include <stdio.h>

int main()
{
    int x, y;
    printf("Entrez les coordonnees cartesiennes: ");
    scanf("%d %d", &x, &y);
    if (x > 0 && y > 0)
    {
        printf("(%d, %d) est dans le 1er quadrant\n", x, y);
    }
    else if (x > 0 && y < 0)
    {
        printf("(%d, %d) est dans le 4eme quadrant\n", x, y);
    }
    else if (x < 0 && y > 0)
    {
        printf("(%d, %d) est dans le 2eme quadrant\n", x, y);
    }
    else if (x < 0 && y < 0)
    {
        printf("(%d, %d) est dans le 3eme quadrant\n", x, y);
    }
    return 0;
}