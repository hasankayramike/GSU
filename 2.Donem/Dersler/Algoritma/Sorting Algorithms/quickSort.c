#include <stdio.h>

void reArrange(int *numList, int size);
void swap(int *x, int *y);
int *assignPointer(int *numList, int size, int *secondPointer);
void printArray(int *numList, int size);

int main(void)
{
    int numList[] = {17, 2, 90, 5, 7, 8, 9, 1, 10, 11};
    reArrange(numList, 10);
    printArray(numList, 10);
    return 0;
}

void reArrange(int *numList, int size)
{
    //               17, 2, 90, 5, 7, 8, 9, 1, 10, 11
    int *pivot = &numList[size-1];
    int *secondPointer;
    for (int *i = assignPointer(numList, size, secondPointer) + 1; i < size + numList; i++)
    {
        if (*i < *pivot)
        {
            swap(i, secondPointer);
            break;
        }
    }
}

int *assignPointer(int *numList, int size, int *secondPointer)
{
    int *pivot = &numList[size-1];
    for (int i = 0; i < size; i++)
    {
        if (numList[i] > *pivot) 
        {
            secondPointer = &numList[i];
            return secondPointer;
        }
    }
}

void swap(int *x, int *y)
{
	int temp = *x;
	*x = *y;
	*y = temp;
}

void printArray(int *numList, int size)
{
    printf("Array: [");
    for (int i = 0; i < size - 1; i++)
    {
        printf("%d, ", numList[i]);
    }
	printf("%d]\n", numList[size-1]);
}