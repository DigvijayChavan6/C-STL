#ifndef dqueue_h
#define dqueue_h

struct dqueue_node{
    void* data;
    struct dqueue_node *next,*prev;
};

typedef struct{
    struct dqueue_node *front , *rear;
    size_t size;
    char *type;
}dqueue;

dqueue* dqueue_create(char*);
struct dqueue_node* create_dqueue_node(dqueue*,void*);

void dqueue_push_front(dqueue*,void*);
void dqueue_push_back(dqueue*,void*);
void* dqueue_pop_front(dqueue*);
void* dqueue_pop_back(dqueue*);

size_t dqueue_size(dqueue*);
void dqueue_swap(dqueue*,dqueue*);
short dqueue_ispresent(dqueue*,void*);
short dqueue_isempty(dqueue*);
void dqueue_clean(dqueue*);
void dqueue_reverse(dqueue*);

#endif