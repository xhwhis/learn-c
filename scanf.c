#include<stdio.h>
int main(){
    char str[100];
    while(scanf("%[^\n]s",str)!=EOF) {
        getchar();
        printf(" has %d chars\n",printf("%s",str));
    }
    return 0;
}
