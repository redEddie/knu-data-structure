#include <stdio.h>
#include <stdlib.h>

#define MAX_QUEUE_SIZE 100

typedef struct {
    int data[MAX_QUEUE_SIZE];
    int front;
    int rear;
} Queue;

void initQueue(Queue* q)
{
    q->front = 0;
    q->rear = 0;
}

int isEmpty(Queue* q)
{
    return (q->front == q->rear);
}

int isFull(Queue* q)
{
    return ((q->rear + 1) % MAX_QUEUE_SIZE == q->front);
}

void enqueue(Queue* q, int item)
{
    if (isFull(q)) {
        printf("큐가 가득 찼습니다.\n");
        return;
    }
    q->rear = (q->rear + 1) % MAX_QUEUE_SIZE;
    q->data[q->rear] = item;
}

int dequeue(Queue* q)
{
    if (isEmpty(q)) {
        printf("큐가 비어있습니다.\n");
        return -1;
    }
    q->front = (q->front + 1) % MAX_QUEUE_SIZE;
    return q->data[q->front];
}

void BFS(int** graph, int numVertices, int startVertex)
{
    int* visited = (int*)malloc(numVertices * sizeof(int));
    Queue queue;
    initQueue(&queue);
    
    for (int i = 0; i < numVertices; i++) {
        visited[i] = 0;
    }

    visited[startVertex] = 1;
    printf("%d ", startVertex);

    enqueue(&queue, startVertex);
    while (!isEmpty(&queue)) {
        int currentVertex = dequeue(&queue);
        for (int i = 0; i < numVertices; i++) {
            if (graph[currentVertex][i] == 1 && visited[i] == 0) {
                visited[i] = 1;
                printf("%d ", i);
                enqueue(&queue, i);
            }
        }
    }

    free(visited);
}

int main(void)
{
    int numVertices = 8;
    int** graph = (int**)malloc(numVertices * sizeof(int*));
    for (int i = 0; i < numVertices; i++) {
        graph[i] = (int*)malloc(numVertices * sizeof(int));
    }

    // 그래프 초기화
    for (int i = 0; i < numVertices; i++) {
        for (int j = 0; j < numVertices; j++) {
            graph[i][j] = 0;
        }
    }

    // 그래프 연결
    graph[0][1] = graph[0][2] = graph[1][3] = graph[1][4] = graph[2][5] = graph[2][6] = graph[4][7] = 1;

    // BFS 실행
    printf("BFS 순회 결과: ");
    BFS(graph, numVertices, 0);
    printf("\n");

    // 그래프 해제
    for (int i = 0; i < numVertices; i++) {
        free(graph[i]);
    }
    free(graph);

    return 0;
}
