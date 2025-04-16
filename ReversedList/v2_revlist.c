#include <stdlib.h>
#include <stdio.h>


struct ListNode {
    int val;
    struct ListNode* next;
};

struct ListInfo{
    int elemSize;
    struct ListNode* lastAhead;
};

//Create a List

struct ListNode* init_list(int value);
void add_node(struct ListNode* head, int value);

//This is the problem function;
struct ListNode* reverseList(struct ListNode* head);

struct ListInfo* mapList(struct ListNode* head);


void display_list(struct ListNode* head);

void display_nodes(struct ListNode* sample);

int main(void){

   struct ListNode* test = init_list(1);
   add_node(test, 2);


    display_list(test);
    
    struct ListNode* rTest = reverseList(test);
    
    
    free(test);
    return 0;

}

struct ListNode* init_list(int value){
    struct ListNode* head = (struct ListNode*)malloc(sizeof(struct ListNode));
    head->val=value;
    head->next=0;
    return head;
}




/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode* reverseList(struct ListNode* head) {
    if (head==0)
    return 0;

    if(head->next==0)
    return head;
    
    struct ListNode* current;           //current node
    struct ListNode* prev;              //previous node
    struct ListNode* context;           //upcoming node
    
    //Initialized value
    prev = head;                            //assign head to prev
    current = head->next;                   //assign the head-next to current
    context = current->next;                //assign current->next to context


    while(context!=0){
        
        current->next=prev;
        prev=current;
        current=context;
        context=context->next;
        
    }
    current->next=prev;
    head->next=0;


    return current;
}


struct ListInfo* mapList(struct ListNode* head){

    struct ListInfo* lastAhead= (struct ListInfo*)malloc(sizeof(struct ListInfo));

    if(head->next==0){
        lastAhead->elemSize=1;
        lastAhead->lastAhead=head;
        

    }
    else{
        
        struct ListNode* current = head;
        lastAhead->elemSize=1;
        lastAhead->lastAhead=current;
        
        while(current->next!=0){
            
            lastAhead->lastAhead=current;
            lastAhead->elemSize++;
            current=current->next;
        }

    }
    
    
   
    
    

    return lastAhead;

}


void add_node(struct ListNode* head, int value){
    struct ListNode* newNode = (struct ListNode*)malloc(sizeof(struct ListNode));
    newNode->val=value;
    newNode->next=0;

        struct ListNode* current = head;
    while(current!=0){
        
        if(current->next==0){
            current->next=newNode;
            break;
        }
        current=current->next;
    }
    
    
    


}


void display_list(struct ListNode* head){
    struct ListNode* currNode=head;
    while(currNode!=0){
        printf("%d ", currNode->val);
        currNode=currNode->next;
    }
    printf("\n");
}

void display_nodes(struct ListNode* sample){
    if(sample->next==0){
        printf("current value: %d, next value->void\n", sample->val);
        return;

    }
    else{
        printf("current value: %d Next value: %d\n", sample->val, sample->next->val);
        
    }
    

}