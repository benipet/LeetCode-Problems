#include "leet.h"

struct LIST* init_list(void){
    struct LIST* current = (struct LIST*)malloc(sizeof(struct LIST));
    current->elemSize=0;
    current->head=0;


    current->lastAhead=0;
}



struct LIST* map_list(struct ListNode* firstNode){
    struct LIST* container = init_list();
    container->head=firstNode;
    while(firstNode->next!=0){
        container->elemSize++;
        firstNode=firstNode->next;
    }
    container->elemSize++;
    container->lastAhead=firstNode;
    return container;

}


void add_node(struct LIST* name, int value){
    struct ListNode* current = (struct ListNode*)malloc(sizeof(struct ListNode));
    current->val=value;
    current->next=0;

    if(name->elemSize==0){
        name->head=current;
        name->lastAhead=0;
        name->elemSize++;
        return;
    }
    else if(name->elemSize == 1){
        name->head->next=current;
        name->lastAhead=name->head;
        name->elemSize++;
    }
    else{
        struct ListNode* last = name->lastAhead->next;
        name->lastAhead=last;
        last->next=current;
        name->elemSize++;
    }

}

void pop_node(struct LIST* name){
    if(name->elemSize==0)
    return;

    struct ListNode* prev;
    struct ListNode* context;

    if(name->elemSize==1){
    name->head=0;
    free(name->head);
    }
      

    else if(name->elemSize<=2){
        context=name->head;
        
        //printf("hello");
        free(context->next);
        context->next=0;
        name->lastAhead=context;        
        
    }

    else{       
        
        int i=1;
        prev=name->head;
        

        for(i;i<name->elemSize-2;i++){
            prev=prev->next;
        }
        context=prev->next;
        name->lastAhead=prev;
        free(context->next);
        context->next=0;
        
       
    }
    
    name->elemSize--;
   
    return;  
    
    
}

void clear(struct LIST* name){
    while(name->elemSize!=0){
        pop_node(name);
    }

}

void build_list(struct LIST* name, int* src, int size){
    int i=0;

    for(i;i<size;i++){
        add_node(name, src[i]);
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

