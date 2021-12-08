#include "stdio.h"

typedef void (^callback)(int a, int b);

int main() {
    callback fun;
    const char *str = "hello world";
    printf("%lu\n", sizeof(fun));
    printf("%lu\n", sizeof(str));
    return 0;
}
