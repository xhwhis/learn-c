#include <stdio.h>

#define swap (a,b); {\
    __typeof (a) temp = a;\
    a = b;\
    b = temp;\
}

int main() {
    int a, b;
    scanf("%d%d", &a, &b);
    swap(a, b);
    printf("%d %d", a, b);
    return 0;
}
