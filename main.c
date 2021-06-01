#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>

#define SIZE 20

struct DataItem
{
    int data;
    int key;
};

struct DataItem *hashArray[SIZE];
struct DataItem *tmpItem;
struct DataItem *item;

int hashCode(int key)
{
    return key % SIZE;
}

struct DataItem *search(int key)
{
    int hashIndex;

    // get the hash
    hashIndex = hashCode(key);

    // move the array until an empty
    while(hashArray[hashIndex] != NULL)
    {
        if(hashArray[hashIndex]->key == key)
            return hashArray[hashIndex];

        // go to the next cell
        hashIndex++;

        // wrap around the table
        hashIndex %= SIZE;
    }

    return NULL;
}

void insert(int key, int data)
{
    struct DataItem *item;
    int hashIndex;

    item = (struct DataItem *) malloc(sizeof(struct DataItem));
    item->data = data;
    item->key = key;

    hashIndex = hashCode(key);
    while(hashArray[hashIndex] != NULL && hashArray[hashIndex]->key != -1)
    {
        hashIndex++;
        hashIndex %= SIZE;
    }

    hashArray[hashIndex] = item;
}

struct DataItem *delete(struct DataItem *item) {
    int key;
    int hashIndex;

    key = item->key;
    hashIndex = hashCode(key);

    while(hashArray[hashIndex] != NULL)
    {
        if(hashArray[hashIndex]->key == key)
        {
            struct DataItem *tmp = hashArray[hashIndex];
            hashArray[hashIndex] = tmpItem;
            return tmp;
        }
        hashIndex++;
        hashIndex %= SIZE;
    }

    return NULL;
}

void display()
{
    int i;

    i = 0;
    while(i < SIZE)
    {
        if(hashArray[i] != NULL)
            printf(" (%d, %d)", hashArray[i]->key, hashArray[i]->data);
        else
            printf(" -- ");
        i++;
    }
    printf("\n");
}

int main() {
    tmpItem = (struct DataItem *) malloc(sizeof(struct DataItem));
    tmpItem->data = -1;
    tmpItem->key = -1;

    insert(1, 45);
    insert(2, 5463);
    insert(3, 53465);
    insert(4, 45);
    insert(5, 32);
    insert(6, 27);
    insert(7, 26);
    insert(8, 24);
    insert(9, 23);
    insert(10, 22);

    item = search(8);
    display();
    if(item != NULL)
        printf("Element found: %d\n", item->data);
    else
        printf("Element not found\n");

    delete(item);
    item = search(8);
    display();
    if(item != NULL)
        printf("Element found: %d\n", item->data);
    else
        printf("Element not found\n");
    return 0;
}
