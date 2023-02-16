#include <stdio.h>

int binarySearch(int* arr, int start, int end, int target);
void match(int* arr, int startIndex, int endIndex, int sum);

int main(void)
{
    int arr[] = {-5, -4, -3, -1, 0, 0, 2, 3, 4, 5};
    int end = (sizeof(arr) / sizeof(arr[0])) - 1, start = 0, sum;
    printf("Search for: ");
    scanf("%d", &sum);
    match(arr, start, end, sum);
}

int binarySearch(int* arr, int startIndex, int endIndex, int target)
{
    if (startIndex > endIndex) return -1;
    int middleIndex = (startIndex + endIndex)/2;
    if (target == arr[middleIndex])
    {
        return middleIndex;
    }
    else if (target < arr[middleIndex])
    {
        return binarySearch(arr, startIndex, middleIndex-1, target);
    }
    else
    {
        return binarySearch(arr, middleIndex+1, endIndex, target);
    }
}

void match(int* arr, int startIndex, int endIndex, int sum)
{
    int target;
    for (int i = startIndex; i < endIndex + 1; i++)
    {
        target = sum - arr[i];
        int result = binarySearch(arr, i+1, endIndex, target);
        if (result == -1) continue;
        printf("Indices that add up to %d: (%d, %d)\n", sum, i, result);
    }
}

