#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include "queue.h"

queue* queue_create(char* dataType){
    queue *q=NULL;
    while(q==NULL)q=(queue*)malloc(sizeof(queue));
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

void queue_insert(queue* q, void* val){
    struct queue_node* node=NULL;
    while(node==NULL)node=(struct queue_node*)malloc(sizeof(struct queue_node));
    size_t size;
    if(0==strcmp(q->type,"CHAR"))size=sizeof(char);
    else if(0==strcmp(q->type,"STRING"))size=strlen((char*)val)+1;
    else if(0==strcmp(q->type,"FLOAT"))size=sizeof(float);
    else if(0==strcmp(q->type,"DOUBLE"))size=sizeof(double);
    else if(0==strcmp(q->type,"BOOL"))size=sizeof(char);
    else size=sizeof(int);
    node->data=NULL;
    while(node->data==NULL)node->data=malloc(size);
    memcpy(node->data,val,size);
    node->next=NULL;
    if(q->rear==NULL){
        q->rear=node;
        q->front=node;
    }
    else{
        q->rear->next=node;
        q->rear=node;
    }
    q->size++;
}

void* queue_remove(queue* q){
    if(q->front==NULL)return NULL;
    void *val=q->front->data;
    struct queue_node *t=q->front;
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
