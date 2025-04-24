#include "leet.h"
#include <stdio.h>


struct ListNode* swapPairs(struct ListNode* head);


struct ListNode* swap_nodes(struct ListNode* NodeA, struct ListNode* parent);

int main(void){
    int n[10] ={1,2,3,4};

    struct LIST* test;
    build_list(test, n, 4);

    test->head=swapPairs(test->head);
    test=map_list(test->head);
    display_list(test->head);
    
    
    clear(test);

    return 0;
}