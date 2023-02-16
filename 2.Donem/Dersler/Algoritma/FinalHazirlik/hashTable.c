#include <stdio.h>

//hash tablosu yarat
#define TABLE_SIZE 6

typedef struct hashtable
{
    int key;
    int value;
} hashtable;

hashtable table[TABLE_SIZE];

//prototipler
int hash(int key);
void putData(hashtable row);
int getData(int key);
void linearProbe(hashtable *table);
void printHashTable(hashtable *table);


int main(void)
{
    linearProbe(table);
    hashtable row1 = {.key = 1, .value = 10};
    hashtable row2 = {.key = 2, .value = 20};
    hashtable row3 = {.key = 3, .value = 30};
    hashtable row4 = {.key = 4, .value = 40};
    hashtable row5 = {.key = 5, .value = 50};
    hashtable row6 = {.key = 6, .value = 60};
    putData(row1);
    putData(row2);
    putData(row3);
    putData(row4);
    putData(row5);
    putData(row6);
    printHashTable(table);
    printf("searched key: %d, found value: %d\n", 2, getData(2));
}

int hash(int key)
{
    return (8*key) % TABLE_SIZE;
}

//hash tablosuna veri koyan fonksiyon
void putData(hashtable row)
{
    int i = hash(row.key);
    if (table[i].key != -1) 
    {
        int lap = 0;
        while (table[i].key != row.key && table[i].key != -1) i++;
        if (i >= TABLE_SIZE)
        {
            if (lap >= 1) // Bir kere tabloyu baştan dön ki boş yerleri doldur. Birden fazla dönemezsin tablo dolu nereye dönüyon
            {
                printf("Hash Table is Full\n");
                return;
            }
            i %= TABLE_SIZE;
            lap++;
        }
    }
    table[i].key = row.key;
    table[i].value = row.value;
}

//hash tablosundan elemana eriş
int getData(int key)
{
    int i = hash(key);
    if (table[i].key != key)
    {
        int lap = 0;
        while (table[i].key != key) i++;
        if (i >= TABLE_SIZE)
        {
            if (lap >= 1)
            {
                printf("Hash Table is Empty\n");
                return -1;
            }
            i %= TABLE_SIZE;
            lap++;
        }
    }
    return table[i].value; 
}

void linearProbe(hashtable *table)
{
    for (int i = 0; i < TABLE_SIZE; i++)
    {
        table[i].key = -1;
    }
    
}

void printHashTable(hashtable *table)
{
    for (int i = 0; i < TABLE_SIZE; i++)
    {
        printf("key: %d, value: %d \n", table[i].key, table[i].value);
    }
}