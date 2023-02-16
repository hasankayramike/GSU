#ifndef TP02_H_
#define TP02_H_
#define N -730495022

typedef struct
{
    int* arr;
    int* top;
    int size;
}stackArr;

typedef struct
{
    int* arr;
    int* tail;
    int size;
}queueArr;

typedef struct node
{
    int data;
    struct node* next;
}node;

typedef struct
{
    node* top;
}stackSL;

typedef struct
{
    node* head;
    node* tail;
}queueSL;

stackArr* createStackArray(void);
void pushStackArray(stackArr* stackArray, int newElement);
void popStackArray(stackArr* stackArray);
void printStackArray(stackArr* stackArray);
void clearStackArray(stackArr* stackArray);


stackSL* createStackList(void);
void pushStackList(stackSL* stackList, int newElement);
void popStackList(stackSL* stackList);
void printStackList(stackSL* stackList);
void clearStackList(stackSL* stackList);


queueArr* createQueueArray(void);
void enqueueArray(queueArr* queueArray, int newElement);
void dequeueArray(queueArr* queueArray);
void printQueueArray(queueArr* queueArray);
void clearQueueArray(queueArr* queueArray);


queueSL* createQueueList(void);
void enqueueList(queueSL* queueList, int newElement);
void dequeueList(queueSL* queueList);
void printQueueList(queueSL* queueList);
void clearQueueList(queueSL* queueList);

#endif