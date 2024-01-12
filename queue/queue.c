#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include "queue.h"

queue* queue_create(char* data_type){
    queue *q=NULL;
    while(q==NULL)q=(queue*)malloc(sizeof(queue));
    q->front=NULL;
    q->rear=NULL;
    q->size=0;
    q->type=(char*)malloc(strlen(data_type)+1);
    strcpy(q->type,data_type);
    for(int i=0;q->type[i]!='\0';i++){
        q->type[i]=toupper(q->type[i]);
    }
    return q;
}

void queue_push(queue* q, void* val){
    struct queue_node* node=NULL;
    node=(struct queue_node*)malloc(sizeof(struct queue_node));
    size_t size;
    if(0==strcmp(q->type,"CHAR"))size=sizeof(char);
    else if(0==strcmp(q->type,"STRING"))size=strlen((char*)val)+1;
    else if(0==strcmp(q->type,"FLOAT"))size=sizeof(float);
    else if(0==strcmp(q->type,"DOUBLE"))size=sizeof(double);
    else if(0==strcmp(q->type,"BOOL"))size=sizeof(short);
    else size=sizeof(int);
    node->data=NULL;
    node->data=malloc(size);
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

void* queue_pop(queue* q){
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

size_t queue_size(queue* q){
    size_t size=0;
    struct queue_node *temp=q->front;
    while(temp!=NULL){
        size++;
        temp=temp->next;
    }
    q->size=size;
    return size;
}

void queue_swap(queue* q1,queue* q2){
    if (0==strcmp(q1->type,q2->type)) {
        struct queue_node *node=q1->front;
        q1->front=q2->front;
        q2->front=node;

        node=q1->rear;
        q1->rear=q2->rear;
        q2->rear=node;
        
        size_t size=q1->size;
        q1->size=q2->size;
        q2->size=size;

    }
}

short queue_ispresent(queue* q,void* val){
    struct queue_node *node=q->front;
    while(node!=NULL){
        if(0==strcmp(q->type,"CHAR")){
            if(*(char*)node->data == *(char*)val)return 1;
        }
        else if(0==strcmp(q->type,"STRING")){
            if(strcmp((char*)node->data ,(char*)val)==0)return 1;
        }
        else if(0==strcmp(q->type,"FLOAT")){
            if(*(float*)node->data == *(float*)val)return 1;
        }
        else if(0==strcmp(q->type,"DOUBLE")){
            if(*(double*)node->data == *(double*)val)return 1;
        }
        else if(0==strcmp(q->type,"BOOL")){
            if(*(short*)node->data == *(short*)val)return 1;
        }
        else{
            if(*(int*)node->data == *(int*)val)return 1;
        }
        node=node->next;
    }
    return 0;
}

short queue_isempty(queue* q){
    if(q->front==NULL)return 1;
    return 0;
}

void queue_clean(queue* q){
    while(q->front!=NULL){
        struct queue_node *temp=q->front;
        q->front=temp->next;
        free(temp->data);
        free(temp);
    }
    free(q->type);
    free(q);
}

void queue_reverse(queue* q) {
    struct queue_node* prev = NULL;
    struct queue_node* current = q->front;
    while (current != NULL) {
        struct queue_node* next = current->next;  
        current->next = prev;                      
        prev = current;
        current = next;
    }
    struct queue_node* temp = q->front;
    q->front = q->rear;
    q->rear = temp;
}

void* queue_peek(queue* q) {
    if (q->front == NULL) {
        return NULL;
    }
    void* val = q->front->data;
    return val;
}