#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include "stack.h"

stack* stack_create(char *data_type){
    stack *st=(stack*)malloc(sizeof(stack));
    st->top=NULL;
    st->size=0;
    st->type=(char*)malloc(strlen(data_type)+1);
    strcpy(st->type,data_type);
    for(int i=0;data_type[i]!='\0';i++){
        st->type[i]=toupper(st->type[i]);
    }
    return st;
}

void stack_push(stack *st,void* val){
    struct stack_node* node=(struct stack_node*)malloc(sizeof(struct stack_node));
    size_t size;
    if(0==strcmp(st->type,"CHAR"))size=sizeof(char);
    else if(0==strcmp(st->type,"STRING"))size=strlen((char*)val)+1;
    else if(0==strcmp(st->type,"FLOAT"))size=sizeof(float);
    else if(0==strcmp(st->type,"DOUBLE"))size=sizeof(double);
    else if(0==strcmp(st->type,"BOOL"))size=sizeof(char);
    else size=sizeof(int);
    node->data=malloc(size);
    memcpy(node->data,val,size);
    node->prev=st->top;
    st->top=node;
    st->size++;
}

void* stack_pop(stack *st){
    if(st->top==NULL)return NULL;
    void* val=st->top->data;
    struct stack_node *t=st->top;
    st->top=st->top->prev;
    free(t);
    st->size--;
    return val;
}

void* stack_peek(stack *st){
    if(st->top==NULL)return NULL;
    void* val=st->top->data;
    return val;    
}

size_t stack_size(stack* st){
    size_t size=0;
    struct stack_node *node=st->top;
    while(node!=NULL){
        size++;
        node=node->prev;
    }
    st->size=size;
    return size;
}

void stack_swap(stack* st1,stack* st2){
    if(strcmp(st1->type,st2->type)==0){
        struct stack_node *temp=st1->top;
        st1->top=st2->top;
        st2->top=temp;

        size_t size=st1->size;
        st1->size=st2->size;
        st2->size=size;
    }
}

short stack_ispresent(stack* st,void* val){
    struct stack_node *node=st->top;
    while(node!=NULL){
        if(0==strcmp(st->type,"CHAR")){
            if(*(char*)node->data == *(char*)val)return 1;
        }
        else if(0==strcmp(st->type,"STRING")){
            if(strcmp((char*)node->data ,(char*)val)==0)return 1;
        }
        else if(0==strcmp(st->type,"FLOAT")){
            if(*(float*)node->data == *(float*)val)return 1;
        }
        else if(0==strcmp(st->type,"DOUBLE")){
            if(*(double*)node->data == *(double*)val)return 1;
        }
        else if(0==strcmp(st->type,"BOOL")){
            if(*(short*)node->data == *(short*)val)return 1;
        }
        else{
            if(*(int*)node->data == *(int*)val)return 1;
        }
        node=node->prev;
    }
    return 0;
}

short stack_isempty(stack* st){
    if(st->top==NULL)return 1;
    return 0;
}

void stack_clean(stack* st){
    while(st->top!=NULL){
        struct stack_node *temp=st->top;
        st->top=temp->prev;
        free(temp->data);
        free(temp);
    }
    free(st->type);
    free(st);
}