#include <stdio.h>

int func_2(int (*a)[200][300]) {
    return 0;
}

int main() {
    int arr[100][200][300];
    func_2(arr);
    printf("&arr[0] = %p  arr = %p\n", &arr[0], arr);
    printf("arr + 1 = %p  arr + 2 = %p\n", arr + 1, arr + 2);
    char *p = (char *)arr;
    printf("p + 1 = %p  p + 2 = %p\n", p + 1, p + 2);
    printf("sizeof(arr) = %lu\n", sizeof(arr));
    return 0;
}
