# include <stdio.h>
# include <stdlib.h>

int partition(int list[], int left, int right) {
    int pivot = list[left];
    int i = left + 1;
    int j = right;

    while (i <= j) {
        while (list[i] <= pivot) {
            i++;
        }
        while (list[j] > pivot) {
            j--;
        }
        if (i <= j) {
            int temp = list[i];
            list[i] = list[j];
            list[j] = temp;
        }
    }

    list[left] = list[j];       // 처음 Left는 값이 변화하지 않아 pivot 그 자체이다. 따라서 pivot을 j에 넣어준다.
    list[j] = pivot;

    return j;
}

void quickSort(int list[], int left, int right) {
    if (left < right) {
        int pivot = partition(list, left, right);
        quickSort(list, left, pivot - 1);
        quickSort(list, pivot + 1, right);
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

    quickSort(list, 0, n-1);

    check(list, n);

    return 0;
}