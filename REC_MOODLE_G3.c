#include<stdio.h>

long long f(long long  n){
    if(n<0) return 0;
    if(n==1 || n==0) return 1;
    return f(n-1)+f(n-3);
}

int main() {
    int n;
    scanf("%d",&n);
    printf("%lld",f(n));
}