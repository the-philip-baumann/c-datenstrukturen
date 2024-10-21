#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node {
	int value;
	struct Node* next;
};

struct SingleLinkedList {
    struct Node* header;
    struct Node* tailer;
    int size;
};

void addFirst(struct SingleLinkedList* list, int value);
int removeFirst(struct SingleLinkedList* list);
void print(struct SingleLinkedList* list);
struct SingleLinkedList* createSingleLinkedList();

int main(int argc, char *argv[]) {

    struct SingleLinkedList* list = createSingleLinkedList();

    addFirst(list, 3);
    addFirst(list, 2);
    addFirst(list, 1);
    addFirst(list, 3);

    removeFirst(list);

    print(list);

}

struct SingleLinkedList* createSingleLinkedList() {
    struct Node* header = (struct Node*)malloc(sizeof(struct Node));
    struct Node* tailer = (struct Node*)malloc(sizeof(struct Node));
    struct SingleLinkedList* list = (struct SingleLinkedList*)malloc(sizeof(struct SingleLinkedList));
    list->header = header;
    list->tailer = tailer;
    header->next = tailer;
    return list;
}

void addFirst(struct SingleLinkedList* list, int value){
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    struct Node* first = list->header->next;
    node->value = value;
    list->header->next = node;
    node->next = first;
    list->header->next = node;
    node->next = first; 
    list->size++;
}

int removeFirst(struct SingleLinkedList* list) {
    if (list->size == 0){
        return -1;
    }
    
    struct Node* first = list->header->next;
    int value = first->value;
    list->header->next = first->next;
    return value; 
}

void print(struct SingleLinkedList* list) {
    struct Node* temp = list->header->next;
    while(temp != list->tailer){
        printf("Value: %d\n", temp->value); 
        temp = temp->next;
    } 
}
