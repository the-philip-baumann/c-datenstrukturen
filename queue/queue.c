#include "stdio.h"
#include "stdlib.h"

struct Node {
    struct Node* next;
    int value;
};

struct Queue {
    struct Node* head;
    struct Node* tail;
    int size;
};

struct Queue* createQueue();
void push(struct Queue* queue, int value);
int pop(struct Queue* queue);

int main(int argc, char* argv[]) {

    struct Queue* queue = createQueue();

    printf("%d\n", pop(queue));

    push(queue, 6);
    push(queue, 5);
    push(queue, 4);
    push(queue, 3);
    push(queue, 2);
    push(queue, 1);

    printf("%d\n", pop(queue));
    printf("%d\n", pop(queue));
    printf("%d\n", pop(queue));

    printf("%d\n", queue->size);
   
   return 0; 
}

void push(struct Queue* queue, int value) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->value = value;

    if (queue->size == 0){
        queue->tail = node;
        queue->head = node;
        node->next = NULL;
    } else {
        struct Node* oldTail = queue->tail;
        oldTail->next = node;
        queue->tail = node;
    }

    queue->size++;
}

int pop(struct Queue* queue) {
    if (queue->size == 0) {
        return -1;
    }

    int value = queue->head->value;

    struct Node* first = queue->head;
    queue->head = first->next;

    free(first);
    queue->size--;
    return value;
}

struct Queue* createQueue() {
    struct Queue* queue = (struct Queue*)malloc(sizeof(struct Queue));
    
    queue->head = NULL;
    queue->tail = NULL;
    queue->size = 0;

    return queue;
}
