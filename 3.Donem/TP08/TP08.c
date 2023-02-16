#include <stdio.h>
#include <stdlib.h>

// Cizgedeki dugum sayisi
#define SIZE 9


typedef struct minHeapNode {
    int id; // Dugumun cizgedeki indexi.
    int priority; // Dugumun baslangic vertexine uzakligi.
}minHeapNode;

typedef struct minHeap {
    int rear; // Dizideki son elemanin indeksi.
    int size; // Dizinin maksimum boyutu.
    minHeapNode** arr;
}minHeap;

typedef struct graph {
    int size;
    int* visited;
    int* distances; // Her vertexin baslangic vertexine uzakligi.
    int** adjMatrix;
}graph;

// Teker teker elle sehirleri yazmamak icin yaptim.
// Cok da onemli degil.
typedef struct city {
    int code;
    char name[20];
}city;

minHeapNode* createMinHeapNode(int id, int priority);
minHeapNode* extractMin(minHeap* minHeap);
minHeap* createMinHeap(void);
graph* dijkstra(graph* g, int src);
graph* createGraph(int size);
int* bestOption(graph* g1, graph* g2, int from, int to);
int isEmpty(minHeap* minHeap);
int isFull(minHeap* minHeap);
void changePriority(minHeap* minHeap, int index, int newPriority);
void addEdge(graph* g, int ix1, int ix2, int weight);
void insert(minHeap* minHeap, int id, int priority);
void swapNodes(minHeapNode* a, minHeapNode* b);
void minHeapify(minHeap* minHeap, int index);
void bubbleUp(minHeap* minHeap, int index);
void printCostMatrix(graph* g);
void freeMinHeap(minHeap* minHeap);
void freeGraph(graph* g);


int main(void)
{
    city cities[9] = {{1, "Gaziantep"}, {2, "Adana"}, {3, "Izmir"}, {4, "Eskisehir"}, {5, "Ankara"}, {6, "Antalya"}, {7, "Trabzon"}, {8, "Kars"}, {9, "Istanbul"}};

    int from, to;

    printf("Cities:\n");
    for (int i = 0; i < 9; i++)
    {
        printf("%d. %s\n", cities[i].code, cities[i].name);
    }

    printf("\nFrom? (Please enter the city code): ");
    scanf("%d", &from);
    printf("To? (Please enter the city code): ");
    scanf("%d", &to);
    if (from < 1 || from > 9 || to < 1 || to > 9)
    {
        printf("Enter a valid city code!\n");
        return -1;
    }
    
    // index olarak kullanabilmek icin degerlerini birer azalttim
    from--;
    to--;

    graph* g1 = createGraph(SIZE);
    graph* g2 = createGraph(SIZE);

    // Birinci firmanin ucuslari
    addEdge(g1, 0, 1, 10);
    addEdge(g1, 0, 7, 40);
    addEdge(g1, 1, 2, 10);
    addEdge(g1, 1, 8, 30);
    addEdge(g1, 2, 8, 100);
    addEdge(g1, 2, 3, 20);
    addEdge(g1, 2, 4, 100);
    addEdge(g1, 3, 4, 30);
    addEdge(g1, 4, 5, 50);
    addEdge(g1, 4, 8, 30);
    addEdge(g1, 5, 8, 50);
    addEdge(g1, 6, 7, 30);
    addEdge(g1, 6, 8, 70);
    addEdge(g1, 7, 8, 20);

    // Ikinci firmanin ucuslari
    addEdge(g2, 0, 1, 20);
    addEdge(g2, 0, 7, 20);
    addEdge(g2, 1, 2, 40);
    addEdge(g2, 1, 8, 30);
    addEdge(g2, 2, 8, 15);
    addEdge(g2, 2, 3, 30);
    addEdge(g2, 2, 4, 100);
    addEdge(g2, 3, 4, 10);
    addEdge(g2, 4, 5, 30);
    addEdge(g2, 4, 8, 20);
    addEdge(g2, 5, 8, 50);
    addEdge(g2, 6, 7, 60);
    addEdge(g2, 6, 8, 60);
    addEdge(g2, 7, 8, 20);


    printf("1st option (Cost Matrix):\n");
    printCostMatrix(g1);
    printf("2nd option (Cost Matrix):\n");
    printCostMatrix(g2);

    int* result = bestOption(g1, g2, from, to);

    if (result[0] == 1)
    {
        printf("The best option for the flight %s-%s is the first one (%d < %d)\n", cities[from].name, cities[to].name, result[1], result[2]);
    }
    else if (result[0] == 2)
    {
        printf("The best option for the flight %s-%s is the second one (%d < %d)\n", cities[from].name, cities[to].name, result[2], result[1]);
    }

    free(result);
    freeGraph(g1);
    freeGraph(g2);
    return 0;
}

minHeapNode* createMinHeapNode(int id, int priority)
{
    minHeapNode* newNode = malloc(sizeof(minHeapNode));
    newNode->id = id;
    newNode->priority = priority;
    return newNode;
}

minHeap* createMinHeap(void)
{
    minHeap* newHeap = malloc(sizeof(minHeap));
    newHeap->rear = -1; // -1'den baslatiyorum ki dizi bos oldugunda -1, sadece bir eleman oldugunda 0 olsun.
    newHeap->size = SIZE;
    newHeap->arr = malloc(SIZE * sizeof(minHeapNode*));
    return newHeap;
}

int isEmpty(minHeap* minHeap)
{
    if (minHeap->rear == -1) return 1;
    return 0;
}

int isFull(minHeap* minHeap)
{
    if (minHeap->rear == minHeap->size - 1) return 1;
    if (minHeap->rear < minHeap->size - 1) return 0;
    return -1; // Dolup tastiysa -1 dondurur. 0 olmasin yeter.
}

void swapNodes(minHeapNode* a, minHeapNode* b)
{
    minHeapNode* temp = a;
    a = b;
    b = temp; 
}

void minHeapify(minHeap* minHeap, int index)
{
    int smallest = index;
    int left = 2*index + 1;
    if (left <= minHeap->rear && minHeap->arr[left]->priority < minHeap->arr[smallest]->priority)
    {
        smallest = left;
    }
    int right = 2*index + 2;
    if (right <= minHeap->rear && minHeap->arr[right]->priority < minHeap->arr[smallest]->priority)
    {
        smallest = right;
    }
    if (index != smallest)
    {
        swapNodes(minHeap->arr[smallest], minHeap->arr[index]);
        minHeapify(minHeap, smallest);
    }
}

void bubbleUp(minHeap* minHeap, int index)
{
    while (index > 0 && minHeap->arr[index]->priority < minHeap->arr[(index-1)/2]->priority)
    {
        swapNodes(minHeap->arr[index], minHeap->arr[(index-1)/2]);
        index--;
        index /= 2;
    }
}

void insert(minHeap* minHeap, int id, int priority)
{
    if (isFull(minHeap)) return;
    minHeapNode* newNode = createMinHeapNode(id, priority);
    minHeap->arr[++minHeap->rear] = newNode;
    bubbleUp(minHeap, minHeap->rear);
}

minHeapNode* extractMin(minHeap* minHeap)
{
    minHeapNode* min = minHeap->arr[0];
    minHeap->arr[0] = minHeap->arr[minHeap->rear];
    minHeap->size--;
    minHeap->rear--;
    minHeapify(minHeap, 0);
    return min;
}

graph* createGraph(int size) 
{
    graph* newGraph = malloc(sizeof(graph));
    newGraph->size = size;
    newGraph->distances = malloc(size * sizeof(int));
    newGraph->visited = malloc(size * sizeof(int));
    newGraph->adjMatrix = malloc(size * sizeof(int*));

    for (int i = 0; i < size; i++) 
    {
        newGraph->adjMatrix[i] = malloc(size * sizeof(int));
    }

    for (int i = 0; i < size; i++) 
    {
        for (int j = 0; j < size; j++) 
        {
            newGraph->adjMatrix[i][j] = 0;
        }
    }

    return newGraph;
}

void addEdge(graph* g, int ix1, int ix2, int weight)
{
    // Edgelerin yonu yok.
    if (ix1 >= g->size || ix2 >= g->size || ix1 == ix2) return;
    g->adjMatrix[ix1][ix2] = weight;
    g->adjMatrix[ix2][ix1] = weight;
}

graph* dijkstra(graph* g, int src)
{
    // Her vertexin mesafe degiskenini sozde sonsuz yaptim.
    // Hicbir vertex daha once ziyaret edilmedi dedim.
    for (int j = 0; j < SIZE; j++)
    {
        g->visited[j] = 0;
        g->distances[j] = INT_MAX;
    }

    // Baslangic vertexine olan mesafemiz 0, yani ziyaret edildi dedim.
    g->distances[src] = 0;
    g->visited[src] = 1;

    int newDistance, vertex;

    // Bir oncelikli kuyruk olusturdum.
    minHeap* newHeap = createMinHeap();
    // Baslangic vertexini kuyruga iteledim ve onceligini 0 (mesafesi) yaptım.
    insert(newHeap, src, 0);

    // Oncelikli kuyrukta eleman oldugu surece:
    while (!isEmpty(newHeap))
    {
        // En kucuk elemani yeni bir dugume kaydettim.
        minHeapNode* newNode = extractMin(newHeap);
        // En kucuk elemanin cizgedeki indexini yeni bir degiskene atadım.
        vertex = newNode->id;

        // Butun vertexlere baktım. En kucuk elemanin komsularini ariyorum. 
        for (int i = 0; i < SIZE; i++)
        {
            // Bulunan en kucuk elemanla komsu degilse devam ettirdim.
            if (g->adjMatrix[vertex][i] == 0) continue;

            // Komsuyu buldum. Aralarindaki mesafeyi yeni bir degiskene atadim.
            newDistance = g->distances[vertex] + g->adjMatrix[vertex][i];

            // Yeni buldugum mesafe elimde olandan buyukse isime gelmiyor.
            if (newDistance < g->distances[i])
            {
                // Kucukse hemen atamasini yapiyorum.
                g->distances[i] = newDistance;

                // Bu dugumu daha once ziyaret ettiysem bir daha kuyruga eklemiyorum.
                if (g->visited[i] == 1) continue;
                // Etmediysem ekliyorum.
                insert(newHeap, i, newDistance);
            }
            // Sonuc olarak i indexli vertexi ziyaret ettim. Onu kaydediyorum.
            g->visited[i] = 1;
        }
    }

    // Oncelikli kuyrukla isim kalmadi. Hafizadan yolladim.
    freeMinHeap(newHeap);
    return g;
}

void printCostMatrix(graph* g)
{
    printf("  \t1\t2\t3\t4\t5\t6\t7\t8\t9\n");
    printf("  \t--\t--\t--\t--\t--\t--\t--\t--\t--\n");
    for (int i = 0; i < SIZE; i++)
    {
        printf("%d|", i+1);
        g = dijkstra(g, i); 
        for (int j = 0; j < SIZE; j++)
        {
            
            if (j == i) printf("\t-");
            else
            {
                printf("\t%d", g->distances[j]);
            }
        }
        printf("\n");
    }
    printf("\n");
}

int* bestOption(graph* g1, graph* g2, int from, int to)
{
    // result[0]: g1 daha optimalse 1, g2 daha optimalse 2
    // result[1]: g1'deki mesafe
    // result[2]: g2'deki mesafe

    int* result = malloc(3*sizeof(int));
    g1 = dijkstra(g1, from);
    g2 = dijkstra(g2, from);
    result[1] = g1->distances[to];
    result[2] = g2->distances[to];
    if (result[1] <= result[2])
    {
        result[0] = 1;
    }
    else
    {
        result[0] = 2;
    }
    return result;
}

void freeMinHeap(minHeap* minHeap) 
{
    for (int i = 0; i <= minHeap->rear; i++) {
        free(minHeap->arr[i]);
    }
    free(minHeap->arr);
    free(minHeap);
}

void freeGraph(graph* g)
{
    free(g->visited);
    free(g->distances);
    for (int i = 0; i < g->size; i++) {
        free(g->adjMatrix[i]);
    }
    free(g->adjMatrix);
    free(g);
}
