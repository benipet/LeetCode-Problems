#include "leet.h"

struct ListNode* swapPairs(struct ListNode* head) {
    if(head==0)
    return 0;

    if(head->next==0)
    return head;

    head=swap_nodes(head,0);
    
    struct ListNode* curr=head->next;
    struct ListNode* ctx=curr->next;

    while(ctx!=0){
        swap_nodes(ctx,curr);
        curr=ctx;
        ctx=ctx->next;
    }
    
    
    return head;
}


struct ListNode* swap_nodes(struct ListNode* NodeA, struct ListNode* parent){
    if(NodeA->next==0)
    return 0;
   
    struct ListNode* head;
    struct ListNode* NodeB=NodeA->next;
    struct ListNode* swap;


    if(parent==NULL){
        swap=NodeB->next;
        NodeB->next=NodeA;
        NodeA->next=swap;
        return NodeB;

    }
    else{
        swap=NodeB->next;
        NodeB->next=NodeA;
        NodeA->next=swap;
        parent->next=NodeB;
        return 0;
    }

}