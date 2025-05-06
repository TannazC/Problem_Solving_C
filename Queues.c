/*
Queue Practice Module
Author: Tannaz Chowdhury
Date: 2025

This module demonstrates the implementation of:
- Circular Queue of integers (simulated)
- Priority Queue using structs (C)
- Queue exercises for deeper understanding of pointers, data movement, and memory safety
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

// -----------------------------------------------------------------------------
// CIRCULAR QUEUE OF INTEGERS (FIXED SIZE)
// -----------------------------------------------------------------------------
typedef struct {
    int items[MAX_SIZE]; // Array buffer for queue elements
    int front;           // Points to the first (oldest) element
    int rear;            // Points to the last (most recent) element
    int size;            // Number of elements in the queue
} CircQueue;

// Initializes the queue
void initialize(CircQueue *q) {
    q->front = -1;
    q->rear = -1;
    q->size = 0;
}

// Checks if the queue is full
int full(CircQueue *q) {
    return ((q->rear + 1) % MAX_SIZE == q->front);
}

// Checks if the queue is empty
int empty(CircQueue *q) {
    return (q->front == -1);
}

// Enqueues an integer into the circular queue
void enqueue(CircQueue *q, int data) {
    if (full(q)) {
        printf("Queue is full\n");
        return;
    }

    if (empty(q)) {
        q->front = 0;
        q->rear = 0;
    } else {
        q->rear = (q->rear + 1) % MAX_SIZE;
    }

    q->items[q->rear] = data;
    q->size++;
    printf("Enqueued: %d\n", data);
}

// Dequeues an integer from the circular queue
void dequeue(CircQueue *q) {
    if (empty(q)) {
        printf("Queue is empty\n");
        return;
    }

    int removed = q->items[q->front];
    printf("Dequeued: %d\n", removed);

    if (q->front == q->rear) {
        q->front = -1;
        q->rear = -1;
    } else {
        q->front = (q->front + 1) % MAX_SIZE;
    }

    q->size--;
}

// -----------------------------------------------------------------------------
// PRIORITY QUEUE USING STRUCTS
// -----------------------------------------------------------------------------
typedef struct {
    int value;    // The data value
    int priority; // Priority: lower value means higher priority
} Element;

typedef struct {
    Element data[MAX_SIZE]; // Array to store queue elements
    int size;               // Tracks the current number of elements
} PriorityQueue;

// Insert with priority into the priority queue
void insert(PriorityQueue *pq, int value, int priority) {
    if (pq->size == MAX_SIZE) {
        printf("Queue is full!\n");
        return;
    }

    int i = pq->size - 1;

    // Shift elements until the right position is found
    while (i >= 0 && pq->data[i].priority > priority) {
        pq->data[i + 1] = pq->data[i];
        i--;
    }

    pq->data[i + 1].value = value;
    pq->data[i + 1].priority = priority;
    pq->size++;
    printf("Inserted: %d with priority %d\n", value, priority);
}

// Removes and returns the element with the minimum priority
Element extract_min(PriorityQueue *pq) {
    if (pq->size == 0) {
        printf("Queue is empty\n");
        Element e = {-1, -1};
        return e;
    }
    pq->size--;
    return pq->data[pq->size];
}

// -----------------------------------------------------------------------------
// EXERCISES FOR PRACTICE
// -----------------------------------------------------------------------------

// Exercise 1: Implement a peek function for the circular queue
int peek(CircQueue *q) {
    if (empty(q)) {
        printf("Queue is empty\n");
        return -1;
    }
    return q->items[q->front];
}

// Exercise 2: Implement a queue that resizes dynamically using malloc/realloc
// (optional challenge)

// Exercise 3: Print all elements in the circular queue
void print_queue(CircQueue *q) {
    if (empty(q)) {
        printf("Queue is empty\n");
        return;
    }

    printf("Queue contents: ");
    int i = q->front;
    while (1) {
        printf("%d ", q->items[i]);
        if (i == q->rear)
            break;
        i = (i + 1) % MAX_SIZE;
    }
    printf("\n");
}

// Exercise 4: Write a wrapper to convert this integer queue into a string queue
// (advanced pointer + memory management practice)

// -----------------------------------------------------------------------------
// MAIN DEMO (UNCOMMENT TO RUN)
// -----------------------------------------------------------------------------
/*
int main() {
    CircQueue q;
    initialize(&q);
    enqueue(&q, 10);
    enqueue(&q, 20);
    enqueue(&q, 30);
    print_queue(&q);
    dequeue(&q);
    print_queue(&q);
    printf("Front element is: %d\n", peek(&q));

    PriorityQueue pq = {.size = 0};
    insert(&pq, 5, 2);
    insert(&pq, 10, 1);
    Element min = extract_min(&pq);
    printf("Extracted min: %d with priority %d\n", min.value, min.priority);

    return 0;
}
*/
