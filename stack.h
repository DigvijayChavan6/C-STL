#ifndef stack_h
#define stack_h
#include<stdlib.h>
#include<string.h>

struct stackNode{
    void* data;
    struct stackNode *prev;
};
struct stack{
    struct stackNode *top;
    int size;
    char *type;
};
struct stack createStack(char *dataType){
    struct stack st;
    st.top=NULL;
    st.size=0;
    st.type=dataType;
    return st;
}
void push(struct stack *st,void* val){
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
void* pop(struct stack *st){
    if(!st->top)return NULL;
    void* val=st->top->data;
    struct stackNode *t=st->top;
    st->top=st->top->prev;
    free(t);
    st->size--;
    return val;
}
#endif