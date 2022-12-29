// https://en.wikipedia.org/wiki/Double-ended_queue

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>

typedef struct Dequeue_node {
    int val;
    struct Dequeue_node *prev, *next;
} Dequeue_node;

typedef struct Dequeue {
    struct Dequeue_node *head, *tail;
} Dequeue;

Dequeue_node* new_dequeue_node(int val) {
    Dequeue_node *node = malloc(sizeof(Dequeue_node));
    node -> val = val;
    node -> prev = node -> next = NULL;
    return node;
}

Dequeue* new_dequeue() {
    Dequeue *deque = malloc(sizeof(Dequeue));
    deque -> head = NULL;
    deque -> tail = NULL;
    return deque;
}

void push_back(Dequeue *deque, const int value) {
    Dequeue_node *node = new_dequeue_node(value);
    if (deque -> head == NULL) {
        deque -> head = deque -> tail = node;
    }
    else {
        node -> prev = deque -> tail;
        deque -> tail -> next = node;
        deque -> tail = node;
    }
}

void push_front(Dequeue *deque, const int value) {
    Dequeue_node *node = new_dequeue_node(value);
    if (deque -> head == NULL) {
        deque -> head = deque -> tail = node;
    }
    else {
        node -> next = deque -> head;
        deque -> head -> prev = node;
        deque -> head = node;
    }
}

void pop_back(Dequeue *deque) {
    // Check for empty deque
    assert(deque -> tail != NULL);

    Dequeue_node *node = deque -> tail;

    if (deque -> head == deque -> tail) {
        // Single node deque
        deque -> head = deque -> tail = NULL;
    }

    else {
        // More than one node
        node -> prev -> next = NULL;
        deque -> tail = node -> prev;
    }

    free(node);
}

void pop_front(Dequeue *deque) {
    // Check for empty deque
    assert(deque -> head != NULL);

    Dequeue_node *node = deque -> head;

    if (deque -> head == deque -> tail) {
        // Single node deque
        deque -> head = deque -> tail = NULL;
    }

    else {
        // More than one node
        node -> next -> prev = NULL;
        deque -> head = node -> next;
    }

    free(node);
}

int back(const Dequeue *deque) {
    // Check for empty deque
    assert(deque -> tail != NULL);

    return deque -> tail -> val;
}

int front(const Dequeue *deque) {
    // Check for empty deque
    assert(deque -> head != NULL);

    return deque -> head -> val;
}

bool is_empty(const Dequeue *deque) {
    return deque -> head == NULL;
}

void print_deque(const Dequeue *deque) {
    Dequeue_node *node = deque -> head;
    printf("{");
    while (node) {
        printf("%d", node -> val);
        printf(node -> next ? ", ": "");
        node = node -> next;
    }
    printf("}\n");
}

int main() {
    Dequeue *deque = new_dequeue();

    push_back(deque, 5);
    push_back(deque, 10);
    print_deque(deque);

    push_back(deque, 0);
    pop_front(deque);
    print_deque(deque);

    int val_front = front(deque);
    int val_back = back(deque);

    printf("Front: %d, back: %d\n", val_front, val_back);

    pop_back(deque); pop_back(deque);

    printf("Dequeue is %s\n", (is_empty(deque) ? "Empty" : "Not Empty"));

    return 0;
}