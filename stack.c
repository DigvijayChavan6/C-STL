#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<stdio.h>
#include "stack.h"

stack* createStack(char *dataType){
    stack *st=(stack*)malloc(sizeof(stack));
    st->top=NULL;
    st->size=0;
    st->type=(char*)malloc(strlen(dataType)+1);
    strcpy(st->type,dataType);
    for(int i=0;dataType[i]!='\0';i++){
        st->type[i]=toupper(st->type[i]);
    }
    return st;
}
void pushC(stack *st,void* val){
    struct stackNode* node=(struct stackNode*)malloc(sizeof(struct stackNode));
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
void* popC(stack *st){
    if(!st->top)return NULL;
    void* val=st->top->data;
    struct stackNode *t=st->top;
    st->top=st->top->prev;
    free(t);
    st->size--;
    return val;
}