#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TOPLAMSEHIR 81

// a)
typedef struct adjListNode {
    int data;
    struct adjListNode* next;
}adjListNode;

// b)
typedef struct adjList {
    adjListNode* head;
}adjList;

// d)
typedef struct graph {
    int totalNodes;
    adjList* lists;
}graph;

// g)
typedef struct sehir {
    int plaka;
    char isim[20];
    int mesafe;
}sehir;

// c) Yeni bir komsuluk listesi dugumu olusturup donduren fonksiyonu yazin.
adjListNode* newAdjListNode(int neighbor)
{
    adjListNode* newNode = malloc(sizeof(adjListNode));
    newNode->data = neighbor;
    newNode->next = NULL;
    return newNode;
}

// e) Olusturulacak cizgedeki dugum sayisini parametre olarak alan ve her bir
// dugum icin komsuluk listelerini olusturup hazirlayan ve graph yapisinda
// bir sonuc donduren fonksiyonu yazin.
graph* createGraph(int v)
{
    graph* new = malloc(sizeof(graph));
    new->lists = malloc(v * sizeof(adjList));
    new->totalNodes = v;
    for (int i = 0; i < v; i++)
    {
        new->lists[i].head = NULL;
    }
    return new;
}


// f) Parametre olarak aldigi cizgeye, yine parametre olarak aldigi merkez
// dugum ve komsusu arasindaki komsuluk iliskisini kuran fonksiyonu yazin.
void addEdge(graph* g, int center, int neighbor)
{
    adjListNode* new = newAdjListNode(neighbor);
    new->next = g->lists[center].head;
    g->lists[center].head = new;

    new = newAdjListNode(center);
    new->next = g->lists[neighbor].head;
    g->lists[neighbor].head = new;
}


// g) Moodle'da verilen sehir.txt dosyasinda sirasiyla illerin:
// plaka kodlari, isimleri ve km cinsinden Istanbul'a olan uzaklik bilgileri
// yer almaktadir. Bu dosyadaki verileri okuyup yapisini kendi tanimladiginiz
// bir struct tablosuna kopyalayan bir fonksiyon yazin.
sehir* copyToTable(char* filename)
{
    FILE* fp = fopen(filename, "r");
    if (fp == NULL) 
    {
        printf("%s dosyasi bulunamadi!\n", filename);
        exit(1);
    }

    sehir* table = malloc(TOPLAMSEHIR * sizeof(sehir));
    for (int i = 0; i < TOPLAMSEHIR; i++)
    {
        if (i == 33)
        {
            table[i].plaka = 34;
            strcpy(table[i].isim, "istanbul");
            table[i].mesafe = 0;
            continue;
        }
        fscanf(fp, "%d%s%d", &table[i].plaka, table[i].isim, &table[i].mesafe);
    }

    fclose(fp);
    return table;
}

// h) Istanbul'u merkez dugum olarak kabul edin ve komsular arasi
// mesafenin 250km sayildigi duruma gore komsuluk listelerini cikarin.
graph* createAdjLists(char* filename, int distance)
{
    sehir* table = copyToTable(filename);
    graph* g = createGraph(TOPLAMSEHIR);
    for (int i = 0; i < TOPLAMSEHIR; i++)
    {
        if (table[i].mesafe > distance || i == 33) continue;
        addEdge(g, 33, table[i].plaka-1);
    }
    return g;
}

// i) Cikardiginiz komsuluk listelerine gore listedeki her bir dugumun kacinci
// dereceden bir dugum oldugunu hesaplayan bir fonksiyon yazin.
// Dugumun Derecesi = Toplam Komsu Sayisi = Dugumden Cikan Baglanti Sayisi.
int* calculateDegrees(graph* g)
{
    int* degrees = malloc(TOPLAMSEHIR * sizeof(int));
    for (int i = 0; i < TOPLAMSEHIR; i++)
    {
        degrees[i] = 0;
    }

    for (int i = 0; i < TOPLAMSEHIR; i++)
    {
        adjListNode* temp = g->lists[i].head;
        while (temp)
        {
            degrees[i]++;
            temp = temp->next;
        }
    }
    return degrees;
}

// j) Her bir sehir icin:
// Sehrin Adi: X, Merkeze Uzaklgi: X, Komsu Sayisi: X, Komsulari: X,X,X...
// seklinde bir cikti verin.
int main(int argc, char* argv[])
{
    if (argc != 2)
    {
        printf("\nKullanim: %s <dosya_adi>\n", argv[0]);
        return -1;
    }

    sehir* table = copyToTable(argv[1]);
    graph* g = createAdjLists(argv[1], 250);
    int* degrees = calculateDegrees(g);
    for (int i = 0; i < TOPLAMSEHIR; i++) {
        printf("Sehrin Adi: %s, Merkeze Uzaklgi: %d, Komsu Sayisi: %d, Komsulari:", table[i].isim, table[i].mesafe, degrees[table[i].plaka-1]);
        for (adjListNode* j = g->lists[i].head; j != NULL; j = j->next)
        {
            printf(" %s", table[j->data].isim);
        }
        printf("\n");
    }
    free(g);
    free(table);
    free(degrees);
    return 0;
}