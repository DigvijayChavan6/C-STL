#include<stdlib.h>
#include<string.h>
#include "stack.h"

stack* createStack(char *dataType){
    stack *st;
    st->top=NULL;
    st->size=0;
    st->type=dataType;
    return st;
}
void push(stack *st,void* val){
    stackNode* node=(stackNode*)malloc(sizeof(stackNode));
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
void* pop(stack *st){
    if(!st->top)return NULL;
    void* val=st->top->data;
    stackNode *t=st->top;
    st->top=st->top->prev;
    free(t);
    st->size--;
    return val;
}