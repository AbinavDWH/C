#include<stdio.h>
#include<stdlib.h>

int compare(void const * a, void const * b){
    return (*(int*) b- *(int*)a);

}
int main(){
    int n;
    scanf("%d",&n);
    int child[n];
    for(int i=0;i<n;i++){
        scanf("%d",&child[i]);
    }
    qsort(child,n,sizeof(int),compare);
    int t;
    scanf("%d",&t);
    int cookies[t];
    for(int i=0;i<t;i++){
        scanf("%d",&cookies[i]);    
    }
    qsort(cookies,t,sizeof(int),compare);

    int c=0;
    for(int i=0;i<n;i++){
        for (size_t j = 0; j < t; j++)
        {
            /* code */
            if(child[i]==cookies[j]){
                c++;
                break;
                
            }
        }
        
    }
    printf("%d",c);
    
}