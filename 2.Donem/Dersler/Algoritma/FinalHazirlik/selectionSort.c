#include <stdio.h>


int *findMin(int *arr, int size, int startIndex);
void swap(int *x, int *y);
void sort(int *arr, int size);
void printArray(int *arr, int size);


int main(void)
{
    int arr[] = {20, 13, 23, 4, 51, 24};
    int size = sizeof(arr)/sizeof(arr[0]);
    printArray(arr, size);
    sort(arr, size);
    printArray(arr, size);
}

int *findMin(int *arr, int size, int startIndex)
{
    if (size == 1) return arr;
    int *min = arr + startIndex;
    for (int *i = arr + startIndex + 1; i < arr + size; i++)
    {
        if (*i >= *min) continue;
        min = i;
    }
    return min;
}

void swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}

void sort(int *arr, int size)
{
    for (int *i = arr; i < arr + size; i++)
    {
        int startIndex = i - arr; 
        int* minElement = findMin(arr, size, startIndex);
        swap(i, minElement);
    }
}

void printArray(int *arr, int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}