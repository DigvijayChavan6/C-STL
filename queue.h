#ifndef queue_h
#define queue_h

struct queue_node{
    void *data;
    struct queue_node *next;
};

typedef struct{
    struct queue_node *front,*rear;
    size_t size;
    char *type;
}queue;

queue* queue_create(char* data_type);

void queue_push(queue*, void*);
void* queue_pop(queue*);
short queue_isempty(queue*);
size_t queue_size(queue*);
short queue_ispresent(queue*,void*);
void queue_reverse(queue*);
void queue_clean(queue*);
void queue_swap(queue*, struct queue_node*, struct queue_node*);
#endif