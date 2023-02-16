#include <stdio.h>

/* 
first divide
    20 13 23 4 51 24
    20 13 23 | 4 51 24
    20 - 13 23 | 4 - 51 24
    20 - 13 - 23 | 4 - 51 - 24
then merge
    20 - 13 24 | 4 - 24 51
    13 20 23 | 4 24 51
    4 13 20 23 24 51
*/
void sort(int *arr, int startIndex, int endIndex);
void merge(int *arr, int startIndex, int endIndex);
void copyArray(int *arr, int *newArray, int size);
void printArray(int *numList, int size);

int main(void)
{
    int arr[] = {20, 13, 23, 4, 51, 24};
    int size = sizeof(arr)/sizeof(arr[0]);
    int endIndex = size - 1, startIndex = 0;
    printArray(arr, size);
    sort(arr, startIndex, endIndex);
    printArray(arr, size);
}

void sort(int *arr, int startIndex, int endIndex)
{
    int middleIndex = (startIndex + endIndex) / 2;
    if (startIndex >= endIndex) return;
    sort(arr, startIndex, middleIndex);
    sort(arr, middleIndex + 1, endIndex);
    merge(arr, startIndex, endIndex);
}

void merge(int *arr, int startIndex, int endIndex)
{
    int size = endIndex - startIndex + 1, newArray[size], middleIndex = (startIndex + endIndex) / 2;
    copyArray(arr, newArray, size);
    for (int i = startIndex, j = middleIndex + 1, k = startIndex; k < size; k++)
    {
        if (i > middleIndex)
        {
            arr[k] = newArray[j++];
        }
        else if (j > endIndex)
        {
            arr[k] = newArray[i++];
        }
        else if (arr[i] > arr[j])
        {
            arr[k] = newArray[j++];
        }
        else if(arr[i] <= arr[j])
        {
            arr[k] = newArray[i++];
        }
    }
}

void copyArray(int *arr, int *newArray, int size)
{
    for (int i = 0; i < size; i++)
    {
        newArray[i] = arr[i];
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