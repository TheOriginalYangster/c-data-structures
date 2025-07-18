#include <stdio.h>
#include <stdlib.h>

// Function prototypes
struct LinkedList* create_list(void);
struct Node* create_node(int value);
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

    list->head = malloc(sizeof(struct Node));
    
    // Ensure memory allocation is successful
    if (list->head == NULL) {
        free(list);
        return NULL;
    }
    
    list->size = 1;


    return list;
}

struct Node* create_node(int value) {
    // TODO: Allocate memory for Node struct
    // TODO: Set data to value and next to NULL
    // TODO: Return pointer to new node or NULL on failure
    return NULL;
}

int destroy_list(struct LinkedList* list) {
    // TODO: Check for NULL list
    // TODO: Free all nodes in the list
    // TODO: Free the list struct itself
    // TODO: Return 0 on success, 1 on failure
    return 1;
}

int insert_front(struct LinkedList* list, int value) {
    // TODO: Check for NULL list
    // TODO: Create new node
    // TODO: Set new node's next to current head
    // TODO: Update head to point to new node
    // TODO: Increment size
    // TODO: Return 0 on success, 1 on failure
    return 1;
}

int insert_back(struct LinkedList* list, int value) {
    // TODO: Check for NULL list
    // TODO: Create new node
    // TODO: If list is empty, set head to new node
    // TODO: Otherwise, traverse to last node and link new node
    // TODO: Increment size
    // TODO: Return 0 on success, 1 on failure
    return 1;
}

int insert_at(struct LinkedList* list, int index, int value) {
    // TODO: Check for NULL list and valid index
    // TODO: If index is 0, use insert_front
    // TODO: Otherwise, traverse to position index-1
    // TODO: Create new node and link it between current and next
    // TODO: Increment size
    // TODO: Return 0 on success, 1 on failure
    return 1;
}

int remove_value(struct LinkedList* list, int value) {
    // TODO: Check for NULL list
    // TODO: Handle removing head node specially
    // TODO: Traverse list to find node with matching value
    // TODO: Update pointers to skip found node
    // TODO: Free the removed node
    // TODO: Decrement size
    // TODO: Return 0 on success, 1 if not found
    return 1;
}

int remove_at(struct LinkedList* list, int index) {
    // TODO: Check for NULL list and valid index
    // TODO: Handle removing head node specially
    // TODO: Traverse to position index-1
    // TODO: Update pointers to skip node at index
    // TODO: Free the removed node
    // TODO: Decrement size
    // TODO: Return 0 on success, 1 on failure
    return 1;
}

int remove_front(struct LinkedList* list) {
    // TODO: Check for NULL list and empty list
    // TODO: Save current head
    // TODO: Update head to next node
    // TODO: Free old head
    // TODO: Decrement size
    // TODO: Return 0 on success, 1 on failure
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