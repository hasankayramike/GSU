#include <stdio.h>
#include <stdlib.h>

void sort(int *numList, int lowIndex, int highIndex);
void merge(int *numList, int lowIndex, int highIndex);
void listCopy(int *oldList, int *newList, int highIndex);
void printArray(int *numList, int highIndex);


int main(void)
{
    int numList[] = {17, 2, 90, 5, 7, 21, 8, 9, 1, 10, 11, 0};
    int high = (sizeof(numList) / sizeof(numList[0])) - 1;
    int low = 0;
    sort(numList, low, high);
    printArray(numList, high);
}


void sort(int *numList, int lowIndex, int highIndex)
{
    int midIndex = (int) ((lowIndex + highIndex) / 2); 
    if (lowIndex >= highIndex) return;
    sort(numList, lowIndex, midIndex);
    sort(numList, midIndex + 1, highIndex);
    merge(numList, lowIndex, highIndex);
}

void merge(int *numList, int lowIndex, int highIndex)
{
    int size = highIndex + 1, newList[size];
    listCopy(numList, newList, highIndex);
    for (int k = lowIndex, midIndex  = (int) ((lowIndex + highIndex) / 2), i = lowIndex, j = midIndex + 1; k < size; k++)
    {
        if (i > midIndex) numList[k] = newList[j++];
        else if (j > highIndex) numList[k] = newList[i++];
        else if (newList[i] < newList[j]) numList[k] = newList[i++];
        else numList[k] = newList[j++];
    }
}

void listCopy(int *oldList, int *newList, int highIndex)
{
    int size = highIndex+1;
    for (int i = 0; i < size; i++)
    {
        newList[i] = oldList[i];
    }
}

void printArray(int *numList, int highIndex)
{
    int size = highIndex+1;
    printf("Array: [");
    for (int i = 0; i < size - 1; i++)
    {
        printf("%d, ", numList[i]);
    }
	printf("%d]\n", numList[size-1]);
}