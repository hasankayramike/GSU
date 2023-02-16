#include <stdio.h>

void swap(int *x, int *y);
void sort(int *arr, int size);
void printArray(int *arr, int size);


/*
    (9 5 1 4 3)
    (5 9 1 4 3)
    (5 1 9 4 3) -> (1 5 9 4 3)
    (1 5 4 9 3) -> (1 4 5 9 3)
    (1 4 5 3 9) -> (1 4 3 5 9) -> (1 3 4 5 9) 
*/
int main(void)
{
    int arr[] = {9, 5, 1, 4, 3};
    int size = sizeof(arr)/sizeof(arr[0]);
    printArray(arr, size);
    sort(arr, size);
    printArray(arr, size);
}

void swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}

void sort(int *arr, int size)
{
    if (size == 1) return;
    for (int *i = arr + 1; i < arr + size; i++)
    {
        for (int *j = i; j > arr; j--)
        {
            if (*j > *(j-1)) break;
            swap(j, j - 1);
        }
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