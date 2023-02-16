#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "TP02.h"

int main(void)
{
    char dataType[2], operation[2] = "1";
    int newElement;
    printf("a) Stack Array\nb) Stack Linked List\n");
    printf("c) Queue Array\nd) Queue Linked List\n");
    printf(">>> "); scanf("%s", dataType);
    switch (tolower(dataType[0]))
    {
        case 'a':;
            stackArr* SA = createStackArray();
            while (operation[0] == '1' || operation[0] == '2' || operation[0] == '3' || operation[0] == '4')
            {
                printf("1) Push\n2) Pop\n3) Print Stack\n4) Clear Stack\n");
                printf("Any other key to quit\n");
                printf(">>> "); scanf("%s", operation);
                switch (operation[0])
                {
                    case '1':
                        printf("Integer to push: ");
                        scanf("%d", &newElement);
                        pushStackArray(SA, newElement);
                        break;
                    case '2':
                        popStackArray(SA);
                        break;
                    case '3':
                        printStackArray(SA);
                        break;
                    case '4':
                        clearStackArray(SA);
                        break;
                    default:
                        printf("Exiting...\n");
                        break;
                }
            }
            free(SA);
            break;
        case 'b':;
            stackSL* SL = createStackList();
            while (operation[0] == '1' || operation[0] == '2' || operation[0] == '3' || operation[0] == '4')
            {
                printf("1) Push\n2) Pop\n3) Print Stack\n4) Clear Stack\n");
                printf("Any other key to quit\n");
                printf(">>> "); scanf("%s", operation);
                switch (operation[0])
                {
                    case '1':
                        printf("Integer to push: ");
                        scanf("%d", &newElement);
                        pushStackList(SL, newElement);
                        break;
                    case '2':
                        popStackList(SL);
                        break;
                    case '3':
                        printStackList(SL);
                        break;
                    case '4':
                        clearStackList(SL);
                        break;
                    default:
                        printf("Exiting...\n");
                        break;
                }
            }
            free(SL);
            break;
        case 'c':;
            queueArr* QA = createQueueArray();
            while (operation[0] == '1' || operation[0] == '2' || operation[0] == '3' || operation[0] == '4')
            {
                printf("1) Enqueue\n2) Dequeue\n3) Print Queue\n4) Clear Queue\n");
                printf("Any other key to quit\n");
                printf(">>> "); scanf("%s", operation);
                switch (operation[0])
                {
                    case '1':
                        printf("Integer to enqueue: ");
                        scanf("%d", &newElement);
                        enqueueArray(QA, newElement);
                        break;
                    case '2':
                        dequeueArray(QA);
                        break;
                    case '3':
                        printQueueArray(QA);
                        break;
                    case '4':
                        clearQueueArray(QA);
                        break;
                    default:
                        printf("Exiting...\n");
                        break;
                }
            }
            free(QA);
            break;
        case 'd':;
            queueSL* QL = createQueueList();
            while (operation[0] == '1' || operation[0] == '2' || operation[0] == '3' || operation[0] == '4')
            {
                printf("1) Enqueue\n2) Dequeue\n3) Print Queue\n4) Clear Queue\n");
                printf("Any other key to quit\n");
                printf(">>> "); scanf("%s", operation);
                switch (operation[0])
                {
                    case '1':
                        printf("Integer to enqueue: ");
                        scanf("%d", &newElement);
                        enqueueList(QL, newElement);
                        break;
                    case '2':
                        dequeueList(QL);
                        break;
                    case '3':
                        printQueueList(QL);
                        break;
                    case '4':
                        clearQueueList(QL);
                        break;
                    default:
                        printf("Exiting...\n");
                        break;
                }
            }
            free(QL);
            break;
        default:
            printf("Invalid command!\n");
            printf("Exiting...\n");
            break;
    }

}