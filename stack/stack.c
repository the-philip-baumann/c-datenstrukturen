#include "stdio.h"
#include "stdlib.h"

struct Node {
    struct Node* next;
    int value;
};

struct Stack {
    struct Node* header;
    struct Node* tailer;
    int size;
};

struct Stack* createStack();
void push(struct Stack* stack, int value);
int pop(struct Stack* stack);

int main(int argc, char* argv[]) {
   struct Stack* stack = createStack();

    printf("%d\n", pop(stack));

    push(stack, 5); 
    push(stack, 4); 
    push(stack, 3); 
    push(stack, 2); 
    push(stack, 1); 
    push(stack, 0); 

    printf("%d\n", pop(stack));
    printf("%d\n", pop(stack));
    printf("%d\n", pop(stack));
    printf("%d\n", pop(stack));
    
    printf("%d\n", stack->size);
}

struct Stack* createStack() {
    struct Stack* stack = (struct Stack*)malloc(sizeof(struct Stack));
    struct Node* head = (struct Node*)malloc(sizeof(struct Node));
    struct Node* tail = (struct Node*)malloc(sizeof(struct Node));

    stack->header = head;
    stack->tailer = tail;

    tail->next = NULL;
    head->next = tail;

    stack->size = 0;

    return stack; 
}

void push(struct Stack* stack, int value) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Stack));
    struct Node* first = stack->header->next;

    node->next = first;
    stack->header->next = node;
    
    node->value = value;

    stack->size++;
}

int pop(struct Stack* stack) {
    if (stack->size == 0) {
        return -1;
    }
    struct Node* node = stack->header->next;
    int value = node->value;
    
    stack->header->next = node->next; 
    stack->size--;

    free(node);
    return value; 
}
