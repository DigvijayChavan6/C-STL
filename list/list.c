#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include "list.h"

list* list_create(char* data_type){
    list *li=(list*)malloc(sizeof(list));
    li->head=NULL;
    li->size=0;
    li->type=(char*)malloc(sizeof(strlen(data_type)+1));
    strcpy(li->type,data_type);
    for(int i=0;data_type[i]!='\0';i++){
        li->type[i]=toupper(li->type[i]);
    }
    return li;
}

struct list_node* create_list_node(list* li,void* val){
    struct list_node *node=NULL;
    while(node==NULL)node=(struct list_node*)malloc(sizeof(struct list_node));
    size_t size;
    if(0==strcmp(li->type,"CHAR"))size=sizeof(char);
    else if(0==strcmp(li->type,"STRING"))size=strlen((char*)val)+1;
    else if(0==strcmp(li->type,"FLOAT"))size=sizeof(float);
    else if(0==strcmp(li->type,"DOUBLE"))size=sizeof(double);
    else if(0==strcmp(li->type,"SHORT"))size=sizeof(short);
    else if(0==strcmp(li->type,"LONG"))size=sizeof(long);
    else if(0==strcmp(li->type,"BOOL"))size=sizeof(short);
    else size=sizeof(int);
    node->data=NULL;
    while(node->data==NULL)node->data=malloc(size);
    memcpy(node->data,val,size);
    node->next=NULL;
    return node;
}

void list_push_front(list* li, void* val){
    struct list_node *node=create_list_node(li,val);
    if(li->head==NULL){
        li->head=node;
    }
    else{
        node->next=li->head;
        li->head=node;
    }
    li->size++;
}

void* list_pop_front(list* li){
    struct list_node *temp=li->head;
    if(temp==NULL)return NULL;
    void* val=temp->data;
    li->head=temp->next;
    free(temp);
    li->size--;
    return val;
}

void list_push_back(list* li, void* val){
    struct list_node *node=create_list_node(li,val);
    if(li->head==NULL){
        li->head=node;
    }
    else{
        struct list_node *temp=li->head;
        while(temp->next!=NULL){
            temp=temp->next;
        }
        temp->next=node;
    }
}

void* list_pop_back(list* li){
    struct list_node *temp=li->head;
    void* val;
    if(li->head==NULL)return NULL;
    if(temp->next==NULL){
        li->head=NULL;
        val=temp->data;
        free(temp);
    }
    else{
        while(temp->next->next!=NULL){
            temp=temp->next;
        }
        val=temp->next->data;
        free(temp->next);
        temp->next=NULL;
    }
    li->size--;
    return val;
}

void list_insert(list* li,void* val,size_t position){
    struct list_node* node = create_list_node(li, val);
    if(position == 1 || li->head==NULL){
        node->next = li->head;
        li->head = node;
    }
    else{
        struct list_node* temp = li->head;
        for(size_t i = 2; i < position; i++){
            temp = temp->next;
        }
        node->next = temp->next;
        temp->next = node;
    }
    li->size++;  
}

void list_remove(list* li,size_t position){
    if(li->head == NULL || position > li->size)return; 
    struct list_node* temp = li->head,*t;
    if(position == 1 ){
        li->head=temp->next;
        free(temp);
    }
    else{
        for(size_t i=2;i<position;i++){
            temp=temp->next;
        }
        t=temp->next;
        temp->next=t->next;
        free(t);
    }
    li->size--;
}

size_t list_size(list* li){
    size_t size=0;
    struct list_node *temp=li->head;
    while(temp!=NULL){
        temp=temp->next;
        size++;
    }
    li->size=size;
    return size;
}

void list_swap(list* li1, list* li2){
    if(strcmp(li1->type,li2->type)==0){
        size_t size=sizeof(list);
        list *t=(list*)malloc(size);
        memcpy(t,li1,size);
        memcpy(li1,li2,size);
        memcpy(li2,t,size);
        free(t);
    }
}

short list_ispresent(list* li,void* val){
    struct list_node *node=li->head;
    while(node!=NULL){
        if(0==strcmp(li->type,"CHAR")){
            if(*(char*)node->data == *(char*)val)return 1;
        }
        else if(0==strcmp(li->type,"STRING")){
            if(strcmp((char*)node->data ,(char*)val)==0)return 1;
        }
        else if(0==strcmp(li->type,"FLOAT")){
            if(*(float*)node->data == *(float*)val)return 1;
        }
        else if(0==strcmp(li->type,"DOUBLE")){
            if(*(double*)node->data == *(double*)val)return 1;
        }
        else if(0==strcmp(li->type,"SHORT")){
            if(*(short*)node->data == *(short*)val)return 1;
        }
        else if(0==strcmp(li->type,"LONG")){
            if(*(long*)node->data == *(long*)val)return 1;
        }
        else if(0==strcmp(li->type,"BOOL")){
            if(*(short*)node->data == *(short*)val)return 1;
        }
        else{
            if(*(int*)node->data == *(int*)val)return 1;
        }
        node=node->next;
    }
    return 0;
}

short list_isempty(list* li){
    if(li->head==NULL)return 1;
    return 0;
}

void list_clean(list* li){
    while(li->head!=NULL){
        struct list_node *temp=li->head;
        li->head=li->head->next;
        free(temp);
    }
    free(li);
}

void list_reverse(list* li) {
    struct list_node* prev = NULL;
    struct list_node* temp = li->head;
    while (temp != NULL) {
        struct list_node* next = temp->next;
        temp->next = prev;               
        prev = temp; 
        temp = next;
    }
    li->head = prev;
}