#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int max;
    int num;
    int *que;
} IntQueue;

int Initialize(IntQueue *q, int max) {
    q->num = 0;
    if ((q->que = (int *)calloc(max, sizeof(int))) == NULL) {
        q->max = 0;
        return -1;
    }
    q->max = max;
    return 0;
}

int Enque(IntQueue *q, int x) {
    if (q->num >= q->max) {
        return -1;
    }
    q->que[q->num++] = x;
    return 0;
}

int Deque(IntQueue *q, int *x) {
    if (q->num <= 0) {
        return -1;
    }
    *x = q->que[0];
    for (int i = 0; i < q->num - 1; i++) {
        q->que[i] = q->que[i + 1];
    }
    q->num--;
    return 0;
}

int Peek(const IntQueue *q, int *x) {
    if (q->num <= 0) {
        return -1;
    }
    *x = q->que[0];
    return 0;
}

int Capacity(const IntQueue *q) {
    return q->max;
}

int Size(const IntQueue *q) {
    return q->num;
}

int IsEmpty(const IntQueue *q) {
    return q->num <= 0;
}

int IsFull(const IntQueue *q) {
    return q->num >= q->max;
}

int Search(const IntQueue *q, int x) {
    for (int i = 0; i < q->num; i++) {
        if (q->que[i] == x) {
            return i;
        }
    }
    return -1;
}

void Print(const IntQueue *q) {
    for (int i = 0; i < q->num; i++) {
        printf("%d ", q->que[i]);
    }
    putchar('\n');
}

void Terminate(IntQueue *q) {
    if (q->que != NULL) {
        free(q->que);
    }
    q->max = q->num = 0;
}

int main(void) {
    IntQueue que;
    if (Initialize(&que, 64) == -1) {
        puts("큐 생성에 실패했습니다.");
        return 1;
    }
    while (1) {
        int m, x;
        printf("현재 데이터 수 : %d / %d\n", Size(&que), Capacity(&que));
        printf("(1)인큐 (2)디큐 (3)피크 (4)출력 (0)종료 : ");
        scanf("%d", &m);
        if (m == 0) {
            break;
        }
        switch (m) {
            case 1:
                printf("데이터 : ");
                scanf("%d", &x);
                if (Enque(&que, x) == -1) {
                    puts("\a오류 : 인큐에 실패했습니다.");
                }
                break;
            case 2:
                if (Deque(&que, &x) == -1) {
                    puts("\a오류 : 디큐에 실패했습니다.");
                } else {
                    printf("디큐한 데이터는 %d입니다.\n", x);
                }
                break;
            case 3:
                if (Peek(&que, &x) == -1) {
                    puts("\a오류 : 피크에 실패했습니다.");
                } else {
                    printf("피크한 데이터는 %d입니다.\n", x);
                }
                break;
            case 4:
                Print(&que);
                break;
        }
    }
    Terminate(&que);
    return 0;
}