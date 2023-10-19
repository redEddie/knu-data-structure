#include <stdio.h>
#include <stdlib.h>

// 이진 트리 노드 정의
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// 스택 구조체 정의
struct StackNode {
    struct Node* node;
    struct StackNode* next;
};

// 스택 기능: push, pop, isEmpty
void push(struct StackNode** top, struct Node* node) {
    struct StackNode* stackNode = (struct StackNode*)malloc(sizeof(struct StackNode));
    stackNode->node = node;
    stackNode->next = *top;
    *top = stackNode;
}

struct Node* pop(struct StackNode** top) {
    if (*top == NULL)
        return NULL;
    struct Node* node = (*top)->node;
    // struct StackNode* temp = *top;
    *top = (*top)->next;
    // free(temp);
    return node;
}

int isEmpty(struct StackNode* top) {
    return top == NULL;
}

// 이진 트리에 노드 삽입
struct Node* insertNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// 이진 트리의 깊이 우선 탐색 (DFS) 반복 알고리즘
void dfsIterative(struct Node* root) {
    if (root == NULL)
        return;
  
    struct StackNode* stack = NULL;
    push(&stack, root);
  
    while (!isEmpty(stack)) {
        struct Node* node = pop(&stack);
        printf("%d ", node->data);
  
        if (node->right != NULL)
            push(&stack, node->right);
  
        if (node->left != NULL)
            push(&stack, node->left);
    }
}

int main() {
    // 이진 트리 생성
    struct Node* root = insertNode(1);
    root->left = insertNode(2);
    root->right = insertNode(3);
    root->left->left = insertNode(4);
    root->left->right = insertNode(5);
  
    printf("DFS(깊이 우선 탐색): ");
    dfsIterative(root);
  
    return 0;
}
