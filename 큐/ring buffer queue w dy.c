#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int *buffer;
    int front;
    int rear;
    int count;
    int size;
} Queue;

void initialize(Queue *queue, int size) {
    queue->buffer = (int *)malloc(size * sizeof(int));
    queue->front = 0;
    queue->rear = 0;
    queue->count = 0;
    queue->size = size;
}

int is_empty(Queue *queue) {
    return (queue->count == 0);
}

int is_full(Queue *queue) {
    return (queue->count == queue->size);
}

void enqueue(Queue *queue, int item) {
    if (is_full(queue)) {
        printf("Queue is full. Cannot enqueue.\n");
        return;
    }

    queue->buffer[queue->rear] = item;
    queue->rear = (queue->rear + 1) % queue->size;
    queue->count++;
}

int dequeue(Queue *queue) {
    if (is_empty(queue)) {
        printf("Queue is empty. Cannot dequeue.\n");
        return -1;
    }

    int item = queue->buffer[queue->front];
    queue->front = (queue->front + 1) % queue->size;
    queue->count--;

    return item;
}

void deallocate(Queue *queue) {
    if (queue->buffer != NULL)
        (queue->buffer);
    queue->count = 0;
    queue->front = 0;
    queue->rear = 0;
    queue->size = 0;
}

void printQueue(Queue *queue) {
    printf("Queue: ");
    
    if (is_empty(queue)) {
        printf("Empty\n");
        return;
    }

    int i = queue->front;
    while (i != queue->rear) {
        printf("%d ", queue->buffer[i]);
        i = (i + 1) % queue->size;
    }
    printf("\n");
}

int main() {
    Queue queue;
    int size = 8;
    initialize(&queue, size);

    int choice;
    int item;

    do {
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Print Queue\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter item to enqueue: ");
                scanf("%d", &item);
                enqueue(&queue, item);
                break;
            case 2:
                item = dequeue(&queue);
                if (item != -1) {
                    printf("Dequeued item: %d\n", item);
                }
                break;
            case 3:
                printQueue(&queue);
                break;
            case 4:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }

        printf("\n");
    } while (choice != 4);

    deallocate(&queue);

    return 0;
}
