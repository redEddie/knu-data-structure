#include <stdio.h>

typedef struct {
    char name[10];
    int age;
    float salary;
    int *stk;
} InStack;

typedef struct {
    float real;
    float imag;
} complex;

complex complex_add(complex a, complex b);

int main() {
    complex c1, c2;

    c1.real = 1.0;
    c1.imag = 2.0;
    c2.real = 3.0;
    c2.imag = 4.0;

    complex c3 = complex_add(c1, c2);

    printf("     c1 = %f + i%f\n", c1.real, c1.imag);
    printf("     c2 = %f + i%f\n", c2.real, c2.imag);
    printf("c1 + c2 = %f + i%f\n", c3.real, c3.imag);
    
    return 0;
}

complex complex_add(complex a, complex b) {
    return (complex){a.real + b.real, a.imag + b.imag};
}
