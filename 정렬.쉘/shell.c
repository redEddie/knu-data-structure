#include <stdio.h>
#include <stdlib.h>

void insert(int list[], int first, int last, int gap)
{
    int i, j, key;
    for (i = first + gap; i <= last; i = i + gap){
        key = list[i];
        for (j = i - gap; j >= first && list[j] > key; j = j - gap){    // 어차피 i가 커지면서 모든 부분리스트를 비교함.
            list[j + gap] = list[j];
        }
        list[j + gap] = key;        // 바꾸는 경우 얘가 꼭 필요함.
    }
}

void shell(int list[], int n)
{
    int i, gap;
    for (gap = n / 2; gap > 0; gap = gap / 2){
        if ((gap % 2) == 0){
            gap++;
        }
        for (i = 0; i < gap; i++){
            int temp[n];
            for(int j = 0; j < n; j++){
                temp[j] = list[j];
            }
            insert(list, i, n - 1, gap);

            printf("gap = %d, i = %d\n", gap, i);
            for(int j = 0; j < n; j++){
                printf("%d ", temp[j]);
            }
            printf("\n");
            for (int j = 0; j < n; j++){
                printf("%d ", list[j]);
            }
            printf("\n\n");
        }
    }
}

int main(){
    int n = 11;

    int list1[n];
    for (int i = 0; i < n; i++){
        list1[i] = 20 - i;
    }

    shell(list1, n);

    for (int i = 0; i < n; i++){
        printf("%d ", list1[i]);
    }
    printf("\n");
    return 0;
}