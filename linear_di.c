#include<stdio.h>

int main(){
    int a,b,m;
    scanf("%d %d %d",&a,&b,&m);
    int i=1;
    while(i<100){
        float to;
        to=(b+m*i++)%a;
        if(to==0){
            printf("%d i = %d",(b+m*(i-1))/a,i-1);
            break;
        }
    }

}