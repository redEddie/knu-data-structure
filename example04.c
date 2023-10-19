#include <stdio.h>



int main(){

    int two[10];
    
    for (int i = 0; i < 10; i++)
        two[i] = 20 + i;

    for (int i = 0; i < 10; i++)
        printf("%d\n", two[i]);

}