#include <stdio.h>
#include <stdlib.h>

typedef int element;
typedef struct ListNode { 
	element data;
	struct ListNode *link;
} ListNode;

void error(char *message)
{
	fprintf(stderr, "%s\n", message);
	exit(1);
}
ListNode* insert_first(ListNode *head, int value)
{
	ListNode *p = (ListNode *)malloc(sizeof(ListNode));	//(1)
	p->data = value;					// (2)
	p->link = head;		//(3)
	head = p;		//(4)
	return head;
}

ListNode*  insert(ListNode *head, ListNode *pre, element value)
{
	ListNode *p = (ListNode *)malloc(sizeof(ListNode));	//(1)
	p->data = value;		//(2)
	p->link = pre->link;	//(3)	
	pre->link = p;		//(4)	
	return head;		//(5)	
}

ListNode* delete_first(ListNode *head)
{
	ListNode *removed;
	if (head == NULL)
		return NULL;
	removed = head;	// (1)
	head = removed->link;	// (2)
	free(removed);		// (3)
	return head;		// (4)
}

ListNode* deleteeeeeeee(ListNode *head, ListNode *loc){
	if (head == NULL)
	{
		return NULL;
	}
	else if (loc == NULL)
	{
		return head;
	}
	else if (loc->link == NULL)
	{
		return head;
	}
	
	ListNode* temp = head;
	for (int i = 0; temp->link == loc; i++){
		temp = temp->link;
	}
	temp->link = loc->link;
	free(loc);
}


ListNode* deleteWithPre(ListNode *head, ListNode *pre)
{
	if (head == NULL || pre == NULL)
		return NULL;
	if (pre->link == NULL)
		return NULL;
	ListNode *removed;
	removed = pre->link;
	if (removed->link == NULL)
		pre->link = NULL;
	else
		pre->link = removed->link;		// (2)
	free(removed);					// (3)
	return head;					// (4)
}

void print_list(ListNode *head)
{
	for (ListNode *p = head; p != NULL; p = p->link)
		printf("%d->", p->data);
	printf("NULL \n");
}

ListNode *getNodeAt(ListNode *head, int index)
{
	if (head == NULL)
		return NULL;
	if (index == 0)
		return head;
	ListNode *p = head;
	for (int i = 0; i != index - 1; i++) { // 한 단계 덜 찾아야 pre가 된다.
		p = p->link;
	}
}

int main(void)
{
	ListNode *head = NULL;

	for (int i = 0; i < 5; i++) {
		head = insert_first(head, i);
		print_list(head);
	}
	for (int i = 0; i < 5; i++) {
		head = delete_first(head);
		print_list(head);
	}
	for (int i = 0; i < 5; i++) {
		head = insert_first(head, i);
		print_list(head);
	}

	head = deleteWithPre(head, getNodeAt(head, 0));
	print_list(head);

	head = deleteeeeeeee(head, getNodeAt(head, 2)->link);
	print_list(head);

	return 0;
}