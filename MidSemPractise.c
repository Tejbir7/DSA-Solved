#include<stdio.h>
struct node{
    int data;
    struct node* link;
}*ptr, *start, * ptr1, *new;

struct node* deleteAnywhere(struct node* start, int pos){
    if(!start) return NULL;
    
    struct node*temp = start;
    //delete first
    if(pos==1){
        start = start->link;
        free(temp);
        return start;
    }
    struct node * prev = NULL;
    int count = 0;
    while(temp){
        ++count;
        if(count == pos){
            prev->link = temp->link;
            free(temp);
            return start;
        }
        prev = temp;
        temp = temp->link;
    }
   return start;
}
