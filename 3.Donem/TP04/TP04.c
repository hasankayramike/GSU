#include <stdio.h>
#include <stdlib.h>

// Splay tree dugum yapisi
struct node {
	int data;
	struct node *left;
	struct node *right;
};

// Parametre olarak aldigi veri ile yeni dugum yaratip donduren fonksiyon
struct node* createNode(int data) {
	struct node *n = malloc(sizeof(struct node));
	n->data = data;
	n->left = NULL;
	n->right = NULL;
	return n;
}

// Hangi rotation olduguna gore fonksiyonun adini duzeltin
struct node* zagRotate(struct node *n) {
	struct node *temp = n->right;
	n->right = temp->left;
	temp->left = n;
	return temp;
}

// Diger tarafa olan rotation kodunu yazin
struct node* zigRotate(struct node *n) {
	struct node* temp = n->left;
    n->left = temp->right;
    temp->right = n;
    return temp;
}

// Parametre olarak aldigi agacin kokune (root) parametre olarak aldigi yeni veriyi (data) ekleyip agacini guncelleyen ve guncellenmis agacin yeni kokunu donduren fonksiyonu yazin. Aciklamalarinizi yorum satiri olarak eklemeyi unutmayin.
struct node* splay(struct node *root, int data) {
    // Parent pointer kullanmamak icin top-down yontemi
    // Zig-zig zag-zag zig-zag gibi islemler yerine tek seferde bir tane zig ya da bir tane zag yapilir
   
    // Agac uce bolunur: sol alt agac - kok - sag alt agac
    // Istenilen dugum bulunana kadar ustunden gecilen dugumlerin tuttugu degerler
    // istenilen dugumun tuttugu degerle olan esitsizliklerine gore sol veya sag alt agacta tutulurlar
    // Ustunden gecilen ancak bulmaya calistigimiz dugum olmayan dugumler sol ya da sag alt agaca gitmeden 
    // once zig ya da zag islemine tabi tutulurlar


    struct node N, *leftSub, *rightSub;
    if (!root)
    {
        return root;
    }
    N.left = N.right = NULL;
    leftSub = rightSub = &N;
    while(1)
    {
        if (data < root->data)
        {
            if (!root->left) break;
            if (data < root->left->data)
            {
                root = zigRotate(root);
                if (!root->left) break;                
            }
            rightSub->left = root;
            rightSub = root;
            root = root->left;
        }

        else if (data > root->data)
        {
            if (!root->right) break;
            if (data > root->right->data)
            {
                root = zagRotate(root);
                if (!root->right) break;
            }
            leftSub->right = root;
            leftSub = root;
            root = root->right;
        }
        else break;
    }
 
    leftSub->right = root->left; 
    rightSub->left = root->right;
    root->left = N.right;
    root->right = N.left;
    return root;
}

// Parametre olarak aldigi splay agaci kokune (root) parametre olarak aldigi veriyi (data) ekleyip yeni agacin kokunu donduren fonksiyon. Aciklamalarinizi yorum satiri olarak eklemeyi unutmayin.
struct node* insertNode(struct node *root, int data) {
    // Once eklemek istedigimiz dugumu olusturuyoruz
    // Agac bossa yeni elemanimizi kok olarak donduruyoruz
    // Agacta en az bir eleman bulunuyorsa sanki elemanimiz agacta varmis gibi splay atiyoruz
    // Boylece yeni elemanin eklenmesinin en uygun oldugu dugum en uste gelmis oluyor
    // Eklemek istedigimiz elemani direkt kok olarak atiyoruz
    // ve bu eleman ile en yukari cikardigimiz dugumdeki elemanin esitsizliklerine gore
    // alt agaclarin atamasi gerceklesiyor

    struct node* newItem = createNode(data);
    if (!root)
    {
        return newItem;
    }

	root = splay(root, data);

    if (data < root->data)
    {
        newItem->left = root->left;
        newItem->right = root;
        root->left = NULL;
        return newItem;
    }
    else if (data > root->data) 
    {
        newItem->right = root->right;
        newItem->left = root;
        root->right = NULL;
        return newItem;
    }
    else
    {
        free(newItem);
        return root;
    }    
}


// Agaci rekursif olarak "pre-order" yontemi ile dolasip degerleri ekrana bastiran fonksiyon
void printTreePreOrder(struct node *tree) {
	if (tree) {
		printf("%d ", tree->data);
		printTreePreOrder(tree->left);
		printTreePreOrder(tree->right);
	}
}

int main(int argc, char *argv[]) {
    if (argc < 2)
    {
        printf("Where is my splay!!!\n");
        return -1;
    }

    struct node* root = NULL;
    for (int i = 1; i < argc; i++)
    {
        root = insertNode(root, atoi(argv[i]));
        printTreePreOrder(root);
        printf("\n");
    }
	return 0;
}
