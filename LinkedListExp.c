#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
struct node {

	int data;
	struct node* link;
};
struct node* head;
void insertInHead(int n)
{
	struct node* temp = (struct node*)malloc(sizeof(struct node));
	temp->data = n;
	temp->link = head;//if n== 1 => head == null
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
}
void insertinn(int n, int pos)
{
	struct node* temp = head;
	struct node* new = (struct node*)malloc(sizeof(struct node));

	if (pos == 1)
	{
		insertInHead(n);
		return;
	}
	for (int i = 1; i < pos - 2; i++)
	{
		temp = temp->link;
		if (temp == NULL)
		{
			printf("error");
			return;
		}
	}
	new->data = n;
	new->link = temp->link;
	temp->link = new;
}
void delNthNode(int n)
{
	struct node* temp = head;
	if (n == 1)
	{
		head = head->link;
		free(temp);
		return;
	}
	for (int i = 1; i < n - 1; i++)
	{
		temp = temp->link;
		if (temp == NULL)
		{
			printf("error");
			return;
		}
	}
	struct node* del = temp->link;
	temp->link = del->link;
	free(del);
}
void reverse()
{
	struct node* temp = head;
	struct node* old = NULL;
	struct node* next = NULL;
	while (temp != NULL) {
		next = temp->link;
		temp->link = old;
		old = temp;
		temp = next;
	}
	head = old;
}
void main() {

	head = NULL;
	insertInHead(1);
	insertInHead(2);
	insertInHead(3);
	insertInHead(4);
	insertinn(6, 2);
	delNthNode(2);
	reverse();
	print();
}