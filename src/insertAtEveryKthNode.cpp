/*
OVERVIEW: Given a single linked list insert a new node at every Kth node with value K.
E.g.: 1->2->3->4->5, k = 2, 1->2->2->3->4->2->5

INPUTS: A linked list and Value of K.

OUTPUT: Insert a new node at every Kth node with value K.

ERROR CASES: Return NULL for error cases.

NOTES:
*/

#include <stdio.h>
#include <malloc.h>

struct node {
	int num;
	struct node *next;
};

struct node * insertAtEveryKthNode(struct node *head, int K) {
	if (head == NULL)
		return NULL;
	if (K == 0)
		return head;

	struct node *cur = head;
	int cnt = 0;

	while (cur != NULL) {
		cnt++;
		if (cnt == K) {
			struct node *temp = (struct node *)malloc(sizeof(struct node));
			temp->num = K;
			temp->next = cur->next;
			cur->next = temp;
			cnt = 0;
			cur = temp->next;
		}
		else
			cur = cur->next;
	}
	return head;
}
