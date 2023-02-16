#include <stdio.h>
#include <stdlib.h>
#include "TP02.h"

stackArr* createStackArray(void)
{
    stackArr* newStack = (stackArr*)malloc(sizeof(stackArr));
    newStack->size = sizeof(int);
    newStack->arr = (int*)malloc(sizeof(int));
    newStack->top = newStack->arr;
    return newStack;
}

void pushStackArray(stackArr* stackArray, int newElement)
{
    stackArray->size += sizeof(int);
    stackArray->arr = (int*)realloc(stackArray->arr, stackArray->size);
    *(stackArray->top) = newElement;
    stackArray->top++;
}

void popStackArray(stackArr* stackArray)
{
    if (stackArray->size <= 2*sizeof(int))
    {
        clearStackArray(stackArray);
        return;
    }
    
    stackArray->size -= sizeof(int);
    stackArray->top--;
    stackArray->top = NULL;
    stackArray->arr = (int*)realloc(stackArray->arr, stackArray->size);
    stackArray->top = stackArray->size / sizeof(int) + stackArray->arr;
}

void printStackArray(stackArr* stackArray)
{
    if (stackArray->size <= sizeof(int))
    {
        printf("\n#####################\n");
        printf("Stack is empty!\n");
        printf("#####################\n");
        return;
    }
    
    int len = stackArray->size / sizeof(int);
    printf("\n#####################\n");
    for (int i = len - 2; i >= 0; i--)
    {
        printf("En ustten en alta: %d\n", *(stackArray->arr + i));
    }
    printf("#####################\n");

}

void clearStackArray(stackArr* stackArray)
{
    free(stackArray);
    stackArray = createStackArray();
}



stackSL* createStackList(void)
{
    stackSL* newStack = (stackSL *)malloc(sizeof(stackSL));
    newStack->top = (node*)malloc(sizeof(node));
    newStack->top->next = NULL;

        // Buradaki ilk deger atamasi program kendiliginden atama yapmasin diye var
        // Push fonksiyonunda bu durum kontrol edilerek ilk deger atamasi istenilen
        // Veri ile tekrar gerceklestiriliyor
    newStack->top->data = N; 
    return newStack;
}

void pushStackList(stackSL* stackList, int newElement)
{
    if (stackList->top->next == NULL && stackList->top->data == N)
    {
        stackList->top->data = newElement;
        return;
    }
    
    node* newNode = (node*)malloc(sizeof(node));
    newNode->data = newElement;
    newNode->next = stackList->top;
    stackList->top = newNode;
}

void popStackList(stackSL* stackList)
{
    if (!stackList->top) return;
    if (stackList->top->next == NULL)
    {
        clearStackList(stackList);
        return;    
    }
    node* toPop = stackList->top;
    stackList->top = toPop->next;
    free(toPop);
}

void printStackList(stackSL* stackList)
{
    if (stackList->top == NULL || (stackList->top->next == NULL && stackList->top->data == N))
    {
        printf("\n#####################\n");
        printf("Stack is empty!\n");
        printf("#####################\n");
        return;
    }

    printf("\n#####################\n");
    for (node* tmp = stackList->top; tmp != NULL; tmp = tmp->next)
    {
        printf("En ustten en alta: %d\n", tmp->data);
    }
    printf("#####################\n");
}

void clearStackList(stackSL* stackList)
{
    free(stackList);
    stackList = createStackList();
}

queueArr* createQueueArray(void)
{
    queueArr* newQueue = (queueArr*)malloc(sizeof(queueArr));
    newQueue->size = sizeof(int);
    newQueue->arr = (int*)malloc(sizeof(int));
    newQueue->tail = newQueue->arr;
    return newQueue;
}

void enqueueArray(queueArr* queueArray, int newElement)
{
    queueArray->size += sizeof(int);
    queueArray->arr = (int*)realloc(queueArray->arr, queueArray->size);
    *(queueArray->tail) = newElement;
    queueArray->tail++;
}

void dequeueArray(queueArr* queueArray)
{
    if (queueArray->size <= 2*sizeof(int))
    {
        clearQueueArray(queueArray);
        return;
    }
    int* tmp = queueArray->arr;
    queueArray->arr++;
    queueArray->size -= sizeof(int);
}

void printQueueArray(queueArr* queueArray)
{
    if (queueArray->size <= sizeof(int))
    {
        printf("\n#####################\n");
        printf("Queue is empty!\n");
        printf("#####################\n");
        return;
    }

    int len = queueArray->size / sizeof(int);
    printf("#############################\n");
    for (int i = 0; i < len - 1; i++)
    {
        printf("Ilk girenden son girene: %d\n", *(queueArray->arr + i));
    }
    printf("#############################\n");
}

void clearQueueArray(queueArr* queueArray)
{
    free(queueArray);
    queueArray = createQueueArray();
}

queueSL* createQueueList(void)
{
    queueSL* newQueue = (queueSL*)malloc(sizeof(queueSL));
    newQueue->head = (node*)malloc(sizeof(node));
    newQueue->head->next = NULL;
    newQueue->head->data = N;
    newQueue->tail = newQueue->head;
    return newQueue;
}

void enqueueList(queueSL* queueList, int newElement)
{
    if (queueList->head == NULL || (queueList->head->data == N && queueList->head->next == NULL))
    {
        queueList->head->data = newElement;
        return;
    }

    node* newNode = (node*)malloc(sizeof(node));
    newNode->data = newElement;
    newNode->next = NULL;
    queueList->tail->next = newNode;
    queueList->tail = newNode;
}

void dequeueList(queueSL* queueList)
{
    if (!queueList->head) return;
    if (queueList->head->next == NULL)
    {
        clearQueueList(queueList);
        return;
    }
    node* toDelete = queueList->head;
    queueList->head = toDelete->next;
    free(toDelete);
}

void printQueueList(queueSL* queueList)
{
    if (queueList->head == NULL ||queueList->head->data == N && queueList->head->next == NULL)
    {
        printf("\n#####################\n");
        printf("Queue is empty!\n");
        printf("#####################\n");
        return;        
    }
    
    printf("\n#############################\n");
    for (node* tmp = queueList->head; tmp != NULL; tmp = tmp->next)
    {
        printf("Ilk girenden son girene: %d\n", tmp->data);
    }
    printf("#############################\n");

}

void clearQueueList(queueSL* queueList)
{
    free(queueList);
    queueList = createQueueList();
}
