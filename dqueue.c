#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include "dqueue.h"

dqueue* dqueue_create(char* dataType){
    dqueue *q=NULL;
    while(q==NULL)q=(dqueue*)malloc(sizeof(dqueue));
    q->front=NULL;
    q->rear=NULL;
    q->size=0;
    q->type=(char*)malloc(strlen(dataType)+1);
    strcpy(q->type,dataType);
    for(int i=0;q->type[i]!='\0';i++){
        q->type[i]=toupper(q->type[i]);
    }
    return q;
}

void dqueue_push_front(dqueue* q, void* val){
    struct dqueue_node* node=NULL;
    while(node==NULL)node=(struct dqueue_node*)malloc(sizeof(struct dqueue_node));
    size_t size;
    if(0==strcmp(q->type,"CHAR"))size=sizeof(char);
    else if(0==strcmp(q->type,"STRING"))size=strlen((char*)val)+1;
    else if(0==strcmp(q->type,"FLOAT"))size=sizeof(float);
    else if(0==strcmp(q->type,"DOUBLE"))size=sizeof(double);
    else if(0==strcmp(q->type,"BOOL"))size=sizeof(char);
    else size=sizeof(int);
    node->data=NULL;
    node->prev=NULL;
    node->next=NULL;
    while(node->data==NULL)node->data=malloc(size);
    memcpy(node->data,val,size);
    node->next=NULL;
    if(q->front==NULL){
        q->front=node;
        q->rear=node;
    }
    else{
        node->next=q->front;
        q->front->prev=node;
        q->front=node;
    }
    q->size++;
}

void dqueue_push_back(dqueue* q, void* val){
    struct dqueue_node* node=NULL;
    while(node==NULL)node=(struct dqueue_node*)malloc(sizeof(struct dqueue_node));
    size_t size;
    if(0==strcmp(q->type,"CHAR"))size=sizeof(char);
    else if(0==strcmp(q->type,"STRING"))size=strlen((char*)val)+1;
    else if(0==strcmp(q->type,"FLOAT"))size=sizeof(float);
    else if(0==strcmp(q->type,"DOUBLE"))size=sizeof(double);
    else if(0==strcmp(q->type,"BOOL"))size=sizeof(char);
    else size=sizeof(int);
    node->data=NULL;
    node->prev=NULL;
    node->next=NULL;
    while(node->data==NULL)node->data=malloc(size);
    memcpy(node->data,val,size);
    node->next=NULL;
    if(q->rear==NULL){
        q->rear=node;
        q->front=node;
    }
    else{
        node->prev=q->rear;
        q->rear->next=node;
        q->rear=node;
    }
    q->size++;
}

void* dqueue_pop_front(dqueue* q){
    if(q->front==NULL)return NULL;
    void *val=q->front->data;
    struct dqueue_node *t=q->front;
    if(q->front==q->rear){
        q->front=NULL;
        q->rear=NULL;
    }
    else{
        q->front=q->front->next;
    }
    free(t);
    q->size--;
    return val;
}

void* dqueue_pop_back(dqueue* q){
    if(q->rear==NULL)return NULL;
    void *val=q->rear->data;
    struct dqueue_node *t=q->rear;
    if(q->front==q->rear){
        q->rear=NULL;
        q->front=NULL;
    }
    else{
        q->rear=q->rear->prev;
    }
    free(t);
    q->size--;
    return val;
}
