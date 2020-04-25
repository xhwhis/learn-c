#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <inttypes.h>

int reverse_num(int num, int *temp) {
    int digit = 0;
    *temp = 0;
    do {
        *temp = *temp * 10 + num % 10;
        num /= 10;
        digit += 1;
    } while (num);
    return digit;
}

int output_num_with_digit(int num, int digit) {
    int ret = 0;
    while (digit--) {
        putchar(num % 10 + '0');
        num /= 10;
        ret += 1;
    }
    return ret;
}

int my_printf(const char *frm, ...) {
    va_list arg;
    va_start(arg, frm);
    int cnt = 0;
    #define PUTC(a) putchar(a), ++cnt
    for (int i = 0; frm[i]; i++) {
        switch (frm[i]) {
            case '%': {
                switch (frm[++i]) {
                    case '%': PUTC(frm[i]); break;
                    case 'd': {
                        int xx = va_arg(arg, int), temp = 0, digit = 0;
                        uint32_t x;
                        if (xx < 0) PUTC('-'), x = -xx;
                        else x = xx;
                        int val1 = x / 100000, val2 = x % 100000;
                        int temp1 = 0, temp2 = 0;
                        int digit1 = reverse_num(val1, &temp1);
                        int digit2 = reverse_num(val2, &temp2);
                        if (val1) digit2 = 5;
                        else digit1 = 0;
                        cnt += output_num_with_digit(temp1, digit1);
                        cnt += output_num_with_digit(temp2, digit2);
                    } break;
                    case 's': {
                        const char *str = va_arg(arg, const char *);
                        for (int i = 0; str[i]; i++) {
                            PUTC(str[i]);
                        }
                    } break;
                }
            } break;
            default: PUTC(frm[i]); break;
        }
    }
    va_end(arg);
    return cnt;
    #undef PUTC
}

int main() {
    int a = 123;
    printf("hello world\n");
    my_printf("hello world\n");
    printf("int a = %d\n", a);
    my_printf("int a = %d\n", a);
    printf("int(1000) = %d\n", 1000);
    my_printf("int(1000) = %d\n", 1000);
    printf("int(0) = %d\n", 0);
    my_printf("int(0) = %d\n", 0);
    printf("int(-123) = %d\n", -123);
    my_printf("int(-123) = %d\n", -123);
    printf("INT32_MAX = %d\n", INT32_MAX);
    my_printf("INT32_MAX = %d\n", INT32_MAX);
    printf("INT32_MIN = %d\n", INT32_MIN);
    my_printf("INT32_MIN = %d\n", INT32_MIN);

    char str[100] = "I love monkey";
    printf("%s\n", str);
    my_printf("%s\n", str);
    int n;
    while (~scanf("%d", &n)) {
        printf(" has %d digits\n", printf("%d", n));
        my_printf(" has %d digits\n", my_printf("%d", n));
    }
    return 0;
}
