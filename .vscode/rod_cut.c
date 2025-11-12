#include<stdio.h>

int rod(int l,int arr[]){
    if(l==0){
        return 0;
    }
    else{
        int max=-1;
        for(int i=0;i<l;i++){
            int tmp=arr[i]+rod(l-i-1,arr);
            if(tmp>max){
                max=tmp;
            }
        }
        return max;
    }
}

int main(){
    int n;
    // int arr[n];
    int p[]={1,5,8,9};
    scanf("%d",&n);
    printf("%d",rod(n,p));
}