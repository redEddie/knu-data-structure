#include <stdio.h>
#include <stdlib.h>

#define MAX_STACK_SIZE 100

typedef int element;
typedef struct {
    element *data;
    int capacity;
    int top;
} StackType;

void init_stack(StackType *s)
{
    s->top = -1;
    s->capacity = 1;
    s->data = (element *)malloc(s->capacity * sizeof(element));
}

int is_empty(StackType *s)
{
    // if (s->top == -1) printf("Stack is empty\n");
    return (s->top == -1);
}

int is_full(StackType *s)
{
    return (s->top == (s->capacity - 1));
}

void push(StackType *s, element item)
{
    if (is_full(s)) {
        s->capacity *= 2;
        s->data = (element *)realloc(s->data, s->capacity * sizeof(element));
    }
    s->data[++(s->top)] = item;
}

element pop(StackType *s)
{
    if (is_empty(s)) {
        fprintf(stderr, "Stack is Empty\n");
        exit(1);
    }
    return s->data[(s->top)--];
}

element peek(StackType *s)
{
    if (is_empty(s)) {
        fprintf(stderr, "Stack is Empty\n");
    }
    return s->data[s->top];
}

void print_stack(StackType *s)
{
    StackType temp_stack;
    init_stack(&temp_stack);
    temp_stack = *s;
    while (!is_empty(&temp_stack)) {
        printf("%d ", peek(&temp_stack));
        pop(&temp_stack);
    }
    printf("\n");
}

int search(StackType *s, int value)
{
    StackType temp_stack;
    init_stack(&temp_stack);
    temp_stack = *s;
    int index = 0;
    while (!is_empty(&temp_stack)) {
        if (peek(&temp_stack) == value) {
            return index;
        }
        pop(&temp_stack);
        index++;
    }
    return -1;
}

void remove_duplicates(StackType *s)
{
    StackType temp_stack;
    init_stack(&temp_stack);

    while (!is_empty(s)) {
        int value = pop(s);
        if (search(&temp_stack, value) == -1) {
            push(&temp_stack, value);
        }
    }
    printf("중복 삭제가 끝났습니다.\n");
    // Reverse the elements back to the original stack

    print_stack(&temp_stack);
    printf("원래 스택에 할당합니다.\n");
    while (!is_empty(&temp_stack)) {
        push(s, pop(&temp_stack));
    }
}

int main(void)
{
    StackType s;
    init_stack(&s);
    push(&s, 1);
    push(&s, 2);
    push(&s, 2);
    push(&s, 3);
    push(&s, 3);
    push(&s, 4);
    push(&s, 4);
    push(&s, 5);
    push(&s, 1);
    push(&s, 2);
    push(&s, 2);
    push(&s, 3);
    push(&s, 3);
    push(&s, 4);
    push(&s, 4);
    push(&s, 5);
    
    printf("Original Stack: ");
    while (!is_empty(&s)) {
        printf("%d ", peek(&s));
        pop(&s);
    }
    printf("\n");
    
    push(&s, 1);
    push(&s, 2);
    push(&s, 2);
    push(&s, 3);
    push(&s, 3);
    push(&s, 4);
    push(&s, 4);
    push(&s, 5);
    push(&s, 1);
    push(&s, 2);
    push(&s, 2);
    push(&s, 3);
    push(&s, 3);
    push(&s, 4);
    push(&s, 4);
    push(&s, 5);
    
    remove_duplicates(&s);
    
    printf("Stack with Duplicates Removed: ");
    print_stack(&s);
    printf("\n");
    
    free(s.data);
    
    return 0;
}
