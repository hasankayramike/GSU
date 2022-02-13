#include <stdio.h>
#include <math.h>

float nouveauCapital(int capital, float taux, int n)
{

    return capital * pow(taux + 1, n);
}

float revenueTotale(int capital, float taux, int n)
{
    return capital * pow(taux + 1, n) - capital;
}

int main()
{
    int capital, n;
    float taux, nvcapital, revenue;
    printf("Entrez le capital initial, le taux d'interet et le nombre d'annees:");
    scanf("%d%f%d", &capital, &taux, &n);
    nvcapital = nouveauCapital(capital, taux, n);
    revenue = revenueTotale(capital, taux, n);
    printf("Le nouveau capital est %.3f\n", nvcapital);
    printf("Le revenue total est %.3f pour %d annees", revenue, n);
    return 0;
}