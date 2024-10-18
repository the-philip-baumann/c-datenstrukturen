#include <stdio.h>
#include <stdlib.h>
#include <string.h>


struct Node {
	char value[30];
	struct Node* next;
};

void printList(struct Node* node);

int main(int argc, char *argv[]) {
	const int lengthOfArray = atoi(argv[1]);
    struct Node* head = NULL;

	printf("Length of list to be generated: %d\n", lengthOfArray);	

    for (int i = 0; i < lengthOfArray; i++) {
        struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->next = head;
        strcpy(newNode->value, "Hello World");
        head = newNode;
    }

    printList(head); 
	
	return 0; 
}

void printList(struct Node* node) {
   struct Node* temp = node;
    
    while(temp != NULL) {
      printf("%s \n", node->value);
      temp = temp->next;
    }
    printf("Finished");
}
