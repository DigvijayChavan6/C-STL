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
    else if(0==strcmp(li->type,"BOOL"))size=sizeof(short);
    else size=sizeof(int);
    node->data=NULL;
    while(node->data==NULL)node->data=malloc(size);
    memcpy(node->data,val,size);
    node->next=NULL;
    node->prev=NULL;
    return node;
}

void list_push_front(list* li, void* val){
    struct list_node *node=create_list_node(li,val);
    if(li->head==NULL){
        li->head=node;
    }
    else{
        node->next=li->head;
        li->head->prev=node;
        li->head=node;
    }
    li->size++;
}

void* list_pop_front(list* li){
    struct list_node *temp=li->head;
    if(temp==NULL)return NULL;
    void* val=temp->data;
    li->head=temp->next;
    li->head->prev=NULL;
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
        node->prev=temp;
    }
}

void* list_pop_back(list* li){
    struct list_node *temp=li->head;
    void* val;
        if(li->head==NULL){
            val=NULL;
        }
        else if(temp->next!=NULL && temp->prev!=NULL){
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

short list_ispresent(list* li,void* find_val){
    struct list_node *temp=li->head;
    while(temp!=NULL){
        if(0==strcmp(temp->data,find_val)){
            return 1;
        }
        temp=temp->next;
    }
    return 0;
}

void list_insert(list* li,size_t pos){
    

}

void* list_remove(list* li,size_t pos){

   if(li->head == NULL || pos > li->size){
        return NULL;
    }
    struct list_node* temp = li->head;
    for(size_t i = 1; i < pos; i++){
        temp = temp->next;
    }
    if(temp->prev != NULL){
        temp->prev->next = temp->next;
    } 
    else {
        li->head = temp->next;
    }
    if(temp->next != NULL){
        temp->next->prev = temp->prev;
    }
    void* val = temp->data;
    free(temp);
    li->size--;
    return val;
}

list* list_reverse(list* li) {
    struct list_node* prev = NULL;
    struct list_node* temp = li->head;
    while (temp != NULL) {
        struct list_node* next = temp->next;
        temp->next = prev;               
        prev = temp; 
        temp = next;
    }
    li->head = prev;
    return li;
}

short list_isempty(list* li){
    if(li->head==NULL)return 1;
    return 0;
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

void list_clean(list* li){
    while(li->head!=NULL){
        struct list_node *temp=li->head;
        li->head=li->head->next;
        free(temp);
    }
    free(li);
}
