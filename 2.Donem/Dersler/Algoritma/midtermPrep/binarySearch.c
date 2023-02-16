#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int linearSearch(int *numbers, int numSize, int target);
int binarySearch(int *numbers, int startIndex, int endIndex, int target);

int main(void)
{
    srand(time(NULL));
    int numbers[] = {0, 1, 2, 3, 4, 5, 6, 7, 8};
    int target = rand() % 12;
    printf("%d\n", target);
    int index = linearSearch(numbers, 9, target);
    int binaryIndex = binarySearch(numbers, 0, 8, target);
    if (index == -1 || binaryIndex == -1)
    {
        printf("Not Found!\n");
    }
    
    printf("%d, %d\n", index, binaryIndex);
}

int linearSearch(int *numbers, int numSize, int target)
{
    for (int i = 0; i < numSize; i++)
    {
        if (numbers[i] == target)
        {
            return i;
        }
    }
    return -1;
}

int binarySearch(int *numbers, int startIndex, int endIndex, int target)
{

    int midIndex =  (startIndex + endIndex) / 2;
    int midValue = numbers[midIndex];
    if (startIndex > endIndex)
    {
        return -1;
    }
    if (target == midValue)
    {
        return midIndex; 
    }
    if (target > midValue)
    {
        startIndex = midIndex+1;
        return binarySearch(numbers, startIndex, endIndex, target);
    }
    endIndex = midIndex - 1;
    return binarySearch(numbers, startIndex, endIndex, target);
}
