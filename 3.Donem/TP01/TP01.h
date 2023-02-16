#ifndef TP01_H_
#define TP01_H_

typedef struct node
{
    char song[999];
    char artist[999];
    char album[999];
    int duration; //in seconds
    int year;
    struct node* next;
    struct node* prev;
}node;

typedef struct
{
    node* head;
    node* last;
}list;

node* createNewNodeSL(char* song, char* artist, char* album, int duration, int year);
list* createNewListSL(char* song, char* artist, char* album, int duration, int year);
node* getNodeBeforeSL(list* list, char* song);
node* getNodeSL(list* list, char* song);
void printNodeSL(list* list, char* song);
void insertAtTheEndSL(list* list, char* song, char* artist, char* album, int duration, int year);
void insertAtTheBeginningSL(list* list, char* song, char* artist, char* album, int duration, int year);
void insertAfterANodeSL(list* list, char* insertAfterThisSong, char* song, char* artist, char* album, int duration, int year);
void removeLastNodeSL(list* list);
void removeFirstNodeSL(list* list);
void removeFromMiddleSL(list* list, char* songToDelete);
void printListSL(list* list);

node* createNewNodeCSL(char* song, char* artist, char* album, int duration, int year);
list* createNewListCSL(char* song, char* artist, char* album, int duration, int year);
node* getNodeBeforeCSL(list* list, char* song);
node* getNodeCSL(list* list, char* song);
void printNodeCSL(list* list, char* song);
void insertAtTheEndCSL(list* list, char* song, char* artist, char* album, int duration, int year);
void insertAtTheBeginningCSL(list* list, char* song, char* artist, char* album, int duration, int year);
void insertAfterANodeCSL(list* list, char* insertAfterThisSong, char* song, char* artist, char* album, int duration, int year);
void removeLastNodeCSL(list* list);
void removeFirstNodeCSL(list* list);
void removeFromMiddleCSL(list* list, char* songToDelete);
void printListCSL(list* list);

node* createNewNodeDL(char* song, char* artist, char* album, int duration, int year);
list* createNewListDL(char* song, char* artist, char* album, int duration, int year);
node* getNodeDL(list* list, char* song);
void printNodeDL(list* list, char* song);
void insertAtTheEndDL(list* list, char* song, char* artist, char* album, int duration, int year);
void insertAtTheBeginningDL(list* list, char* song, char* artist, char* album, int duration, int year);
void insertAfterANodeDL(list* list, char* insertAfterThisSong, char* song, char* artist, char* album, int duration, int year);
void removeLastNodeDL(list* list);
void removeFirstNodeDL(list* list);
void removeFromMiddleDL(list* list, char* songToDelete);
void printListDL(list* list);

node* createNewNodeCDL(char* song, char* artist, char* album, int duration, int year);
list* createNewListCDL(char* song, char* artist, char* album, int duration, int year);
node* getNodeCDL(list* list, char* song);
void printNodeCDL(list* list, char* song);
void insertAtTheEndCDL(list* list, char* song, char* artist, char* album, int duration, int year);
void insertAtTheBeginningCDL(list* list, char* song, char* artist, char* album, int duration, int year);
void insertAfterANodeCDL(list* list, char* insertAfterThisSong, char* song, char* artist, char* album, int duration, int year);
void removeLastNodeCDL(list* list);
void removeFirstNodeCDL(list* list);
void removeFromMiddleCDL(list* list, char* songToDelete);
void printListCDL(list* list);


#endif