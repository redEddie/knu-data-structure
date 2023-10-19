#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 20

typedef struct {
    int data[MAX_SIZE];
    int size;
} LinearList;

void initializeList(LinearList *list) {
    list->size = 0;
}

void printList(const LinearList *list) {
    printf("List elements: ");
    for (int i = 0; i < list->size; i++) {
        printf("%d ", list->data[i]);
    }
    printf("\n");
}

void addElement(LinearList *list, int element) {
    if (list->size < MAX_SIZE) {
        list->data[list->size] = element;
        list->size++;
        printf("Element added successfully.\n");
    } else {
        printf("List is full. Cannot add element.\n");
    }
}

void insertElement(LinearList *list, int element, int location) {
    if (list->size < MAX_SIZE) {
        for (int i = list->size; i > location; i--) {
            list->data[i] = list->data[i - 1];
        }
        list->data[location] = element;
        list->size++;
        printf("Element inserted successfully.\n");
    } else {
        printf("List is full. Cannot insert element.\n");
    }
}

void deleteElement(LinearList *list, int element) {
    int found = 0;
    for (int i = 0; i < list->size; i++) {
        if (list->data[i] == element) {
            for (int j = i; j < list->size - 1; j++) {
                list->data[j] = list->data[j + 1];
            }
            list->size--;
            found = 1;
            break;
        }
    }
    if (found) {
        printf("Element deleted successfully.\n");
    } else {
        printf("Element not found in the list.\n");
    }
}

int main() {
    LinearList list;
    initializeList(&list);

    int choice, element;

    while (1) {
        printf("1. Add element\n");
        printf("2. Insert element\n");
        printf("3. Delete element\n");
        printf("4. Print list\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter element to add: ");
                scanf("%d", &element);
                addElement(&list, element);
                break;
            case 2:
                printf("Enter element to insert: ");
                scanf("%d", &element);
                printf("Enter location: ");
                int location;
                scanf("%d", &location);
                insertElement(&list, element, location);
                break;
            case 3:
                printf("Enter element to delete: ");
                scanf("%d", &element);
                deleteElement(&list, element);
                break;
            case 4:
                printList(&list);
                break;
            case 5:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    }

    return 0;
}
