#include <stdio.h>
#include <stdlib.h>

typedef struct doubleListNode
{
    int data;
    struct doubleListNode* llink;
    struct doubleListNode* rlink;
} dListNode;

void init(dListNode* phead)
{
    phead->llink = phead;
    phead->rlink = phead;
}

void print(dListNode* phead)
{
    dListNode* p;

    for(p  = phead->rlink; p != phead; p = p->rlink)
    {
        printf("<-| |%d| |-> ", p->data);
    }
    printf("\n");
}

void insert(dListNode* before, int data)
{
    dListNode* newnode = (dListNode*)malloc(sizeof(dListNode));
    newnode->data = data;
    
    newnode->llink = before;
    newnode->rlink = before->rlink;
    before->rlink->llink = newnode;
    before->rlink = newnode;
}

void deleteNode(dListNode* head, dListNode* removed)
{
    if(removed == head)
        return;
    removed->llink->rlink = removed->rlink;
    removed->rlink->llink = removed->llink;
    free(removed);
}

dListNode* search(dListNode* head, int data)
{
    dListNode* p;
    for(p = head->rlink; p != head; p = p->rlink)
    {
        if(p->data == data)
            return p;
    }
    return NULL;
}

int main(void)
{
    dListNode* head = (dListNode*)malloc(sizeof(dListNode));
    init(head);

    print(head);
    insert(head, 100);
    print(head);
    insert(head->llink, 200);
    print(head);
    insert(head->llink, 300);
    print(head);

    dListNode* p;
    p = search(head, 200);
    printf("%d\n", p);

    deleteNode(head, search(head, 200));
    print(head);
    deleteNode(head, search(head, 100));
    print(head);
    deleteNode(head, search(head, 300));
    print(head);

    if (head != NULL)
        free(head);

    return 0;
}