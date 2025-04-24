#include <stdlib.h>
#include <stdio.h>

#ifndef LEETLIST_H

#define LEETLIST_H


//This is the official LEETCODE structure
struct ListNode {
    int val;
    struct ListNode *next;
};


//This is my List Info structure

struct LIST{
    struct ListNode* head;
    struct ListNode* lastAhead;
    int elemSize;
};

//List Configuration (tester functions)
//Usually the LeetCode Provide the List...so these are not called

struct LIST* init_list(void);                                   //Initialize a LIST node
struct ListNode* init_node(void);                                //initialize and return a List node
void add_node(struct LIST* name, int value);                    //Add a node to the end of list

void build_list(struct LIST* name, int* src, int size);         //Build a list from array
void pop_node(struct LIST* name);
void clear(struct LIST* name);

struct LIST* map_list(struct ListNode* firsNode);                   //This function map a list architecture, and returns it as a list structure


void display_list(struct ListNode* head);                      //Display the node values to std output

#endif