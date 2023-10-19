#include <stdio.h>
#include <stdlib.h> 
#include <time.h>

void insert(int list[], int first, int last, int gap)
{
    int i, j, key;
    for (i = first + gap; i <= last; i = i + gap){
        key = list[i];
        for (j = i - gap; j >= first && list[j] > key; j = j - gap){
            list[j + gap] = list[j];
        }
        list[j + gap] = key;
    }
}

void shell1(int list[], int n)
{
    int i, gap;
    for (gap = n / 2; gap > 0; gap = gap / 2){
        if ((gap % 2) == 0){
            gap++;
        }
        for (i = 0; i < gap; i++){
            insert(list, i, n - 1, gap);
        }
    }
}


void shell2(int list[], int n)
{
    int i, gap;
    for (gap = n / 2; gap > 0; gap = gap / 2){
        if(gap == 1){
        }
        else if ((gap % 2) == 1){
            gap++;
        }
        for (i = 0; i < gap; i++){
            insert(list, i, n - 1, gap);
        }
    }
}




int main(){
    srand(time(NULL));

    int n = 10;

    int list1[n];
    for (int i = 0; i < n; i++){
        list1[i] = rand() % 100;
    }

    int list2[n];
    list2[n] = list1[n];

    shell1(list1, n);
    shell2(list2, n);


    for (int i = 0; i < n; i++){
        printf("%d ", list1[i]);
    }
    printf ("\n");

    for (int i = 0; i < n; i++){
        printf("%d ", list2[i]);
    }
    printf ("\n");

    return 0;
}