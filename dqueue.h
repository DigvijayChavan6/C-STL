#ifndef dqueue_h
#define dqueue_h

struct dqueue_node{
    void* data;
    struct dqueue_node *next,*prev;
};

typedef struct{
    struct dqueue_node *front , *rear;
    unsigned int size;
    char *type;
}dqueue;

dqueue* dqueue_create(char*);
void dqueue_push_front(dqueue* , void*);
void* dqueue_pop_front(dqueue*);
void dqueue_push_back(dqueue* , void*);
void* dqueue_pop_back(dqueue*);

#endif