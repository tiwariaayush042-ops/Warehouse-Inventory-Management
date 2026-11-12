
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

typedef struct BSTNode {
    Product data;
    struct BSTNode *left, *right;
} BSTNode;

int comparisons = 0;

BSTNode* createNode(Product p) {
    BSTNode *newNode = (BSTNode*)malloc(sizeof(BSTNode));

    if (newNode == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }

    newNode->data = p;
    newNode->left = newNode->right = NULL;

    return newNode;
}

BSTNode* insert(BSTNode *root, Product p) {
    if (root == NULL)
        return createNode(p);

    if (p.id < root->data.id)
        root->left = insert(root->left, p);

    else if (p.id > root->data.id)
        root->right = insert(root->right, p);

    else
        printf("Duplicate Product ID: %d\n", p.id);

    return root;
}

BSTNode* search(BSTNode *root, int key) {
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

void inorder(BSTNode *root) {
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

int height(BSTNode *root) {
    if (root == NULL)
        return 0;

    int leftHeight = height(root->left);
    int rightHeight = height(root->right);

    return 1 + (leftHeight > rightHeight ?
                leftHeight : rightHeight);
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
    BSTNode *root = NULL;

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

    printf("\n--- BST INORDER TRAVERSAL ---\n");
    inorder(root);

    printf("\nBST Height: %d\n", height(root));

    // Successful search
    int key = 175;
    comparisons = 0;

    BSTNode *result = search(root, key);

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

    printf("\nUpdated BST Height: %d\n", height(root));

    return 0;
}
