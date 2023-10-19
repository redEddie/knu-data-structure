#include <stdio.h>
int d(int x) {
    if (x == 1) return 1; 
    if (x == 2) return 1;
    return d(x - 1) + d(x - 2) ;
}


int main (void) {
    printf ("%d", d (10));
}


// 피보나치를 재귀함수로 구현하면 시간복잡도가 O(2^n)이다.