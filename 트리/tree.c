#include <stdio.h>
#include <stdlib.h>

// 노드 구조체 정의
typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
} Node;

// 새로운 노드 생성 함수
Node* createNode(int data)
{
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("메모리 할당에 실패했습니다.\n");
        exit(1);
    }
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

int printNode(Node* node)
{
    printf("%d\n", node->data);
    return 0;
}

void inOrder(Node* root)
{
    if (root == NULL) {
        return;
    }
    inOrder(root->left);
    printNode(root);
    inOrder(root->right);
}

void preOrder(Node* root)
{
    if (root == NULL) {
        return;
    }
    printNode(root);
    preOrder(root->left);
    preOrder(root->right);
}

void postOrder(Node* root)
{
    if (root == NULL) {
        return;
    }
    postOrder(root->left);
    postOrder((root->right));
    printNode(root);
};;;;;;;;;


int main(void)
{
    // 노드 생성
    Node* root = createNode(1);
    Node* node2 = createNode(2);
    Node* node3 = createNode(3);

    // 트리 구성
    root->left = node2;
    root->right = node3;

    // 트리 출력
    printf("트리 구조:\n");
    printf("   %d\n", root->data);
    printf("  / \\\n");
    printf(" %d   %d\n", root->left->data, root->right->data);


    printf("\n전위 순회: ");
    preOrder(root);

    printf("\n중위 순회: ");
    inOrder(root);

    printf("\n후위 순회: ");
    postOrder(root);

    // 메모리 해제
    free(node2);
    free(node3);
    free(root);

    return 0;
}
