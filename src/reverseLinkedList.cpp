/*
OVERVIEW: Given a single linked list, reverse the linked list.
E.g.: 1->2->3->4->5, output is 5->4->3->2->1.

INPUTS: A linked list.

OUTPUT: Reverse the linked list.

ERROR CASES: Return NULL for error cases.

NOTES:
*/

#include <stdio.h>

struct node {
	int num;
	struct node *next;
};

struct node * reverseLinkedList(struct node *head) {
	if (head == NULL)
		return NULL;

	struct node *res= head, *q = NULL, *r, *s = head;
	while (res!= NULL){
		r = q;
		q = res;
		res= res->next;
		q->next = r;
	}
	head->next = NULL;
	return q;
}

struct node * reverseLinkedList2(struct node * head) {
	struct node * res = NULL;
	while (head) {
		struct node *cur = head->next;
		head->next = res;
		res = head;
		head = cur;
	}
	return res;
}
