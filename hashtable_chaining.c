#include <stdio.h>
#include <stdlib.h>

// Node structure for linked list
typedef struct Node
{
    int key;
    int value;
    struct Node *next;
} Node;

// Hash table structure
typedef struct HashTable
{
    int size;
    Node **table;
} HashTable;

// Initialize hash table
void initializeHashTable(HashTable *hashTable, int size)
{
    hashTable->size = size;
    hashTable->table = (Node **)malloc(size * sizeof(Node *));
    // Initialize each slot to NULL
    for (int i = 0; i < size; i++)
    {
        hashTable->table[i] = NULL;
    }
}

// Custom mapping function (simple modulo)
int hashFunction(int key, int size)
{
    return key % size;
}

// Insert key-value pair into hash table
void insertElement(HashTable *hashTable, int key, int value)
{
    int index = hashFunction(key, hashTable->size);
    // Create a new node
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->key = key;
    newNode->value = value;
    newNode->next = NULL;
    // Handle collision: chaining
    if (hashTable->table[index] == NULL)
    {
        // No collision, insert at the beginning
        hashTable->table[index] = newNode;
    }
    else
    {
        // Collision, append to the linked list
        Node *current = hashTable->table[index];
        while (current->next != NULL)
        {
            current = current->next;
        }
        current->next = newNode;
    }
}

// Search for key in hash table
Node *searchElement(HashTable *hashTable, int key)
{
    int index = hashFunction(key, hashTable->size);
    // Search in the linked list at the computed index
    Node *current = hashTable->table[index];
    while (current != NULL)
    {
        if (current->key == key)
        {
            return current; // Key found
        }
        current = current->next;
    }
    return NULL; // Key not found
}

// Display the contents of the hash table
void displayHashTable(HashTable *hashTable)
{
    for (int i = 0; i < hashTable->size; i++)
    {
        printf("Slot %d: ", i);
        Node *current = hashTable->table[i];
        while (current != NULL)
        {
            printf("(%d, %d) ", current->key, current->value);
            current = current->next;
        }
        printf("\n");
    }
}

void main()
{
    HashTable hashTable;
    initializeHashTable(&hashTable, 10);
    insertElement(&hashTable, 5, 10);
    insertElement(&hashTable, 15, 20);
    insertElement(&hashTable, 25, 30);
    insertElement(&hashTable, 35, 40);
    // Display the hash table
    printf("Initial Hash Table:\n");
    displayHashTable(&hashTable);
    // Search for a key
    int keyToSearch = 15;
    Node *result = searchElement(&hashTable, keyToSearch);
    if (result != NULL)
    {
        printf("Key %d found. Value: %d\n", keyToSearch, result->value);
    }
    else
    {
        printf("Key %d not found.\n", keyToSearch);
    }
}
