#include <stdio.h>

void insertionSort(int *numList, int size);
void swap(int *x, int *y);
void compare(int *numList, int *start);
void printArray(int *numList, int size);

int main(void)
{
	int numList[] = {17, 2, 90, 5, 7, 8, 9, 1, 10, 11};
    int size = sizeof(numList) / sizeof(numList[0]);
	insertionSort(numList, size);
    printArray(numList, size);
}

void swap(int *x, int *y)
{
	int temp = *x;
	*x = *y;
	*y = temp;
}

void compare(int *numList, int *start)
{
	for (int *j = start; j > numList; j--)
	{
		if (*j > *(j-1)) break;
		swap(j, j-1);
	}
}
void insertionSort(int *numList, int size)
{
	for (int *i = &numList[1]; i < numList + size; i++)
	{
		compare(numList, i);
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