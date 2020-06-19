#include <stdio.h>

#define MAX(a, b) ({ \
    __typeof(a) _a = (a); \
    __typeof(b) _b = (b); \
    _a > _b ? _a : _b; \
})

#ifdef DEBUG
#define P(a) { \
    printf("[%s : %d] %s = %d\n", __func__, __LINE__, #a, a); \
}
#else
#define P(a)
#endif

int main() {
    int a = 7;
    P(MAX(2, 3));
    P(5 + MAX(2, 3));
    P(MAX(2, MAX(3, 4)));
    P(MAX(2, 3 > 4 ? 3 : 4));
    P(MAX(a++, 6));
    P(a);
    return 0;
}
