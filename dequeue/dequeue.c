#include "stdio.h"
#include "stdlib.h"

struct Node {
    struct Node* next;
    struct Node* prev;
    int value;    
};

struct Dequeue {
    int size;
    struct Node* header;
    struct Node* tailer;
};

struct Dequeue* createDequeue();
void pushHead(struct Dequeue* dequeue, int value);
void pushTail(struct Dequeue* dequeue, int value);
int popHead(struct Dequeue* dequeue);
int popTail(struct Dequeue* dequeue);

int main(int argc, char* argv[]) {

    struct Dequeue* dequeue = createDequeue();
    pushHead(dequeue, 1);
    pushTail(dequeue, 2);
    pushHead(dequeue, 3);
    pushTail(dequeue, 0);

    printf("%d\n", popHead(dequeue));
    printf("%d\n", popTail(dequeue));
    printf("%d\n", dequeue->size);

    return 0;
}

struct Dequeue* createDequeue() {
    struct Dequeue* dequeue = (struct Dequeue*)malloc(sizeof(struct Dequeue));
    struct Node* head = (struct Node*)malloc(sizeof(struct Node));
    struct Node* tail = (struct Node*)malloc(sizeof(struct Node));

    head->next = tail;
    head->prev = NULL;
    tail->prev = head;
    tail->next = NULL;

    dequeue->header = head;
    dequeue->tailer = tail;
    dequeue->size = 0;

    return dequeue;
}

void pushHead(struct Dequeue* dequeue, int value) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    struct Node* first = dequeue->header->next;

    first->prev = node;
    dequeue->header->next = node;
    node->prev = dequeue->header;
    node->next = first;
    node->value = value;

    dequeue->size++;
}

void pushTail(struct Dequeue* dequeue, int value) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    struct Node* last = dequeue->tailer->prev;

    last->next = node;
    dequeue->tailer->prev = node;
    node->next = dequeue->tailer;
    node->prev = last; 

    dequeue->size++;
}

int popHead(struct Dequeue* dequeue) {
    struct Node* first = dequeue->header->next;
    int value = first->value;

    dequeue->header->next = first->next;
    first->next->prev = dequeue->header;

    free(first);
    dequeue->size--;
    return value;
}

int popTail(struct Dequeue* dequeue) {
    struct Node* last = dequeue->tailer->prev;
    int value = last->value;

    dequeue->tailer->prev = last->prev;
    last->prev->next = dequeue->tailer;

    free(last);
    dequeue->size--;
    return value;
}

