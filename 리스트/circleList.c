#include <stdio.h>
#include <stdlib.h>


typedef struct listNode{
    int data;
    struct listNode *link;
} listNode;

listNode* create(int data){
    listNode* node = (listNode *)malloc(sizeof(listNode));
    node->data = data;
    node->link = NULL;
    return node;
}

listNode* insertFirst(listNode* head, int data){
    listNode* node = (listNode *)malloc(sizeof(listNode));
    node->data = data;
    if (head == NULL){
        head = node;
        node->link = head;
    } else{

        node->link = head->link;  // 첫노드이기 때문에 노드가 가리킬 곳이 첫 노드의 위치여야하고
        head->link = node;        // 헤드가 가리키는 곳은 새로운 끝 노드가 된다.
    }
    return head;
}

listNode* insertLast(listNode* head, int data){
    listNode* node = (listNode *)malloc(sizeof(listNode));
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

void print(listNode* head){
    listNode* temp = head->link;

    for(;temp != head;){
        printf("%d ", temp->data);
        temp = temp->link;
    }
    printf("%d ", head->data);
}

void print_list(listNode *head)
{
    listNode *p = head;
	for (int a = 0; a<10; a++){
        p = p->link;    // 먼저 해주면 첫 노드부터 출력함.
		printf("%d->", p->data);
    }    
	printf("뚱 \n");
}

int main(){
    // listNode* head = create(0);
    // listNode* head = (listNode*)malloc(sizeof(listNode));
    listNode* head = NULL;
    // head->link = head;


    // listNode *head = NULL;

    head = insertFirst(head, 1);        // 업데이트된 헤드를 안 받아서 큰일난 거였다.!!!!
    head = insertFirst(head, 2);
    head = insertFirst(head, 3);
    head = insertFirst(head, 4);
    head = insertLast(head, 11);
    head = insertLast(head, 12);

    print(head);
    printf("\n");

    print_list(head);
    printf("\n");

    printf("%d ", head->data);              // 끝노드
    printf("%d ", head->link->data);        // 첫노드
    printf("%d ", head->link->link->data);  // 두번째 노드
    printf("\n");
}