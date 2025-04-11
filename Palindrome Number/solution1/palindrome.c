#include <stdbool.h>
#include <stdio.h>
#include <string.h>

#define BUFF_SIZE 100
char* create_palind(char* str, int length);
int is_palindrome(int x);

int main (void){
    
    
    printf("%d", is_palindrome(121));    
    
    
    return 0;

}


int is_palindrome(int x){
    if(x<0)
    return 0;
    
    char str_x[BUFF_SIZE];
    sprintf(str_x,"%d",x);
    int l = strlen(str_x)-1;
    int i = 0;
    int j = l;

    for(i;i<=l;i++){
        if(str_x[i]!=str_x[j])
        return false;       
        j--;
        
        
    }
    return true;

}