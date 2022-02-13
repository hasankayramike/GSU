#include <stdio.h>
#include <stdlib.h>
#define N 99999

int main(int argc, char* argv[])
{
    if (argc < 2)
    {
        printf("Vous devez entrer 2 arguments");
        return 1;
    }
    
    char isim[N];
    int not, kosul = 1;
    FILE *notlar = fopen(argv[1], "w");
    if (!notlar)
    {
        printf("Pas de fichier!\n");
        exit(1);
    }
    while (kosul == 1)
    {
        printf("Entrez le prenom: ");
        scanf("%s", isim);
        fprintf(notlar, "%s ", isim);
        printf("Entrez la note  : ");
        scanf("%d", &not);
        fprintf(notlar, " %3d\n", not);
        printf("Pour continuer [1], pour terminer [0]: ");
        scanf("%d", &kosul);
    }
    printf("Bye bye...\n");
    fclose(notlar);
    return 0;
}