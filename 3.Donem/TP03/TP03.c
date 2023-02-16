#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

// BST dugum yapisini tanimlayin
struct node {
	int data;
    struct node* left;
    struct node* right;
};

// Yeni dugum yaratma fonksiyonunu yazin
struct node* newNode(int data) {
    struct node* new = (struct node*)malloc(sizeof(struct node));
    new->data = data;
    new->left = NULL;
    new->right = NULL;
    return new;
}

// Agaca rekursif olarak yeni dugum ekleyen fonksiyonu yazin
struct node* insertNode(struct node* n, int data) {
	if (!n)
    {
        return newNode(data);
    }

    if (n->data > data)
    {
        n->left = insertNode(n->left, data);
    }
    else if (n->data <= data) // Buyuk esit olma durumunda yeni eleman bulundugumuz dugumun sag alt agacina eklenir
    {
        n->right = insertNode(n->right, data);
    }
    return n;
}

// Agactaki en dusuk degeri bulup donduren fonksiyonu yazin
int findMin(struct node *tree) {
	if (!tree->left)
    {
        return tree->data; // Bulundugumuz dugumun solu bossa en dusuk deger bulundugumuz degerdir
    }
    return findMin(tree->left); // Agactaki en sol dugume kadar git
}

// Agactaki en buyuk degeri bulup donduren fonksiyonu yazin
int findMax(struct node *tree) {
	if (!tree->right)
    {
        return tree->data; // Bulundugumuz dugumun sagi bossa en buyuk degeri bulundugumuz degerdir
    }
    return findMax(tree->right); // Agactaki en sag dugume kadar git
}

// Agactaki en yuksek degerli dugumun adresini donduren fonksiyonu yazin
struct node* findMaxNode(struct node *tree) {
    if (!tree->right)
    {
        return tree; // Usttekinden farkli olarak data degil adres donduruldu
    }
    return findMaxNode(tree->right);
}

// Agactan rekursif olarak dugum silen fonksiyonu yazin, silinecek dugumun 2 cocugu varsa, silinen dugumu sol alt-agacin maksimum degerli dugumu olarak guncelleyin (https://www.cs.usfca.edu/~galles/visualization/BST.html adresindeki Delete fonksiyonu gibi)
struct node* deleteNode(struct node *tree, int data) {

    if (!tree) return NULL; // Bulundugumuz dugum bossa baska kontrollerle ugrasma, cik gitsin

    // Once silecegimiz degeri agacta aramamiz lazim
        // Silmek istedigimiz deger bulundugumuz dugumdeki degerden kucukse sol alt agaci kontrol et
    if (tree->data > data) tree->left = deleteNode(tree->left, data); 
        // Buyukse sag alt agaci kontrol et
    else if (tree->data < data) tree->right = deleteNode(tree->right, data);
    // Agacta bulunmayan bir deger aranirsa fonksiyon NULL dondurup sonlanir

    // Yani buraya gelindiyse dugum bulunmus demektir

    // Silecegimiz dugumun hic cocugu yoksa hemen siliyoruz
    else if (!tree->right && !tree->left) tree = NULL;

    // Silecegimiz dugumun tek cocugu varsa onu donduruyoruz
    else if (!tree->right) return tree->left;
    else if (!tree->left) return tree->right;

    // Iki cocuk varsa sol cocugumuzun root oldugu alt agacin maksimum degerli dugumu bulunur
    else if (tree->right && tree->left)
    {
        struct node* leftMax = findMaxNode(tree->left);
        tree->data = leftMax->data;
        tree->left = deleteNode(tree->left, leftMax->data);
    }

    // Call stack bittikten sonra yeni agacin rootunu dondurur
    return tree;
}

// Agaci rekursif olarak "in-order" yontemi ile dolasip degerleri ekrana bastiran fonksiyonu yazin
void printTreeInOrder(struct node* tree) {
    if (!tree) return; // Base case
	printTreeInOrder(tree->left);
    printf("%d ", tree->data);
    printTreeInOrder(tree->right);
}

// Agaci rekursif olarak "pre-order" yontemi ile dolasip degerleri ekrana bastiran fonksiyonu yazin
void printTreePreOrder(struct node* tree) {
    if (!tree) return;
	printf("%d ", tree->data);
    printTreePreOrder(tree->left);
    printTreePreOrder(tree->right);
}

// Agaci rekursif olarak "post-order" yontemi ile dolasip degerleri ekrana bastiran fonksiyonu yazin	
void printTreePostOrder(struct node* tree) {
    if (!tree) return;
	printTreePostOrder(tree->left);
    printTreePostOrder(tree->right);
    printf("%d ", tree->data);	
}

// Level-order yontemi icin extra fonksiyonlar
// Rekursif olarak agacin yuksekligini hesaplayan fonksiyon
int findHeight(struct node *tree) {
	if (!tree)
		return 0; // Buradan anlasiliyor ki sadece root olsa height = 1 olurdu.
	else {
		int h_left = findHeight(tree->left);
		int h_right = findHeight(tree->right);
		if (h_left > h_right)
			return (h_left + 1);
		else
			return (h_right + 1);
	}
}

// Rekursif olarak ayni hizadaki dugumleri bastiran fonksiyon
void printLevel(struct node *tree, int level) {
	if (!tree)
		return;
	if (level == 1) // Rootun bulundugu seviye = 1 
		printf("%d ", tree->data);
	else if (level > 1) {
		printLevel(tree->left, level - 1);
		printLevel(tree->right, level - 1);
	}
}

// Yukaridaki iki fonksiyonu kullanarak agaci "level-order" yontemi ile dolasip degerleri ekrana bastiran fonksiyonu yazin	
void printTreeLevelOrder(struct node* tree) {
	int height = findHeight(tree);
    for (int i = 1; i <= height; i++)
    {
        printLevel(tree, i);
    }
}

int main(int argc, char *argv[]) {
	// Copy paste icin: 78 85 56 65 13 79 85 86 43
    if (argc < 2)
    {
        printf("Where is my BST?!?!\n");
        return -1;
    }
    
	
	// Komut satirindan aldiginiz parametreleri kullanarak bir BST tanimlayin ve olusturun
    struct node* root = newNode(atoi(argv[1]));
    for (int i = 2; i < argc; i++)
    {
        root = insertNode(root, atoi(argv[i]));
    }


	// Agaciniza 97 degerli yeni bir dugum ekleyin
	root = insertNode(root, 97);
	
	// Agactaki dugumlerin min ve max degerlerini ekrana bastırın
    printf("\n#########################################\n");
	printf("Minimum: %d\n", findMin(root));
    printf("Maximum: %d\n", findMax(root));
    printf("#########################################\n");

	// Sirayla 85 ve 56 degerli dugumleri silin
	root = deleteNode(root, 85);
    root = deleteNode(root, 56);
	
	// In-order, pre-order, post-order ve level-order yontemleri ile agaci dolasarak dügümlerin degerlerini duzgun bir sekilde ekrana bastirin
    printf("\n#########################################\n");
	printf("In-order: "); printTreeInOrder(root);
    printf("\n#########################################\n");
    printf("Pre-order: "); printTreePreOrder(root);
    printf("\n#########################################\n");
    printf("Post-order: "); printTreePostOrder(root);
    printf("\n#########################################\n");
    printf("Level-order: "); printTreeLevelOrder(root);
    printf("\n#########################################\n");

	
	return 0;
}