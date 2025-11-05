#include<stdio.h>

int main(){
    int a,b,c;
    scanf("%d %d %d",&a,&b,&c);
    int i=0,j=0;
    while(i>-100&&j<100){
        if(a*i+b*j==c)
        {
           printf("\n%d %d",i--,j++);
        }
        else if(a*i+b*j<c)
        j++;
        else
        i--; 
    }
    printf("\n%d %d",i,j);
    
}