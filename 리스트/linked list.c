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

ListNode* insert(ListNode *head, ListNode *pre, element value)
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

ListNode *getNodeWith(ListNode *head, int value)
{
	int sel = 1;
	switch(sel) {
		case 1:
			ListNode *p = head;
			for(ListNode *p = head; p != NULL; p = p->link) {
				if (p->link->data == value) // 한 칸 앞서 봐야지 delete할 때 pre를 알 수 있음
					return p;
			}
		case 2:
			while(p != NULL) {
				// if (p->link->data == value) // 한 칸 앞서 봐야지 delete할 때 pre를 알 수 있음
				if (p->data == value) // 한 칸 앞서 봐야지 delete할 때 pre를 알 수 있음
					return p;
				p = p->link;
			}
	}
}

ListNode *getNodeAt(ListNode *head, int index)
{
	ListNode *p = head;
	for (int i = 0; i != index - 1; i++) { // 한 단계 덜 찾아야 pre가 된다.
		p = p->link;
	}
}

ListNode* deletion(ListNode *head, ListNode *pre)
{
	if (head == pre){
		head = delete_first(head);
	}
	else if (pre -> link == NULL) {
		printf("삭제할 노드가 없습니다.\n");
		return head;
	}
	else {
		ListNode *removed;
		removed = pre->link;
		pre = removed->link;		// (2)
		free(removed);			// (3)
		return head;			// (4)
	}
}

void print_list(ListNode *head)
{
	for (ListNode *p = head; p != NULL; p = p->link)
		printf("%d->", p->data);
	printf("NULL \n");
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

	printf("\n\n");


	for (int i = 0; i < 5; i++) {
		head = insert_first(head, i);
		print_list(head);
	}

	head = deletion(head, getNodeWith(head, 3));
	head = deletion(head, getNodeAt(head, 3));

	print_list(head);


	return 0;
}