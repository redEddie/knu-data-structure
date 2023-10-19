#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int *data;
    int capacity;
    int top;
} StackType;

void init_stack(StackType *s, int capacity)
{
    s->top = -1;
    s->capacity = capacity;
    s->data = (int *)malloc(capacity * sizeof(int));
}

void push(StackType *s, int item)
{
    s->data[++(s->top)] = item;
}

int pop(StackType *s)
{
    return s->data[(s->top)--];
}

int peek(StackType *s)
{
    return s->data[s->top];
}

int main(void)
{
    StackType s;
    init_stack(&s, 5);
    push(&s, 1);
    push(&s, 2);
    push(&s, 3);
    
    printf("Before pop: peek = %d, top = %d\n", peek(&s), s.top);
    
    pop(&s);
    
    printf("After pop: peek = %d, top = %d\n", peek(&s), s.top);
    
    return 0;
}
