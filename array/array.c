#include <stdio.h>
#include <stdlib.h>

// Function declarations (prototypes) - tell compiler what exists
struct DynamicArray* create_array(int initial_capacity);
void push(struct DynamicArray* arr, int value);
int get(struct DynamicArray* arr, int index);
void destroy_array(struct DynamicArray* arr);

// Struct definition
struct DynamicArray {
    int* data;
    int size;
    int capacity;
};

// Function implementations
struct DynamicArray* create_array(int initial_capacity) {
    struct DynamicArray* arrayPtr = malloc(sizeof(struct DynamicArray));

    // check our malloc
    if (arrayPtr == NULL) {
        return NULL;
    }

    arrayPtr->capacity = initial_capacity;
    arrayPtr->size = 0;
    arrayPtr->data = (int*)malloc(initial_capacity * sizeof(int));

    // check our malloc again.
    if (arrayPtr->data != NULL) {
        return arrayPtr;
    } else {
        return NULL;
    }

    // I feel like this might free something we don't own idk.
    // But there's no way it can make it past the above if/else.
    free(arrayPtr->data);
    free(arrayPtr);
    return NULL;
}

void push(struct DynamicArray* arr, int value) {
    // your code here
}

// ... other functions

int main() {
}