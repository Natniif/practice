#include <stdlib.h> 

typedef struct Node {
	int data;
	struct Node* next;
} Node;

// Head -> item1 -> item2 -> item3 -> tail 

Node* add_node(Node* head, int data) {
	Node* newNode = (Node*)malloc(sizeof(Node));

	if (newNode == NULL) {
		printf("Memory failure\n");
		exit(EXIT_FAILURE);
	}

	newNode->data = data;
	newNode->next = NULL;

	head->next = newNode;

	return newNode;
}

void printLinkedList(Node* head) {
	Node* current = head; 
	while (current != NULL) {
		printf("%d -> ", current->data);
		current = current->next;
	}
}

void deleteTopNode(Node* head) {
	Node* head = head->next; 
}

void freeLinkedList(Node* head) {
	Node* current = head; 
	while(current != NULL) {
		Node* tmp = current; 
		current = current->next;
		free(tmp);
	}
}