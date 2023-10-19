#include <stdio.h>
#include <stdlib.h>

typedef struct TreeNode {
    int data;
    struct TreeNode* left;
    struct TreeNode* right;
} TreeNode;

typedef struct QueueNode {
    TreeNode* data;
    struct QueueNode* next;
} QueueNode;

typedef struct {
    QueueNode* front;
    QueueNode* rear;
} Queue;

void initQueue(Queue* q)
{
    q->front = NULL;
    q->rear = NULL;
}

int isEmpty(Queue* q)
{
    return (q->front == NULL);
}

void enqueue(Queue* q, TreeNode* item)
{
    QueueNode* newNode = (QueueNode*)malloc(sizeof(QueueNode));
    if (newNode == NULL) {
        printf("메모리 할당에 실패했습니다.\n");
        exit(1);
    }
    newNode->data = item;
    newNode->next = NULL;

    if (isEmpty(q)) {
        q->front = newNode;
        q->rear = newNode;
    }
    else {
        q->rear->next = newNode;
        q->rear = newNode;
    }
}

TreeNode* dequeue(Queue* q)
{
    if (isEmpty(q)) {
        printf("큐가 비어있습니다.\n");
        return NULL;
    }

    QueueNode* frontNode = q->front;
    TreeNode* data = frontNode->data;

    q->front = q->front->next;
    free(frontNode);

    if (q->front == NULL) {
        q->rear = NULL;
    }

    return data;
}

void BFS(TreeNode* root)
{
    if (root == NULL) {
        printf("트리가 비어있습니다.\n");
        return;
    }

    Queue queue;
    initQueue(&queue);
    enqueue(&queue, root);

    while (!isEmpty(&queue)) {
        TreeNode* node = dequeue(&queue);
        printf("%d ", node->data);

        if (node->left != NULL) {
            enqueue(&queue, node->left);
        }
        if (node->right != NULL) {
            enqueue(&queue, node->right);
        }
    }
}

int main(void)
{
    // 트리 노드 생성
    TreeNode* root = (TreeNode*)malloc(sizeof(TreeNode));
    TreeNode* node2 = (TreeNode*)malloc(sizeof(TreeNode));
    TreeNode* node3 = (TreeNode*)malloc(sizeof(TreeNode));
    TreeNode* node4 = (TreeNode*)malloc(sizeof(TreeNode));
    TreeNode* node5 = (TreeNode*)malloc(sizeof(TreeNode));
    TreeNode* node6 = (TreeNode*)malloc(sizeof(TreeNode));
    TreeNode* node7 = (TreeNode*)malloc(sizeof(TreeNode));

    // 트리 구성
    root->data = 1;
    node2->data = 2;
    node3->data = 3;
    node4->data = 4;
    node5->data = 5;
    node6->data = 6;
    node7->data = 7;

    root->left = node2;
    root->right = node3;
    node2->left = node4;
    node2->right = node5;
    node3->left = node6;
    node3->right = node7;
    node4->left = NULL;
    node4->right = NULL;
    node5->left = NULL;
    node5->right = NULL;
    node6->left = NULL;
    node6->right = NULL;
    node7->left = NULL;
    node7->right = NULL;

    // BFS 실행
    printf("BFS 결과: ");
    BFS(root);
    printf("\n");

    // 트리 노드 해제
    free(root);
    free(node2);
    free(node3);
    free(node4);
    free(node5);
    free(node6);
    free(node7);

    return 0;
}
