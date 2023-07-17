#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
struct node {

	int data;
	struct node* link;
};
struct node* head;
void push(int n)
{
	struct node* temp = (struct node*)malloc(sizeof(struct node));
	temp->data = n;
	temp->link = head;
	head = temp;
}
void print() {
	struct node* temp = head;
	if (head != NULL)
	{
		while (temp != NULL) {
			printf("%d", temp->data);
			temp = temp->link;
		}
	}
	printf("\n");
}
void pop() {
	if (head == NULL) return;
	struct node* temp = head;
	head = head->link;
	printf("%d \n", temp->data);
	free(temp);
}
char isEmpty() {
	if (head == NULL) return 'n';
	return 'y';
}
int top() {
	return head->data;
}
int main() {
	push(1);
	print();
	push(2);
	print();
	push(3);
	print();
	push(4);
	print();
	pop();
	print();
	pop();
	print();
	pop();
	print();
	printf("%c  \n", isEmpty());
	pop();
	print();
	printf("%c  \n", isEmpty());

}