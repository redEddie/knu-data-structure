#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef char element[100];
typedef struct ListNode { 
    element data;
    struct ListNode *link;
} ListNode;


ListNode* insert_first(ListNode* head, element data){
    ListNode *node = (ListNode*)malloc(sizeof(ListNode));
    strcpy(node->data, data);;;
    if(head == NULL){
        head = node;
        node->link = head;
    } else{
        node->link = head->link;
        head->link = node;
    }
    return head;
}


int main(void){
    ListNode *head = NULL;

    head = insert_first(head, "apple");
    head = insert_first(head, "orange");
    head = insert_first(head, "kiwi");

    ListNode *p = head;
    for (; p->link != head; ){
        printf("%s -> ", p->data);
        p = p->link;
    }
    printf("%s \n", p->data);
}