#ifndef list_h
#define list_h

struct list_node{
    void* data;
    struct list_node *next;
};

typedef struct{
    struct list_node *head;
    size_t size;
    char *type;
}list;

list* list_create(char*);
struct list_node* create_list_node(list*,void*);

void list_push_front(list* , void*);
void* list_pop_front(list*);
void list_push_back(list* , void*);
void* list_pop_back(list*);

void list_insert(list*,size_t,void*);
void* list_remove(list*,size_t);

size_t list_size(list*);
void list_swap(list*,list*);
short list_ispresent(list*,void*);
short list_isempty(list*);
void list_clean(list*);
list* list_reverse(list*);

#endif