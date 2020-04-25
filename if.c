#include<stdio.h>
int main() {
    int n;
    scanf("%d",&n);
    if(n==0) printf("FOOLISH\n");
    else if(n<60) printf("FAIL\n");
    else if(n<75) printf("MEDIUM\n");
    else printf("GOOD\n");
    return 0;
}
