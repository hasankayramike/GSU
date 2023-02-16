#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "TP01.h"


/* ###############################
############## SL ################
############################### */

// Listeyi tanimlamak + ilk deger atamasi yapmak
node* createNewNodeSL(char* song, char* artist, char* album, int duration, int year)
{
    node* newNode = malloc(sizeof(node));
    strcpy(newNode->song, song);
    strcpy(newNode->artist, artist);
    strcpy(newNode->album, album);
    newNode->duration = duration;
    newNode->year = year;
    newNode->next = NULL;
    return newNode;
}

list* createNewListSL(char* song, char* artist, char* album, int duration, int year)
{
    list* newList = malloc(sizeof(list));
    newList->head = createNewNodeSL(song, artist, album, duration, year);
    return newList;
}

// Arama kriteri olan karakter dizilerinden birini kullanarak tek bir elemani goruntulemek
node* getNodeBeforeSL(list* list, char* song)
{
    node* tmp = list->head;
    while (tmp->next != NULL)
    {
        if (strcmp(tmp->next->song, song) != 0)
        {
            tmp = tmp->next;
            continue;
        }
        return tmp;
    }

    // Dongu sadece listenin sonuna gelindigi icin bittiyse ve hicbir sey dondurmediyse istenen sarki listede bulunmuyor demektir, head pointer dondurur 
    // Liste bossa, listede tek eleman varsa ya da aranan eleman listenin ilk elemaniysa yine head dondurur cunku bir onceki elemani donduremeyiz
    return list->head;
}

node* getNodeSL(list* list, char* song)
{
    // Liste tek elemanli ya da istenen eleman listenin ilk elemani ise head pointer dondurur
    if (list->head->next == NULL || strcmp(list->head->song, song) == 0)
    {
        // Buraya return getNodeBeforeSL(list, song); yazsam da ayni islevi gorurdu
        // Fazladan islem yaptirmamak icin direkt sonucu dondurdum
        return list->head;
    }
    return getNodeBeforeSL(list, song)->next;
}

    // Goruntuledigimiz dugumu bastirmak istersek
void printNodeSL(list* list, char* song)
{
    node* tmp = getNodeSL(list, song);
    printf("Song: %s\nArtist: %s\nAlbum: %s\nDuration: %d\nYear: %d\n##########\n", tmp->song, tmp->artist, tmp->album, tmp->duration, tmp->year);
}

// Listeye yeni eleman eklemek

    // Sona eklemek
void insertAtTheEndSL(list* list, char* song, char* artist, char* album, int duration, int year)
{
    node* tmp = malloc(sizeof(node));
    tmp = list->head;
    while(tmp->next != NULL)
    {
        tmp = tmp->next;
    }
    tmp->next = createNewNodeSL(song, artist, album, duration, year);
}

    // Basa eklemek
void insertAtTheBeginningSL(list* list, char* song, char* artist, char* album, int duration, int year)
{
    node* newNode = createNewNodeSL(song, artist, album, duration, year);
    newNode->next = list->head;
    list->head = newNode;
}

    // Secilen bir noktaya eklemek
void insertAfterANodeSL(list* list, char* insertAfterThisSong, char* song, char* artist, char* album, int duration, int year)
{
    node* newNode = createNewNodeSL(song, artist, album, duration, year);
    node* insertAfterThisNode = getNodeSL(list, insertAfterThisSong);

    // Arama kriteri olan sarki listede yoksa getNodeBeforeSL fonksiyonu head dondurecek dolayisiyla getNodeSL da head->next dondurecek
    // Bu nedenle head->next'teki sarki adi ile arguman olarak girilen sarki adi farkli olacak
    // Bu farklilik var ise arama kriteri listenin bir elemani degildir.
    if (strcmp(insertAfterThisNode->song, insertAfterThisSong) != 0 )
    {
        printf("Song not found! Instead, we'll instead add it at the end of the playlist!\n");
        insertAtTheEndSL(list, song, artist, album, duration, year);
        return;
    }
    newNode->next = insertAfterThisNode->next;
    insertAfterThisNode->next = newNode;
}

//Eleman silmek

    // Son elemani silmek
void removeLastNodeSL(list* list)
{
    // Liste bossa hicbir sey yapmamasini saglar
    if (list->head == NULL) return;

    // Listede tek eleman varsa direkt listeyi siler
    if (list->head->next == NULL)
    {
        free(list);
        return;
    }


    node* tmp = list->head;
    while (tmp->next->next != NULL)
    {
        tmp = tmp->next;
    }
    free(tmp->next);
    tmp->next = NULL;
}

    // Ilk elemani silmek
void removeFirstNodeSL(list* list)
{
        // Liste bossa hicbir sey yapmamasini saglar
    if (list->head == NULL) return;

    // Listede tek eleman varsa direkt listeyi siler
    if (list->head->next == NULL)
    {
        free(list);
        return;
    }

    node* tmp = list->head;
    list->head = tmp->next;
    free(tmp);
}

    // Istenilen bir elemani silmek
void removeFromMiddleSL(list* list, char* songToDelete)
{
    // Liste bossa hicbir sey yapmamasini saglar
    if (list->head == NULL) return;

    // Listede tek eleman varsa direkt listeyi siler
    if (list->head->next == NULL)
    {
        free(list);
        return;
    }

    node* tmp = getNodeBeforeSL(list, songToDelete);
    node* toDelete = tmp->next;

    // Silinecek sarki listede yoksa getNodeBeforeSL head dondurdugunden getNodeSL da head->next dondurecek
    // toDelete = head->next olacagindan toDelete->song ile silmek istedigimiz sarkinin adi farkli olacak
    // Bu farklilik varsa ancak silmek istedigimiz sarkinin listenin bir elemani olmadigini anlariz,
    if (strcmp(toDelete->song, songToDelete) != 0)
    {
        printf("Song not found!\n");
        return;
    }
    tmp->next = toDelete->next;
    free(toDelete);
}

void printListSL(list* list)
{
    if (list->head == NULL)
    {
        printf("Contents of this playlist had been removed!\n");
        return;
    }
    
    for (node* tmp = list->head; tmp != NULL; tmp = tmp->next)
    {
        printf("Song: %s\nArtist: %s\nAlbum: %s\nDuration: %d\nYear: %d\n##########\n", tmp->song, tmp->artist, tmp->album, tmp->duration, tmp->year);
    }
    printf("\n");
}


/* ###############################
############## CSL ###############
############################### */

// Listeyi tanimlamak + ilk deger atamasi yapmak
node* createNewNodeCSL(char* song, char* artist, char* album, int duration, int year)
{
    node* newNode = malloc(sizeof(node));
    strcpy(newNode->song, song);
    strcpy(newNode->artist, artist);
    strcpy(newNode->album, album);
    newNode->duration = duration;
    newNode->year = year;
    newNode->next = NULL;
    return newNode;
}

list* createNewListCSL(char* song, char* artist, char* album, int duration, int year)
{
    list* newList = malloc(sizeof(list));
    node* newNode = createNewNodeCSL(song, artist, album, duration, year);
    newList->last = newNode;
    newNode->next = newList->last;
    newList->last->next = newNode;
    return newList;
}

// Arama kriteri olan karakter dizilerinden birini kullanarak tek bir elemani goruntulemek

node* getNodeBeforeCSL(list* list, char* song)
{
    node* tmp = list->last->next;
    if (strcmp(tmp->song, song) == 0)
    {
        return list->last;
    }
    while (tmp->next != list->last->next)
    {
        if (strcmp(tmp->next->song, song) != 0)
        {
            tmp = tmp->next;
            continue;
        }
        return tmp;
    }
    return list->last;
}

node* getNodeCSL(list* list, char* song)
{
    if (list->last == list->last->next)
    {
        return list->last;
    }
    return getNodeBeforeCSL(list, song)->next;
}

// Goruntuledigimiz dugumu bastirmak istersek
void printNodeCSL(list* list, char* song)
{
    node* tmp = getNodeCSL(list, song);
    printf("Song: %s\nArtist: %s\nAlbum: %s\nDuration: %d\nYear: %d\n##########\n", tmp->song, tmp->artist, tmp->album, tmp->duration, tmp->year);
}


// Listeye yeni eleman eklemek

    // Sona eklemek
void insertAtTheEndCSL(list* list, char* song, char* artist, char* album, int duration, int year)
{
    node* newNode = createNewNodeCSL(song, artist, album, duration, year);
    newNode->next = list->last->next;
    list->last->next = newNode;
    list->last = newNode;
}

    // Basa eklemek
void insertAtTheBeginningCSL(list* list, char* song, char* artist, char* album, int duration, int year)
{
    node* newNode = createNewNodeCSL(song, artist, album, duration, year);
    newNode->next = list->last->next;
    list->last->next = newNode;
}

    // Secilen bir noktaya eklemek
void insertAfterANodeCSL(list* list, char* insertAfterThisSong, char* song, char* artist, char* album, int duration, int year)
{
    node* newNode = createNewNodeCSL(song, artist, album, duration, year);
    node* insertAfterThisNode = getNodeCSL(list, insertAfterThisSong);
    if (strcmp(insertAfterThisNode->song, insertAfterThisSong) != 0 )
    {
        printf("Song not found! Instead, we'll instead add it at the end of the playlist!\n");
        insertAtTheEndCSL(list, song, artist, album, duration, year);
        return;
    }
    newNode->next = insertAfterThisNode->next;
    insertAfterThisNode->next = newNode;
}


// Listeden eleman silmek

    // Son elemani silmek
void removeLastNodeCSL(list* list)
{
    if (list->last == NULL) return;

    if (list->last->next == list->last)
    {
        free(list);
        return;
    }
    
    node* tmp = list->last;
    node* newLast = getNodeBeforeCSL(list, list->last->song);
    newLast->next = list->last->next;
    list->last = newLast;
    free(tmp);
}

    // Ilk elemani silmek
void removeFirstNodeCSL(list* list)
{
    if (list->last == NULL) return;

    if (list->last->next == list->last)
    {
        free(list);
        return;
    }
    
    node* head = list->last->next;
    list->last->next = head->next;
    free(head);
}

    // Istenilen bir elemani silmek
void removeFromMiddleCSL(list* list, char* songToDelete)
{
    if (list->last == NULL) return;

    if (list->last->next == list->last)
    {
        free(list);
        return;
    }
    
    node* tmp = getNodeBeforeCSL(list, songToDelete);
    node* toDelete = tmp->next;
    if (strcmp(toDelete->song, songToDelete) != 0)
    {
        printf("Song not found!\n");
        return;
    }
    tmp->next = toDelete->next;
    free(toDelete);
}


// Listede  yer  alan  tüm  elemanları  düzgün  bir sekilde  ekrana  bastırmak
void printListCSL(list* list)
{
    if (list->last == NULL)
    {
        printf("Contents of this playlist had been removed!\n");
        return;   
    }
    
    printNodeCSL(list, list->last->next->song);
    for (node* tmp = list->last->next->next; tmp != list->last->next; tmp = tmp->next)
    {
        printf("Song: %s\nArtist: %s\nAlbum: %s\nDuration: %d\nYear: %d\n##########\n", tmp->song, tmp->artist, tmp->album, tmp->duration, tmp->year);
    }
    printf("\n");
}

/* ###############################
############## DL ################
############################### */

// Listeyi tanimlamak + ilk deger atamasi yapmak
node* createNewNodeDL(char* song, char* artist, char* album, int duration, int year)
{
    node* newNode = malloc(sizeof(node));
    strcpy(newNode->song, song);
    strcpy(newNode->artist, artist);
    strcpy(newNode->album, album);
    newNode->duration = duration;
    newNode->year = year;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}

list* createNewListDL(char* song, char* artist, char* album, int duration, int year)
{
    list* newList = malloc(sizeof(list));
    newList->head = createNewNodeDL(song, artist, album, duration, year);
    return newList;
}


// Arama kriteri olan karakter dizilerinden birini kullanarak tek bir elemani goruntulemek
node* getNodeDL(list* list, char* song)
{
    node* tmp = list->head;
    while (tmp != NULL)
    {
        if (strcmp(tmp->song, song) != 0)
        {
            tmp = tmp->next;
            continue;
        }
        return tmp;
    }
    return list->head;
}

// Goruntuledigimiz dugumu bastirmak istersek
void printNodeDL(list* list, char* song)
{
    node* tmp = getNodeDL(list, song);
    printf("Song: %s\nArtist: %s\nAlbum: %s\nDuration: %d\nyear: %d\n##########\n\n", tmp->song, tmp->artist, tmp->album, tmp->duration, tmp->year);
}

// Listeye yeni eleman eklemek

    // Sona eklemek
void insertAtTheEndDL(list* list, char* song, char* artist, char* album, int duration, int year)
{
    node* tmp = list->head;
    while (tmp->next != NULL)
    {
        tmp = tmp->next;
    }
    tmp->next = createNewNodeDL(song, artist, album, duration, year);
    tmp->next->prev = tmp;
}

    // Basa eklemek
void insertAtTheBeginningDL(list* list, char* song, char* artist, char* album, int duration, int year)
{
    node* newNode = createNewNodeDL(song, artist, album, duration, year);
    newNode->next = list->head;
    list->head->prev = newNode;
    list->head = newNode;
}

    // Secilen bir noktaya eklemek
void insertAfterANodeDL(list* list, char* insertAfterThisSong, char* song, char* artist, char* album, int duration, int year)
{
    node* newNode = createNewNodeDL(song, artist, album, duration, year);
    node* insertAfterThisNode = getNodeDL(list, insertAfterThisSong);

    if (strcmp(insertAfterThisNode->song, insertAfterThisSong) != 0 )
    {
        printf("Song not found! Instead, we'll instead add it at the end of the playlist!\n");
        insertAtTheEndDL(list, song, artist, album, duration, year);
        return;
    }
    newNode->next = insertAfterThisNode->next;
    insertAfterThisNode->next->prev = newNode;
    newNode->prev = insertAfterThisNode;
    insertAfterThisNode->next = newNode;
}


// Listeden eleman silmek

    // Son elemani silmek
void removeLastNodeDL(list* list)
{    
    if (list->head == NULL) return;

    if (list->head->next == NULL)
    {
        free(list);
        return;
    }
    node* tmp = list->head;
    while (tmp->next->next != NULL)
    {
        tmp = tmp->next;
    }
    tmp->next = NULL;
    free(tmp->next);
}

    // Ilk elemani silmek
void removeFirstNodeDL(list* list)
{
    if (list->head == NULL) return;

    if (list->head->next == NULL)
    {
        free(list);
        return;
    }
    node* tmp = list->head;
    list->head = tmp->next;
    list->head->prev = NULL;
    free(tmp);
}

    // Istenilen bir elemani silmek
void removeFromMiddleDL(list* list, char* songToDelete)
{
    if (list->head == NULL) return;

    if (list->head->next == NULL)
    {
        free(list);
        return;
    }
    node* toDelete = getNodeDL(list, songToDelete);
    node* tmp = toDelete->prev;

    if (strcmp(toDelete->song, songToDelete) != 0)
    {
        printf("Song not found!\n");
        return;
    }
    tmp->next = toDelete->next;
    toDelete->next->prev = tmp;
    free(toDelete);
}


// Listede  yer  alan  tüm  elemanları  düzgün  bir sekilde  ekrana  bastırmak
void printListDL(list* list)
{
    if (list->head == NULL)
    {
        printf("Contents of this playlist had been removed!\n");
        return;
    }
    
    node* tmp = list->head;
    while (tmp != NULL)
    {
        printf("Song: %s\nArtist: %s\nAlbum: %s\nDuration: %d\nyear: %d\n##########\n", tmp->song, tmp->artist, tmp->album, tmp->duration, tmp->year);
        tmp = tmp->next;
    }
    printf("\n");
}



/* ###############################
############## CDL ###############
############################### */

// Listeyi tanimlamak + ilk deger atamasi yapmak
node* createNewNodeCDL(char* song, char* artist, char* album, int duration, int year)
{
    node* newNode = malloc(sizeof(node));
    strcpy(newNode->song, song);
    strcpy(newNode->artist, artist);
    strcpy(newNode->album, album);
    newNode->duration = duration;
    newNode->year = year;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}

list* createNewListCDL(char* song, char* artist, char* album, int duration, int year)
{
    list* newList = malloc(sizeof(list));
    node* firstNode = createNewNodeCDL(song, artist, album, duration, year);
    newList->head = firstNode;
    firstNode->next = newList->head;
    newList->head->prev = firstNode;
    return newList;
}

// Arama kriteri olan karakter dizilerinden birini kullanarak tek bir elemani goruntulemek
node* getNodeCDL(list* list, char* song)
{
    node* tmp = list->head;
    if (strcmp(tmp->song, song) == 0) return tmp;
    tmp = tmp->next;
    while (tmp != list->head)
    {
        if (strcmp(tmp->song, song) != 0)
        {
            tmp = tmp->next;
            continue;
        }
        return tmp;
    }
}

// Goruntuledigimiz dugumu bastirmak istersek
void printNodeCDL(list* list, char* song)
{
    node* tmp = getNodeCDL(list, song);
    printf("Song: %s\nArtist: %s\nAlbum: %s\nDuration: %d\nyear: %d\n##########\n\n", tmp->song, tmp->artist, tmp->album, tmp->duration, tmp->year);
}



// Listeye yeni eleman eklemek

    // Sona eklemek
void insertAtTheEndCDL(list* list, char* song, char* artist, char* album, int duration, int year)
{
    node* tmp = list->head;
    node* newNode = createNewNodeCDL(song, artist, album, duration, year);
    while (tmp->next != list->head)
    {
        tmp = tmp->next;
    }
    tmp->next = newNode;
    newNode->prev = tmp;
    newNode->next = list->head;
    list->head->prev = newNode;
}

    // Basa eklemek
void insertAtTheBeginningCDL(list* list, char* song, char* artist, char* album, int duration, int year)
{
    node* newNode = createNewNodeCDL(song, artist, album, duration, year);
    node* lastNode = list->head->prev;
    newNode->next = list->head;
    newNode->prev = lastNode;
    lastNode->next = newNode;
    list->head->prev = newNode;
    list->head = newNode;
}

    // Secilen bir noktaya eklemek
void insertAfterANodeCDL(list* list, char* insertAfterThisSong, char* song, char* artist, char* album, int duration, int year)
{
    node* newNode = createNewNodeCDL(song, artist, album, duration, year);
    node* insertAfterThisNode = getNodeCDL(list, insertAfterThisSong);
    if (strcmp(insertAfterThisNode->song, insertAfterThisSong) != 0 )
    {
        printf("Song not found! Instead, we'll instead add it at the end of the playlist!\n");
        insertAtTheEndCDL(list, song, artist, album, duration, year);
        return;
    }
    newNode->next = insertAfterThisNode->next;
    newNode->prev = insertAfterThisNode;
    insertAfterThisNode->next->prev = newNode;
    insertAfterThisNode->next = newNode;

}


// Listeden eleman silmek

    // Son elemani silmek
void removeLastNodeCDL(list* list)
{
    if (list->head == NULL) return;

    if (list->head->next == list->head)
    {
        free(list);
        return;
    }
    node* tmp = list->head->prev;
    node* newLast = tmp->prev;
    newLast->next = list->head;
    list->head->prev = newLast;
    free(tmp);

}

    // Ilk elemani silmek
void removeFirstNodeCDL(list* list)
{
    if (list->head == NULL) return;

    if (list->head->next == list->head)
    {
        free(list);
        return;
    }
    node* last = list->head->prev;
    node* newHead = list->head->next;
    last->next = newHead;
    newHead->prev = last;
    free(list->head);
    list->head = newHead;
}

    // Secilen bir elemani silmek
void removeFromMiddleCDL(list* list, char* songToDelete)
{
    if (list->head == NULL) return;

    if (list->head->next == list->head)
    {
        free(list);
        return;
    }
    node* toDelete = getNodeCDL(list, songToDelete);
    node* tmp = toDelete->prev;
    if (strcmp(toDelete->song, songToDelete) != 0)
    {
        printf("Song not found!\n");
        return;
    }
    tmp->next = toDelete->next;
    toDelete->next->prev = tmp;
    free(toDelete);
}


// Listede  yer  alan  tüm  elemanları  düzgün  bir sekilde  ekrana  bastırmak
void printListCDL(list* list)
{
    if (list->head == NULL)
    {
        printf("Contents of this playlist had been removed!\n");
        return;
    }
    
    node* tmp = list->head;
    printf("Song: %s\nArtist: %s\nAlbum: %s\nDuration: %d\nyear: %d\n##########\n", tmp->song, tmp->artist, tmp->album, tmp->duration, tmp->year);
    tmp = tmp->next;
    while (tmp != list->head)
    {
        printf("Song: %s\nArtist: %s\nAlbum: %s\nDuration: %d\nyear: %d\n##########\n", tmp->song, tmp->artist, tmp->album, tmp->duration, tmp->year);
        tmp = tmp->next;
    }
    printf("\n");
}