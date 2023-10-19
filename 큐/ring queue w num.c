#include <stdio.h>

#define MAX_QUEUE_SIZE 8

typedef struct {
    int buffer[MAX_QUEUE_SIZE];
    int front;
    int rear;
    int count;
} Queue;

void initialize(Queue *queue) {
    queue->front = 0;
    queue->rear = 0;
    queue->count = 0;
}

int is_empty(Queue *queue) {
    return (queue->count == 0);
}

int is_full(Queue *queue) {
    return (queue->count == MAX_QUEUE_SIZE);
}

void enqueue(Queue *queue, int item) {
    if (is_full(queue)) {
        printf("Queue is full. Cannot enqueue.\n");
        return;
    }

    queue->buffer[queue->rear] = item;
    queue->rear = (queue->rear + 1) % MAX_QUEUE_SIZE;
    queue->count++;
}

int dequeue(Queue *queue) {
    if (is_empty(queue)) {
        printf("Queue is empty. Cannot dequeue.\n");
        return -1;
    }

    int item = queue->buffer[queue->front];
    queue->front = (queue->front + 1) % MAX_QUEUE_SIZE;
    queue->count--;

    return item;
}

void printQueue(Queue *queue) {
    printf("Queue: ");
    if (is_empty(queue)) {
        printf("Empty\n");
        return;
    }

    int i = queue->front;
    int count = 0;
    while (count < queue->count) {
        printf("%d ", queue->buffer[i]);
        i = (i + 1) % MAX_QUEUE_SIZE;
        count++;
    }
    printf("\n");
}

int search(Queue *queue, int value) {
    if (is_empty(queue)) {
        printf("Queue is empty. Cannot search.\n");
        return -1;
    }

    int i = queue->front;
    int count = 0;
    while (count < queue->count) {
        if (queue->buffer[i] == value) {
            return count;
        }

        i = (i + 1) % MAX_QUEUE_SIZE;
        count++;
    }

    return -1; // Value not found
}

int main() {
    Queue queue;
    initialize(&queue);

    int choice;
    int item;

    do {
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Print Queue\n");
        printf("4. Search\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                if (is_full(&queue)) {
                    printf("Queue is full. Cannot enqueue.\n");
                } else {
                    printf("Enter item to enqueue: ");
                    scanf("%d", &item);
                    enqueue(&queue, item);
                }
                break;
            case 2:
                if (is_empty(&queue)) {
                    printf("Queue is empty. Cannot dequeue.\n");
                } else {
                    item = dequeue(&queue);
                    printf("Dequeued item: %d\n", item);
                }
                break;
            case 3:
                printQueue(&queue);
                break;
            case 4:{
                printf("Enter item to search: ");
                scanf("%d", &item);
                int index = search(&queue, item);
                if (index == -1) {
                    printf("Item not found.\n");
                } else {
                    printf("Item found at index %d.\n", index+1);
                }
                break;
            }
            case 5:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }

        printf("\n");
    } while (choice != 5);

    return 0;
}
