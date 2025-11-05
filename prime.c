#include<stdio.h>
#include<math.h>


int main(){
    int n;
    scanf("%d",&n);
    for(int i=2;i<=(int)(float)sqrt(n);i++){
        if(n%i==0){
            printf("NOT a prime %d",i);
            return 0;
        }

    }

    printf("Prime");

}