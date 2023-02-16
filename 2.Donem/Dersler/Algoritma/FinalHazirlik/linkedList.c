#include <stdio.h>
#include <stdlib.h>

typedef struct node 
{
    int number;
    struct node *next;
}node;

typedef struct
{
    node *head;
    node *tail;
}list;

node *newNode(int number);
node* addAtTheBeginning(list *list, int number);
node* addAtTheEnd(list *list, int number);
node* addAfter(node *addAfterThisNode, int number);
void removeFromTheEnd(list *list);
void removeFromTheBeginning(list *list);
void removeAfter(node* removeAfterThisNode);
void printList(list *list);
void recPrint(node *head);


int main(void)
{
    list *newList = malloc(sizeof(list));
    newList->head = NULL;
    node* one = addAtTheBeginning(newList, 1);
    node* two = addAtTheEnd(newList, 2);
    recPrint(newList->head);
    printf("\n");
    //removeFromTheEnd(newList);
    recPrint(newList->head);
    printf("\n");
    node* three = addAfter(one, 8);
    recPrint(newList->head);
    printf("\n");
    //removeFromTheBeginning(newList);
    removeAfter(one);
    recPrint(newList->head);
}

node *newNode(int number)
{
    node *new = malloc(sizeof(node));
    new->next = NULL;
    new->number = number;
    return new; 
}

node* addAtTheEnd(list *list, int number)
{
    node *addedNode = newNode(number);
    node *tmp = list->head;
    while (tmp->next != NULL)
    {
        tmp = tmp->next;
    }
    tmp->next = addedNode;
    return addedNode;
}

node* addAtTheBeginning(list *list, int number)
{
    node *addedNode = newNode(number);
    addedNode->next = list->head;
    list->head = addedNode;
    return addedNode;
}

node* addAfter(node *addAfterThisNode, int number)
{
    node *addedNode = newNode(number);
    addedNode->next = addAfterThisNode->next;
    addAfterThisNode->next = addedNode;
}

void removeFromTheEnd(list *list)
{
    node *tmp = list->head;
    while (tmp->next->next != NULL)
    {
        tmp = tmp->next;
    }
    tmp->next = NULL;
}

void removeFromTheBeginning(list *list)
{
    list->head = list->head->next;
}

void removeAfter(node* removeAfterThisNode)
{
    removeAfterThisNode->next = removeAfterThisNode->next->next;
}

void printList(list *list)
{
    for (node *tmp = list->head; tmp != NULL; tmp = tmp->next)
    {
        printf("%i\n", tmp->number);  
    }
}

void recPrint(node *head)
{
    if (head == NULL) printf("\n");
    printf("%d ", head->number);
    recPrint(head->next);
}