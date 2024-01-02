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