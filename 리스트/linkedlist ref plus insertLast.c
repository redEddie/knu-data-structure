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
	p->data = value;	// (2)
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

ListNode* delete(ListNode *head, ListNode *pre)
{
	ListNode *removed;
	removed = pre->link;
	pre->link = removed->link;		// (2)
	free(removed);			// (3)
	return head;			// (4)
}

ListNode* insertLast(ListNode* head, int data){
    ListNode* node = (ListNode *)malloc(sizeof(ListNode));
    node->data = data;
    if (head == NULL){
        head = node;
        node->link = head;
    } else{
        node->link = head->link;    // 새로운 노드가 가르키는 곳은 헤드가 가리키는 곳에 있던 첫 노드가 되고
        head->link = node;    // 헤드가 가르키던 곳의 노드는 끝노드를 가리키고
        head = node;          // 헤드가 자체가 새로운 끝 노드가 된다.
        // head = node;                // 헤드는 그 자체로 끝노드다. 다시 말하면 끝에서 두번째 노드가 헤드를 가르키고 있다.
    }
    return head;
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
	for (int i = 0; i < 5; i++) {
		head = insert_first(head, i);
		print_list(head);
	}
	for (int i = 10; i<15; i++){
		head = insertLast(head, i);
		print_list(head);
	}
	return 0;
}