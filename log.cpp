#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define COLOR(a, b) "\033[" #b "m" a "\033[0m"
#define RED(a) COLOR(a, 31)
#define BLUE(a) COLOR(a, 34)
#define GREEN(a) COLOR(a, 32)
#define YELLOW(a) COLOR(a, 33)

#ifndef DEBUG
#define log(frm, args...) { \
    printf("\033[1;31m[%s : %d]\033[0m ", __func__, __LINE__); \
    printf(frm, ##args); \
    printf("\n"); \
}
#else
#define log(frm, args...)
#endif

#define __contact(a, b) a##b
#define contact(a, b) __contact(a, b)
#define ABS(x) _Generic((x), \
    int : abs(x), \
    double : fabs(x), \
    default: fabs(x) \
)

int main() {
    int a = 7, abc, def, ab, c, de, f;
    int abcdef = 19;
    log(RED("%d"), a);
    log(GREEN("hello") " " RED("world"));
    log(BLUE("%d"), abcdef);
    contact(abc, def) = 21;
    log(YELLOW("%d"), abcdef);
    contact(contact(ab, c), contact(de, f)) = 23;
    log(YELLOW("%d"), abcdef);
    int temp1 = -123;
    double temp2 = -456.78;
    log("|temp1| : %d", ABS(temp1));
    log("|temp2| : %lf", ABS(temp2));
    return 0;
}
