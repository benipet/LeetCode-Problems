#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define BUFF_SIZE 100
char* create_palind(char* str, int length);
int is_palindrome(int x);

int main (void){
    
    
    printf("%d", is_palindrome(-121));
    
  
    

    
    
    
    return 0;

}


int is_palindrome(int x){
    int answer;
    if(x<0)
    return 0;

    char* num_str = (char*)malloc(BUFF_SIZE*sizeof(char));
    sprintf(num_str, "%d", x);
    char* palind = create_palind(num_str, strlen(num_str));

    if(strcmp(num_str,palind)==0)
        answer=1;
    else
        answer=0;


    free(num_str);
    free(palind);

    return answer;

}


char* create_palind(char* str, int length){
    char* palind = (char*)malloc(BUFF_SIZE*sizeof(char));
    int i = 0;
    int l = length-1;
    
    
    for(l;l>=0;l--){
        palind[l] = str[i];
        i++;
    }
    palind[length]=0;
    return palind;
}
