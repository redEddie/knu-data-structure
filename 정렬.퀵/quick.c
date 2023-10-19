#include <stdio.h>
#include <stdlib.h>

#define SWAP(temp, a, b) ((temp = a), (a = b), (b = temp))
// #define SWAP(temp, a, b) (temp = a); (a = b); (b = temp);

int partition(int list[], int left, int right)
{
    int temp; int pivot; int low; int high;

    low = left;
    high = right + 1;
    pivot = list[left];

    do {
        do{
            low++;          // low가 커지면서 피벗보다 큰 값을 찾음.
        } while ((list[low] < pivot) && (low <= right));        // 역순이므로 이 케이스에서는 피벗보다 작은 값이 없음. 따라서 이 코드는 건너뜀.
        do{
            high--;         // high가 작아지면서 피벗보다 작은 값을 찾음.
        } while ((list[high] > pivot) && (high >= left));       // 역순이니까 항상 동작하다가 high가 low보다 작아지면 멈춤.
        if (low < high){
            SWAP(temp, list[low], list[high]);      // 만약 low와 high가 교차하지 않았다면 두 값을 교환.
        }
    } while (low < high);       // 아직 교차하지 않았으면 계속 반복.
    
    SWAP(temp, list[left], list[high]);    // high가 low보다 작아졌을 때 high와 피벗(left)을 교환.
    return high;        // high가 반환되는건 low가 high보다 커졌을 때이므로 high가 피벗의 위치임. Low를 반환해도 상관없음.
}

void quick(int list[], int left, int right)
{
    if (left < right){
        int q = partition(list, left, right);
        quick(list, left, q - 1);
        quick(list, q + 1, right);
    }
}


void check(int list[], int size)
{
    for (int i = 0; i < size; i++){
        printf("%d ", list[i]);
    }
    printf("\n");
}


int main()
{
    int n = 10;

    int list[n];

    list[0] = 1;
    for (int i = 1; i < n-1; i++){
        list[i] = 20-i;
    }
    list[n-1] = 30;

    check(list, n);

    quick(list, 0, n-1);

    check(list, n);

    return 0;
}