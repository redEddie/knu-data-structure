#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int* x = (int *)calloc(1, sizeof(int));
    if (x == NULL) {
        printf("메모리 할당에 실패했습니다.\n");
    } else {
        *x = 57;
        printf("*x = %d\n", *x);
        free(x);
    }
}


/*
// int* 와 int * 는 같다.
int* ptr1;  // int 형식의 포인터 변수 ptr1 선언
int *ptr2;  // int 형식의 포인터 변수 ptr2 선언
*/
