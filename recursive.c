#include <stdio.h>

int one(int n){
    if (n == 1){
        return 1;
    }
    else{
        return n + one(n - 1);
    }
}

int sum(int a, int b){
    return a + b;
}

int onev2(int n){
    if (n == 1){
        return 1;
    }
    else{
        int r = sum(n, onev2(n - 1));
        printf("%d\n", r);
        return r;
    }
}

int main(){
    printf("recursive : \n");
    printf("%d\n\n", one(10));


    printf("iterative : \n");
    int temp = 0;
    for (int i = 0; i < 11; i++){
        temp += i;
        printf("%d\n", temp);
    }

    printf("indirect recursive : \n");
    printf("%d\n", onev2(10));
    return 0;
}