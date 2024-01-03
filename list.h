#ifndef list_h
#define list_h

struct list_node{
    void* data;
    struct list_node *next,*prev;
};

typedef struct{
    struct list_node *head;
    unsigned int size;
    char *type;
}list;

list* list_create(char*);
void list_add_begin(list* , void*);
void* list_delete_begin(list*);
void list_add_end(list* , void*);
void* list_delete_back(list*);
void list_insert(list*,unsigned int);
int list_isempty(list*);

#endif