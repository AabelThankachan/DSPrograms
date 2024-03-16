#include <stdio.h>
#include <stdlib.h>

// Hash table structure
typedef struct HashTable
{
    int size;
    int *keys;
    int *values;
} HashTable;

// Initialize hash table
void initializeHashTable(HashTable *hashTable, int size)
{
    hashTable->size = size;
    hashTable->keys = (int *)malloc(size * sizeof(int));
    hashTable->values = (int *)malloc(size * sizeof(int));
    // Initialize each slot to -1 (indicating empty slot)
    for (int i = 0; i < size; i++)
    {
        hashTable->keys[i] = -1;
        hashTable->values[i] = -1;
    }
}

// Custom mapping function (simple modulo)
int hashFunction(int key, int size)
{
    return key % size;
}

// Resolve collision using linear probing
int resolveCollision(HashTable *hashTable, int index)
{
    int i = 1;
    while (hashTable->keys[index] != -1)
    {
        index = (index + i) % hashTable->size;
    }
    return index;
}

// Insert key-value pair into hash table using linear probing
void insertElement(HashTable *hashTable, int key, int value)
{
    int index = hashFunction(key, hashTable->size);
    // Handle collision: linear probing
    if (hashTable->keys[index] != -1)
    {
        index = resolveCollision(hashTable, index);
    }
    // Insert key and value at the computed index
    hashTable->keys[index] = key;
    hashTable->values[index] = value;
}

// Search for key in hash table using linear probing
int searchElement(HashTable *hashTable, int key)
{
    int index = hashFunction(key, hashTable->size);
    int initialIndex = index;
    // Search for key or empty slot using linear probing
    while (hashTable->keys[index] != -1)
    {
        if (hashTable->keys[index] == key)
        {
            return index; // Key found
        }
        index = (index + 1) % hashTable->size;
        // Stop if we have completed one loop (indicating key not found)
        if (index == initialIndex)
        {
            break;
        }
    }
    return -1; // Key not found
}

// Display the contents of the hash table
void displayHashTable(HashTable *hashTable)
{
    for (int i = 0; i < hashTable->size; i++)
    {
        if (hashTable->keys[i] != -1)
        {
            printf("Slot %d: (%d, %d)\n", i, hashTable->keys[i], hashTable->values[i]);
        }
        else
        {
            printf("Slot %d: Empty\n", i);
        }
    }
}

void main()
{
    HashTable hashTable;
    int size;
    printf("enter size of hash table: ");
    scanf("%d", &size);
    initializeHashTable(&hashTable, size);
    int n, key, value;
    printf("enter how many values to insert: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        printf("enter key and corresponding value: ");
        scanf("%d %d", &key, &value);
        insertElement(&hashTable, key, value);
    }
    // Display the hash table
    printf("Initial Hash Table:\n");
    displayHashTable(&hashTable);
    // Search for a key
    int keyToSearch;
    printf("enter key to search: ");
    scanf("%d", &keyToSearch);
    int index = searchElement(&hashTable, keyToSearch);
    if (index != -1)
    {
        printf("Key %d found\nValue: %d\n", keyToSearch, hashTable.values[index]);
    }
    else
    {
        printf("Key %d not found.\n", keyToSearch);
    }
}
