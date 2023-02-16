#include <stdio.h>

void swap(int *x, int *y);
int *findMin(int *numList, int index, int size);
void selectionSort(int *numList, int size);
void printArray(int *numList, int size);

int main(void)
{
    int numList[] = {17, 2, 90, 5, 7, 8, 9, 1, 10, 11};
    int size = sizeof(numList) / sizeof(numList[0]);
    selectionSort(numList, size);
    printArray(numList, size);
}

void swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}

int *findMin(int *numList, int index, int size)
{
    if (size == 1) return numList;
    int *min = &numList[index];
    for (int *i = numList + index; i < numList + size; i++)
    {
        if (*i < *min)
        {
            min = i;
        }
    }
    return min;
}

void selectionSort(int *numList, int size)
{
    for (int i = 0; i < size; i++)
    {
        swap(&numList[i], findMin(numList, i, size));
    }
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