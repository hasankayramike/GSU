#include <stdio.h>
#include <stdlib.h>


void swap(int *a, int *b);
void shuffle(int *arr, int size);
int partition(int *arr, int startIndex, int endIndex);
void quicksort(int *arr, int startIndex, int endIndex);
void printArray(int *numList, int size);


int main(void)
{
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 9, 8};
    int size = sizeof(arr)/sizeof(arr[0]), endIndex = size - 1;
    shuffle(arr, size);
    quicksort(arr, 0, endIndex);
    printArray(arr, size);
}


void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}


void shuffle(int *arr, int size)
{
    for (int i = 0; i < size; i++)
    {
        int r = rand() % (size - i);
        swap(&arr[i], &arr[r]);
    }
}


int partition(int *arr, int startIndex, int endIndex)
{
    int *pivot = arr + endIndex, size = endIndex + 1, i = startIndex-1;
    for (int j = startIndex; j < size; j++)
    {
        if (arr[j] > *pivot) continue;
        swap(&arr[++i], &arr[j]);
    }
    return i;
}

void quicksort(int *arr, int startIndex, int endIndex)
{
    int pivotIndex = partition(arr, startIndex, endIndex);
    if (startIndex >= endIndex) return;
    quicksort(arr, startIndex, pivotIndex - 1);
    quicksort(arr, pivotIndex + 1, endIndex);
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