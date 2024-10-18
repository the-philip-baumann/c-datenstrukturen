#include "stdio.h"
#include "stdlib.h"

struct Node {
    int value;
    struct Node* prev;
    struct Node* next;
};

struct DoubleLinkedList {
    struct Node* header;
    struct Node* tailer;
    int size;
};

void print(struct DoubleLinkedList* list);
void addFirst(struct DoubleLinkedList* list, int value);
void addLast(struct DoubleLinkedList* list, int value);
int removeFirst(struct DoubleLinkedList* list);
int removeLast(struct DoubleLinkedList* list);
struct DoubleLinkedList* createDoubleLinkedList();

int main(int argc, char* argv[]){
    printf("Programm running with Arguments: %d \n", argc); 

    struct DoubleLinkedList* list = createDoubleLinkedList();
    printf("%d \n", removeFirst(list));
    printf("%d \n", removeLast(list));

    addFirst(list, 1);
    addLast(list, 2);
    addLast(list, 3);

    addFirst(list, 5);
    addLast(list, 0);

    removeFirst(list);
    removeLast(list);

    print(list);
}

struct DoubleLinkedList* createDoubleLinkedList(){
    struct DoubleLinkedList* list = (struct DoubleLinkedList*)malloc(sizeof(struct DoubleLinkedList));
    list->header = (struct Node*)malloc(sizeof(struct Node));
    list->tailer = (struct Node*)malloc(sizeof(struct Node));
    list->header->next = list->tailer;
    list->tailer->prev = list->header;
    list->size = 0;
    return list; 
}

void addFirst(struct DoubleLinkedList* list, int value) {
    struct Node* first = list->header->next;
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    first->prev = node;
    node->next = first;
    node->prev = list->header;
    node->value = value;
    list->header->next = node;
    list->size++;
}

void addLast(struct DoubleLinkedList* list, int value) {
    struct Node* last = list->tailer->prev;
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    last->next = node;
    node->prev = last;
    node->value = value;
    node->next = list->tailer;
    list->tailer->prev = node;
    list->size++;
}

int removeFirst(struct DoubleLinkedList* list) {
    if (list->size == 0) {
        return -1;
    }
    struct Node* first = list->header->next;
    list->header->next = first->next;
    first->next->prev = list->header;
    int value = first->value;
    free(first);
    list->size--; 
    return value; 
}

int removeLast(struct DoubleLinkedList* list) {
    if (list->size == 0) {
        return -1;
    }
    struct Node* last = list->tailer->prev;
    last->prev->next = list->tailer;
    list->tailer->prev = last->prev;
    int value = last->value;
    free(last);
    list->size--;
    return value;
}

void print(struct DoubleLinkedList* list) {
    struct Node* node = list->header->next; 
    while(node != list->tailer) {
        printf("Value: %d\n", node->value);
        node = node->next;
    }

}
