#include <stdio.h>
#include <stdlib.h>

// Function prototypes
struct LinkedList* create_list(void);
int destroy_list(struct LinkedList* list);
int insert_front(struct LinkedList* list, int value);
int insert_back(struct LinkedList* list, int value);
int insert_at(struct LinkedList* list, int index, int value);
int remove_value(struct LinkedList* list, int value);
int remove_at(struct LinkedList* list, int index);
int remove_front(struct LinkedList* list);
int remove_back(struct LinkedList* list);
int get(struct LinkedList* list, int index, int* return_value);
int find(struct LinkedList* list, int value);
int contains(struct LinkedList* list, int value);
int size(struct LinkedList* list);
int is_empty(struct LinkedList* list);
void print_list(struct LinkedList* list);
void execute_list_tests(void);

// Struct definitions
struct Node {
    int data;
    struct Node* next;
};

struct LinkedList {
    struct Node* head;
    int size;
};

// ============================================================================
// IMPLEMENTATION SECTION - Fill in the functions below
// ============================================================================

struct LinkedList* create_list(void) {
    struct LinkedList* list = malloc(sizeof(struct LinkedList));

    // Ensure memory allocation is successful
    if (list == NULL) {
        return NULL;
    }

    list->head = NULL;
    list->size = 0;

    return list;
}

int destroy_list(struct LinkedList* list) {
    // TODO
    return 1;
}

int insert_front(struct LinkedList* list, int value) {
    
    // Null pointer check
    if (list == NULL) {
        // list->head can have a Null pointer by design.  Ignore.
        return 1;
    }

    struct Node* new_head = malloc(sizeof(struct Node));

    // Malloc check
    if (new_head == NULL) {
        return 1;
    }

    new_head->data = value;
    new_head->next = list->head;
    list->head = new_head;
    list->size ++;

    return 0;
}

int insert_back(struct LinkedList* list, int value) {
    
    // Null pointer check
    if (list == NULL) {
        return 1;
    }

    // Just create the new node up here
    struct Node* node = malloc(sizeof(struct Node));
    // Check malloc
    if (node == NULL) {
        return 1;
    }
    node->data = value;
    node->next = NULL;
    
    struct Node* current = list->head;

    // Empty list check
    if (current == NULL) {
        list->head = node;
        list->size ++;
        return 0;
    }

    while(current->next != NULL) {
        current = current->next;
    }

    current->next = node;
    list->size ++;
    return 0;

}

int insert_at(struct LinkedList* list, int index, int value) {
    
    // Null pointer check
    // Valid index check
    if (list == NULL || index > list->size) {
        return 1;
    }

    // Create the node
    struct Node* new_node = malloc(sizeof(struct Node));
    if (new_node == NULL) {
        return 1;
    }
    new_node->data = value;

    // index = 0 edge case
    if (index == 0) {
        new_node->next = list->head; // Empty list handles itself
        list->head = new_node;
        list->size ++;
        return 0;
    }

    struct Node* current = list->head;
    int i = 1; // Had to think through why start at 1;
    while(i < index) {
        // Should I do a null pointer check here? => NO!
        // Theoretically it should not happen but who knows.
        current = current->next;
        i ++;
    }

    new_node->next = current->next;
    current->next = new_node;
    list->size ++;
    return 0;
}

int remove_value(struct LinkedList* list, int value) {
    return 1;
}

int remove_at(struct LinkedList* list, int index) {
    return 1;
}

int remove_front(struct LinkedList* list) {
    return 1;
}

int remove_back(struct LinkedList* list) {
    // TODO: Check for NULL list and empty list
    // TODO: Handle single-node case specially
    // TODO: Traverse to second-to-last node
    // TODO: Free last node and set next to NULL
    // TODO: Decrement size
    // TODO: Return 0 on success, 1 on failure
    return 1;
}

int get(struct LinkedList* list, int index, int* return_value) {
    // TODO: Check for NULL list, NULL return_value, and valid index
    // TODO: Traverse to node at index
    // TODO: Set *return_value to node's data
    // TODO: Return 0 on success, 1 on failure
    return 1;
}

int find(struct LinkedList* list, int value) {
    // TODO: Check for NULL list
    // TODO: Traverse list, comparing each node's data to value
    // TODO: Return index if found, -1 if not found
    return -1;
}

int contains(struct LinkedList* list, int value) {
    // TODO: Use find() function
    // TODO: Return 1 if found (index >= 0), 0 if not found
    return 0;
}

int size(struct LinkedList* list) {
    // TODO: Check for NULL list
    // TODO: Return size field
    return 0;
}

int is_empty(struct LinkedList* list) {
    // TODO: Check for NULL list
    // TODO: Return 1 if size is 0, 0 otherwise
    return 1;
}

void print_list(struct LinkedList* list) {
    // TODO: Check for NULL list
    // TODO: Traverse list and print each node's data
    // TODO: Format like: [1, 2, 3] or [empty] for empty list
    printf("[empty]\n");
}

void execute_list_tests(void) {
    printf("Starting linked list tests...\n");
    
    // TODO: Create a list and test all functions
    // TODO: Test edge cases like empty list, single element, etc.
    // TODO: Verify no memory leaks by destroying list at end
    
    printf("Linked list tests completed.\n");
}