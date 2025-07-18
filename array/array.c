#include <stdio.h>
#include <stdlib.h>

// Creates an array of the specified capacity.
// @returns pointer | NULL failure
struct DynamicArray* create_array(int initial_capacity);

// Pushes an element to the array.
// @returns 0 success | 1 failure
int push(struct DynamicArray* arr, int value);

// Retrieves the value at an index.
// Assigns value to `return_pointer`.
// @returns 0 success | 1 failure
int get(struct DynamicArray* arr, int index, int* return_pointer);

// Removes the last element of an array
// @returns 0 success | 1 failure
int pop(struct DynamicArray* arr);

// Removes array from heap memory
// @returns 0 success | 1 failure
int destroy_array(struct DynamicArray* arr);
void execute_array_tests();

struct DynamicArray {
    int* data;
    int size;
    int capacity;
};

struct DynamicArray* create_array(int initial_capacity) {
    
    // Allocate memory for the struct
    struct DynamicArray* arrayPtr = malloc(sizeof(struct DynamicArray));

    // Ensure memory allocation succeded
    if (arrayPtr == NULL) {
        return NULL;
    }

    // Assign intiger values
    arrayPtr->capacity = initial_capacity;
    arrayPtr->size = 0;

    // Allocate memory for the inters according to function input
    // Assign pointer value
    arrayPtr->data = (int*)malloc(initial_capacity * sizeof(int));

    // Check if 'data' memory allocation succeded
    if (arrayPtr->data != NULL) {
        return arrayPtr; // <== Total success
    } else {
        // If not, we need to free the successful struct memory
        free(arrayPtr);
        return NULL;
    }

}

int push(struct DynamicArray* arr, int value) {
    
    // Null pointer check
    if (arr == NULL) {
        return 1;
    }

    // Ensure we still have room
    if (arr->size >= arr->capacity) {
        // I feel like if size is > capacity we have a bigger issue.
        return 1;
    }

    // We have room
    int* next_emtpy_memory_address = arr->data + arr->size; // Get next empty mem address
    *next_emtpy_memory_address = value;                     // Give the address a value 'resident'
    arr->size ++;                                           // Increment the array size
    return 0;
}

int get(struct DynamicArray* arr, int index, int* return_pointer) {

    // Null pointer check
    if (arr == NULL || return_pointer == NULL) {
        return 1;
    }

    // Check if `index` is valid
    if (index < 0 || index >= arr->size) {
        return 1;
    }

    // Return value at calculated mem address
    *return_pointer = *(arr->data + index);
    return 0;
}

int pop(struct DynamicArray* arr) {

    // Null pointer check
    if (arr == NULL) {
        return 1;
    }

    // Empty array check
    // Potential buffer overflow
    if (arr->size <= 0) {
        return 1;
    }

    // Just decrement size.  Don't need to clear data.
    arr->size --;
    return 0;
}

int destroy_array(struct DynamicArray* arr) {

    // Null pointer check
    if(arr == NULL) {
        return 1;
    }

    // Free data and struct
    free(arr->data);
    free(arr);

    return 0;
}

void execute_array_tests() {
    printf("Starting array tests...\n");

    struct DynamicArray* arr = create_array(10);
    push(arr, 100);
    push(arr, 250);
    push(arr, 1000);

    printf("Array size should be 3 and is: %i\n", arr->size);

    // Test getting value at index 2
    int val;
    int result = get(arr, 2, &val);  // Index 2, not 3
    if (result == 0) {
        printf("Value at index 2 should be 1000 and is %i\n", val);
    } else {
        printf("Failed to get value at index 2\n");
    }

    int total = 0;
    for(int i = 0; i < arr->size; i++) {
        result = get(arr, i, &val);
        if (result == 0) {
            total = total + val;
        }
    }
    printf("Total should be 1350 and is %i\n", total);

    pop(arr);
    printf("Size should now be 2 and is %i\n", arr->size);

    int success = destroy_array(arr);
    arr = NULL; // Dangling pointer.
    printf("successful destruction = %i\n", success);
}