/*
Linked List Practice Module
Author: Tannaz Chowdhury
Date: 2025

This module demonstrates key operations on singly linked lists in C, including:
- Insert at index
- Prepend (insert at head)
- Append (insert at tail)
- Move first k nodes to the end

The examples are structured and commented line-by-line to help learners understand pointer manipulation in linked lists.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// -----------------------------------------------------------------------------
// Linked List Structures
// -----------------------------------------------------------------------------

typedef struct node {
    int data;              // Value stored in this node
    struct node *next;     // Pointer to next node
} Node;

typedef struct {
    Node *head;            // Pointer to first node
    int size;              // Number of elements in the list
} LL;


// -----------------------------------------------------------------------------
// Create a new linked list
// -----------------------------------------------------------------------------
LL* create_list() {
    LL *list = (LL *)malloc(sizeof(LL));
    list->head = NULL;
    list->size = 0;
    return list;
}

// -----------------------------------------------------------------------------
// Append value to end of list
// -----------------------------------------------------------------------------
void LL_append(LL *list, int val) {
    Node *new_node = (Node *)malloc(sizeof(Node));
    new_node->data = val;
    new_node->next = NULL;

    if (list->head == NULL) {
        list->head = new_node;
    } else {
        Node *curr = list->head;
        while (curr->next != NULL) curr = curr->next;
        curr->next = new_node;
    }
    list->size++;
}

// -----------------------------------------------------------------------------
// Prepend value to start of list
// -----------------------------------------------------------------------------
void LL_prepend(LL *list, int val) {
    Node *new_node = (Node *)malloc(sizeof(Node));
    new_node->data = val;
    new_node->next = list->head;
    list->head = new_node;
    list->size++;
}

// -----------------------------------------------------------------------------
// Insert value at index i
// -----------------------------------------------------------------------------
void LL_insert(LL *list, int val, int i) {
    if (i < 0 || i > list->size) {
        printf("Index %d out of bounds\n", i);
        return;
    }

    Node *new_node = (Node *)malloc(sizeof(Node));
    new_node->data = val;

    if (i == 0) {
        new_node->next = list->head;
        list->head = new_node;
    } else {
        Node *curr = list->head;
        for (int pos = 0; pos < i - 1; pos++) curr = curr->next;
        new_node->next = curr->next;
        curr->next = new_node;
    }
    list->size++;
}

// -----------------------------------------------------------------------------
// Move first k nodes to the end
// -----------------------------------------------------------------------------
void move_first_k_to_end(LL *list, int k) {
    if (list->head == NULL || k <= 0 || k >= list->size) return;

    Node *curr = list->head;
    int count = 1;

    while (count < k && curr->next != NULL) {
        curr = curr->next;
        count++;
    }

    Node *new_head = curr->next;
    curr->next = NULL; // End first part

    Node *tail = new_head;
    while (tail && tail->next != NULL) tail = tail->next;

    if (tail) tail->next = list->head; // Join end of list to front part
    list->head = new_head;
}

// -----------------------------------------------------------------------------
// Print entire list
// -----------------------------------------------------------------------------
void print_list(LL *list) {
    Node *curr = list->head;
    while (curr != NULL) {
        printf("%d -> ", curr->data);
        curr = curr->next;
    }
    printf("NULL\n");
}

// -----------------------------------------------------------------------------
// Free all nodes in the list
// -----------------------------------------------------------------------------
void destroy_list(LL *list) {
    Node *curr = list->head;
    while (curr) {
        Node *tmp = curr;
        curr = curr->next;
        free(tmp);
    }
    free(list);
}

// -----------------------------------------------------------------------------
// Suggested Exercises
// -----------------------------------------------------------------------------
/*
1. Implement a function to delete a node at a given index.
2. Implement a function that reverses the entire linked list in-place.
3. Implement a function that removes all occurrences of a specific value.
4. Implement a function that finds the middle node in one pass.
*/
