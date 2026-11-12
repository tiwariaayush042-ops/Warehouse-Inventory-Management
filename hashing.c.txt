
#include <stdio.h>
#include <string.h>

#define TABLE_SIZE 53

typedef struct {
    int id;
    char name[50];
    char category[30];
    float price;
    int quantity;
} Product;

typedef struct {
    Product data;
    int occupied;
} HashEntry;

HashEntry hashTable[TABLE_SIZE];

int totalCollisions = 0;
int comparisons = 0;

int hashFunction(int key) {
    return key % TABLE_SIZE;
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

// Insert using Linear Probing
void insert(Product p) {

    int index = hashFunction(p.id);
    int start = index;

    while (hashTable[index].occupied) {

        // Check duplicate ID
        if (hashTable[index].data.id == p.id) {
            printf("Duplicate Product ID: %d\n", p.id);
            return;
        }

        // Collision occurred
        totalCollisions++;

        index = (index + 1) % TABLE_SIZE;

        // Check whether table is full
        if (index == start) {
            printf("Hash Table is Full!\n");
            return;
        }
    }

    hashTable[index].data = p;
    hashTable[index].occupied = 1;

    printf("Product %d inserted at index %d\n",
           p.id, index);
}

// Search using Linear Probing
int search(int key) {

    int index = hashFunction(key);
    int start = index;

    comparisons = 0;

    while (hashTable[index].occupied) {

        comparisons++;

        if (hashTable[index].data.id == key)
            return index;

        index = (index + 1) % TABLE_SIZE;

        if (index == start)
            break;
    }

    return -1;
}

// Display Hash Table
void display() {

    printf("\n--- HASH TABLE ---\n");

    for (int i = 0; i < TABLE_SIZE; i++) {

        if (hashTable[i].occupied) {
            printf("Index %d: ID=%d Name=%s\n",
                   i,
                   hashTable[i].data.id,
                   hashTable[i].data.name);
        }
    }
}

int main() {

    int ids[] = {
        105,120,115,130,110,125,140,135,150,145,
        160,155,170,165,180,175,190,185,200,195,
        210,205,220,215,230,225,240,235,250,245,
        260,255,270,265,280,275,290,285,300,295
    };

    int n = sizeof(ids) / sizeof(ids[0]);

    // Initialize hash table
    for (int i = 0; i < TABLE_SIZE; i++)
        hashTable[i].occupied = 0;

    // Insert 40 products
    printf("--- INSERTING PRODUCTS ---\n");

    for (int i = 0; i < n; i++) {
        Product p = makeProduct(ids[i], "Product");
        insert(p);
    }

    display();

    printf("\nTotal Hash Collisions: %d\n",
           totalCollisions);

    // Successful search
    int key = 175;

    int result = search(key);

    printf("\nSearching Product ID %d\n", key);

    if (result != -1) {
        printf("Product Found at Index %d\n", result);
        printf("Product Name: %s\n",
               hashTable[result].data.name);
    }
    else {
        printf("Product Not Found\n");
    }

    printf("Search Comparisons: %d\n", comparisons);

    // Unsuccessful search
    key = 999;

    result = search(key);

    printf("\nSearching Product ID %d\n", key);

    if (result != -1)
        printf("Product Found\n");
    else
        printf("Product Not Found\n");

    printf("Search Comparisons: %d\n", comparisons);

    // Additional insertion
    printf("\n--- ADDITIONAL INSERTION ---\n");

    Product newProduct = makeProduct(305, "NewProduct");
    insert(newProduct);

    display();

    printf("\nUpdated Total Collisions: %d\n",
           totalCollisions);

    return 0;
}
