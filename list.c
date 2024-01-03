#include<stdlib.h>
#include<string.h>
#include "list.h"

list* list_create(char* dataType){
    list *li=(list*)malloc(sizeof(list));
    li->head=NULL;
    li->size=0;
    li->type=(char*)malloc(sizeof(strlen(dataType)+1));
    strcpy(li->type,dataType);
    for(int i=0;dataType[i]!='\0';i++){
        li->type[i]=toupper(li->type[i]);
    }
    return li;
}

void list_add_begin(list* li , void* val){
    struct list_node *node=(struct list_node*)malloc(sizeof(struct list_node));
    node->data=val;
    node->prev=node->next=NULL;
    if(li->head==NULL){
        li->head=node;
    }
    else{
        node->next=li->head;
        li->head->prev=node;
        li->head=node;
    }
}

void list_add_end(list* li, void* val){
    struct list_node *node=(struct)
}



int list_isempty(list* li){
    if(li->head==NULL){
        return 1;
    }
    else{
        return 0;
    }
}