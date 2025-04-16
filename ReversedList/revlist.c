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



int main(void){

    struct ListNode* test = 0;
   // add_node(test, 3);

    display_list(test);
    
    struct ListNode* rTest = reverseList(test);
    display_list(rTest);


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
    if(head==0)
    return 0;
    struct ListInfo* relevant = mapList(head);
    struct ListNode* reversed;
    
    if(relevant->elemSize==1){
        reversed = init_list(head->val);
        return reversed;
    }
    

    else{
        reversed = init_list(relevant->lastAhead->next->val);
    }  

    free(relevant->lastAhead->next);
    relevant->lastAhead->next=0;
    free(relevant);
    relevant=mapList(head);

    while(relevant->elemSize!=1){
    add_node(reversed, relevant->lastAhead->next->val);
    free(relevant->lastAhead->next);
    relevant->lastAhead->next=0;
    free(relevant);
    relevant = mapList(head);
    };
    add_node(reversed, head->val);
    free(head);

    return reversed;
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