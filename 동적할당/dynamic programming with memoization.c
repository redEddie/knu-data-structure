#include <stdio.h>
int d[100];
int fibonacci (int x) {
    if (x == 1) return 1; if (x == 2) return 1;
    if (d[x] != 0) return d[x];
    return d[x] = fibonacci (x - 1) + fibonacci (x - 2);
}


int main(void) {
    printf ("%d", fibonacci (30));
}

// 피보나치를 배열에 저장하면 연산량이 줄어 들어 시간복잡도가 O(n)이다.