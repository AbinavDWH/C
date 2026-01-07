#include<stdio.h>
#include<ctype.h>
#include<string.h>
#include <stdbool.h>
#include <stdlib.h>


bool ispali(char s[]){

    if(strlen(s)<1){
        return true;
    }

    char *str=(char *)malloc((sizeof(char)*(strlen(s)))+1);
    int j=0;
    for(int i=0;i<strlen(s);i++){
        char t=tolower(s[i]);
        if(isalnum(t)){
            str[j++]=t;
        }
        
    }
    str[j]='\0';
    for(int i=0;i<strlen(str)/2;i++){
        if(str[i]!=str[j-i-1]){
            return false;
        }
    }
    return true;
}


int main(){
    char str[100];
    scanf("%s", str);
    printf("%d",ispali(str) );
}