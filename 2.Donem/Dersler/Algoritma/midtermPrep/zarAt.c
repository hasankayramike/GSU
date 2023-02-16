#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void printArray(int *numbers, int numSize);
int rollDice(void);
void fillArray(int *numbers, int numSize);
float meanValue(int *numbers, int numSize);
void frequency(int *numbers, int numSize);
float medianValue(int *numbers, int numSize);
int mod(int *numbers, int numSize);

int main(void)
{
    int numSize = 7;
    int numbers[numSize];
    fillArray(numbers, numSize);
    printArray(numbers, numSize);
    float mean = meanValue(numbers, numSize);
    printf("Mean = %.2f\n", mean);
    frequency(numbers, numSize);
    printArray(numbers, numSize);
    float median = medianValue(numbers, numSize);
    printf("Median = %.2f\n", median);

}

void printArray(int *numbers, int numSize)
{
    for (int i = 0; i < numSize; i++)
    {
        printf("%d ", numbers[i]);
    }
    printf("\n");
}

int rollDice(void)
{
    return 1 + rand() % 6;
}

void fillArray(int *numbers, int numSize)
{
    for (int i = 0; i < numSize; i++)
    {
        numbers[i] = rollDice();
    }
}

float meanValue(int *numbers, int numSize)
{
    int total = 0;
    for (int i = 0; i < numSize; i++)
    {
        total += numbers[i];
    }
    return total / 2;
}

void frequency(int *numbers, int numSize)
{
    int freq[] = {0, 0, 0, 0, 0, 0};
    for (int i = 0; i < numSize; i++)
    {
        freq[numbers[i]-1]++;
    }
    for (int i = 0; i < 6; i++)
    {
        if (freq[i] == 0)
        {
            continue;
        }
        for (int j = freq[i], k = 0; j > 0; j--, k++)
        {
            numbers[k] = i + 1;
        }
        
        
    }
    
    printArray(freq, 6);
}

// {1, 5, 5, 5, 6, 6, 6,}
// {1, 0, 0, 0, 3, 3}

float medianValue(int *numbers, int numSize)
{
    int index = (numSize + 1) / 2;
    return (ceil(numbers[index]) + floor(numbers[index])) / 2;
}


