#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

typedef struct {
    int numara;
    char soyad[20];
    int not;
}ogrenci;


int main(int argc, char **argv) {
    if (argc < 4 || argc > 32 || (argc-2) % 2 != 0)
    {
        printf("Uygun olmayan arguman sayisi!\n");
        return 1;
    }
    int N = (argc - 2) / 2;
    ogrenci ogr[N];
    char* eskiDosyaAdi = argv[1];
    char* yeniDosyaAdi = "yeniNotlar.txt";
    for (int i = 2, j = 0; i < argc; i+= 2, j++)
    {
        strcpy(ogr[j].soyad, argv[i]);
        ogr[j].not = atoi(argv[i+1]);
    }
    FILE* eskiNot = fopen(eskiDosyaAdi, "r");
    FILE* yeniNot = fopen(yeniDosyaAdi, "w");
    if (!eskiNot || !yeniNot)
    {
        printf("Dosya(lar) bulunamadi");
        return 2;
    }
    rewind(eskiNot);
    rewind(yeniNot); 
    int M = 5;
    ogrenci dosyaOgr[M];
    for (int i = 0; !feof(eskiNot); i++)
    {
        fscanf(eskiNot, "%ld %s %d\n", &dosyaOgr[i].numara, dosyaOgr[i].soyad, &dosyaOgr[i].not);
    } 
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            if (!strcmp(dosyaOgr[j].soyad, ogr[i].soyad))
            {
                if (ogr[i].not + dosyaOgr[j].not <= 100)
                {
                    if (ogr[i].not + dosyaOgr[j].not >= 0)
                    {
                        dosyaOgr[j].not += ogr[i].not;
                        break;
                    }
                    else
                    {
                        dosyaOgr[j].not = 0;
                        break;
                    }
                }
                else
                {
                    dosyaOgr[j].not = 100;
                    break;
                }
            }
        }
    }
    for (int i = 0; i < M; i++)
    {
        fprintf(yeniNot, "%ld %s %d\n", dosyaOgr[i].numara, dosyaOgr[i].soyad, dosyaOgr[i].not);
    }
    fclose(yeniNot);
    fclose(eskiNot);
    printf("          ------------------\n");
    printf("          | Sistem Gunlugu |\n");
    printf("          ------------------\n");
    if (!remove(eskiDosyaAdi))
    {
        printf("-------------------------------------\n");
        printf("| Eski dosya basariyla silindi.     |\n");
    }
    else
    {
        printf("--------------------------\n");
        printf("| Eski dosya silinemedi. |\n");
        printf("--------------------------\n");
        printf("-----------------------\n");
        printf("| Islem Sonlandirildi |\n");
        printf("-----------------------\n");
        return 3;
    }
    if (!rename(yeniDosyaAdi, eskiDosyaAdi))
    {
        printf("-------------------------------------\n");
        printf("| Dosya adi basariyla degistirildi. |\n");
        printf("-------------------------------------\n");
        printf("| Eski dosya adi: %s    |\n", yeniDosyaAdi);
        printf("-------------------------------------\n");
        printf("| Yeni dosya adi: %s        |\n", eskiDosyaAdi);
        printf("-------------------------------------\n");
        printf("-----------------------\n");
        printf("| Islem Sonlandirildi |\n");
        printf("-----------------------\n");
    }
    else
    {
        printf("-------------------------------------\n");
        printf("| Dosya adi degistirilemedi!        |\n");
        printf("-------------------------------------\n");
        printf("-----------------------\n");
        printf("| Islem Sonlandirildi |\n");
        printf("-----------------------\n");
        return 4;
    }
    return 0;
}