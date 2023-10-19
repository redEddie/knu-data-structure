#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
} Node;

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

void printNode(Node* node)
{
    printf("%d ", node->data);
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
    postOrder(root->right);
    printNode(root);
}

void inorder_iter(Node* root)
{
    int top = -1;
    Node* stack[100];

    while (1) {
        for (; root; root = root->left)
            stack[++top] = root;
        root = stack[top--];
        if (!root)
            break;
        printNode(root);
        root = root->right;
    }
}

void preorder_iter(Node* root)
{
    int top = -1;
    Node* stack[100];

    while (1) {
        while (root) {
            stack[++top] = root;
            printNode(root);
            root = root->left;
        }
        if (top == -1)
            break;
        root = stack[top--];
        root = root->right;
    }
}

void preorder_iter(Node* root)
{
    int top = -1;
    Node* stack[100];

    while (1) {
        while (root) {
            stack[++top] = root;
            root = root->left;
        }
        if (top == -1)
            break;
        root = stack[top--];
        root = root->right;
        printNode(root);
    }
}


int main(void)
{
    Node* root = createNode(1);
    Node* node2 = createNode(2);
    Node* node3 = createNode(3);

    root->left = node2;
    root->right = node3;

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

    printf("\n중위 순회 (반복): ");
    inorder_iter(root);
    
    printf("\n전위 순회 (반복): ");
    preorder_iter(root);
    
    free(node2);
    free(node3);
    free(root);

    return 0;
}
