#include <stdio.h>

int main() {
    printf("char: %zu 바이트\n", sizeof(char));
    printf("int: %zu 바이트\n", sizeof(int));
    printf("short: %zu 바이트\n", sizeof(short));
    printf("long: %zu 바이트\n", sizeof(long));
    printf("float: %zu 바이트\n", sizeof(float));
    printf("double: %zu 바이트\n", sizeof(double));
    // printf("void: %zu 바이트\n", sizeof(void));

    return 0;
}
