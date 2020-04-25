/*************************************************************************
	> File Name: test01.c
	> Author: 
	> Mail: 
	> Created Time: 2019年07月27日 星期六 19时10分13秒
 ************************************************************************/

#include<stdio.h>

int func(int n) {
    if(n==0) return 1;
    else return n*func(n-1);
}

int main() {
    int n;
    while(scanf("%d", &n)!=EOF) {
        printf("f(%d)=%d\n",n,func(n));
    }
    return 0;
}
