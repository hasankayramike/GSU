#include <stdio.h>
#include <math.h>

int main()
{
    int rayon = 5;
    int hauter = 10;
    const double pi = M_PI; 
    double surfaceBase = (pi * pow(rayon, 2));
    double surfaceLaterale = (2 * pi * rayon * hauter);
    double surfaceTotale = (surfaceBase * 2 + surfaceLaterale);
    double volume = (pi * pow(rayon, 2) * hauter);
    printf("La surface de la base : %f\n", surfaceBase);
    printf("La surface laterale   : %f\n", surfaceLaterale);
    printf("La surface totale     : %f\n", surfaceTotale);
    printf("Le volume             : %f\n", volume);  
    return(0);
}