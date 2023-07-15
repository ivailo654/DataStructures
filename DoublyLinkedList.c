#include <stdio.h>
#include <stdlib.h>

struct node {

	int data;
	struct node* next;
	struct node* prev;
};
struct node* head;
struct node* NewNode(int x) {
	struct node* NewNode1 = (struct node*)malloc(sizeof(struct node));
	NewNode1->data = x;
	NewNode1->next = NULL;
	NewNode1->prev = NULL;
	return NewNode1;
}
void insertAtTail(int n) {
	struct node* new = NewNode(n);
	if (head == NULL)
	{
		head = new;
		return;
	}
	struct node *temp = head;
	while (temp->next != NULL) temp = temp->next;
	temp->next = new;
	new->prev = temp;
}
void print() {
	struct node* temp = head;
	while (temp != NULL)
	{
		printf("%d", temp->data);
		temp = temp->next;
		
	}
}
void reverse() {
	struct node* temp = head;
	struct node* curr = head;
	while (curr != NULL) {
		temp = curr->prev;
		curr->prev = curr->next;
		curr->next = temp;
		if (curr->prev == NULL) head = curr;
		curr = curr->prev;
	}
	
}
int main() {
	head = NULL;
	insertAtTail(1);
	insertAtTail(2);
	insertAtTail(3);
	insertAtTail(4);
	print();
	reverse();
	print();
    return 0;
}
