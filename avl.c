
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int id;
    char name[50];
    char category[30];
    float price;
    int quantity;
} Product;

typedef struct AVLNode {
    Product data;
    struct AVLNode *left, *right;
    int height;
} AVLNode;

int comparisons = 0;

int max(int a, int b) {
    return (a > b) ? a : b;
}

int getHeight(AVLNode *node) {
    return (node == NULL) ? 0 : node->height;
}

int getBalance(AVLNode *node) {
    if (node == NULL)
        return 0;

    return getHeight(node->left) -
           getHeight(node->right);
}

AVLNode* createNode(Product p) {
    AVLNode *node = (AVLNode*)malloc(sizeof(AVLNode));

    if (node == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }

    node->data = p;
    node->left = node->right = NULL;
    node->height = 1;

    return node;
}

// Right rotation (LL case)
AVLNode* rightRotate(AVLNode *y) {
    AVLNode *x = y->left;
    AVLNode *T2 = x->right;

    x->right = y;
    y->left = T2;

    y->height = 1 + max(getHeight(y->left),
                        getHeight(y->right));

    x->height = 1 + max(getHeight(x->left),
                        getHeight(x->right));

    return x;
}

// Left rotation (RR case)
AVLNode* leftRotate(AVLNode *x) {
    AVLNode *y = x->right;
    AVLNode *T2 = y->left;

    y->left = x;
    x->right = T2;

    x->height = 1 + max(getHeight(x->left),
                        getHeight(x->right));

    y->height = 1 + max(getHeight(y->left),
                        getHeight(y->right));

    return y;
}

AVLNode* insert(AVLNode *node, Product p) {

    // Normal BST insertion
    if (node == NULL)
        return createNode(p);

    if (p.id < node->data.id)
        node->left = insert(node->left, p);

    else if (p.id > node->data.id)
        node->right = insert(node->right, p);

    else {
        printf("Duplicate Product ID: %d\n", p.id);
        return node;
    }

    // Update height
    node->height = 1 + max(getHeight(node->left),
                           getHeight(node->right));

    int balance = getBalance(node);

    // LL Case
    if (balance > 1 && p.id < node->left->data.id)
        return rightRotate(node);

    // RR Case
    if (balance < -1 && p.id > node->right->data.id)
        return leftRotate(node);

    // LR Case
    if (balance > 1 && p.id > node->left->data.id) {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }

    // RL Case
    if (balance < -1 && p.id < node->right->data.id) {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

    return node;
}

AVLNode* search(AVLNode *root, int key) {

    while (root != NULL) {
        comparisons++;

        if (key == root->data.id)
            return root;

        else if (key < root->data.id)
            root = root->left;

        else
            root = root->right;
    }

    return NULL;
}

void inorder(AVLNode *root) {
    if (root != NULL) {
        inorder(root->left);

        printf("ID: %d | Name: %s | Category: %s | "
               "Price: %.2f | Quantity: %d\n",
               root->data.id,
               root->data.name,
               root->data.category,
               root->data.price,
               root->data.quantity);

        inorder(root->right);
    }
}

Product makeProduct(int id, const char *name) {
    Product p;

    p.id = id;
    snprintf(p.name, sizeof(p.name), "%s", name);
    strcpy(p.category, "Electronics");
    p.price = 500.0 + id;
    p.quantity = 20;

    return p;
}

int main() {
    AVLNode *root = NULL;

    int ids[] = {
        105,120,115,130,110,125,140,135,150,145,
        160,155,170,165,180,175,190,185,200,195,
        210,205,220,215,230,225,240,235,250,245,
        260,255,270,265,280,275,290,285,300,295
    };

    int n = sizeof(ids) / sizeof(ids[0]);

    // Insert 40 products
    for (int i = 0; i < n; i++) {
        Product p = makeProduct(ids[i], "Product");
        root = insert(root, p);
    }

    printf("\n--- AVL INORDER TRAVERSAL ---\n");
    inorder(root);

    printf("\nAVL Tree Height: %d\n", getHeight(root));

    // Successful search
    int key = 175;
    comparisons = 0;

    AVLNode *result = search(root, key);

    printf("\nSearching Product ID %d\n", key);

    if (result != NULL)
        printf("Product Found: %s\n", result->data.name);
    else
        printf("Product Not Found\n");

    printf("Search Comparisons: %d\n", comparisons);

    // Unsuccessful search
    key = 999;
    comparisons = 0;

    result = search(root, key);

    printf("\nSearching Product ID %d\n", key);

    if (result != NULL)
        printf("Product Found\n");
    else
        printf("Product Not Found\n");

    printf("Search Comparisons: %d\n", comparisons);

    // Additional insertion
    Product newProduct = makeProduct(305, "NewProduct");
    root = insert(root, newProduct);

    printf("\nAfter inserting Product ID 305:\n");
    inorder(root);

    printf("\nUpdated AVL Height: %d\n", getHeight(root));

    return 0;
}
