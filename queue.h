#ifndef queue_h
#define queue_h

struct queue_node{
    void *data;
    struct queue_node *next;
};

typedef struct{
    queue_node *front,*rear;
    size_t size;
    char *type;
}queue;

queue* queue_create(char* data_type)
void queue_insert(queue*, void*);
void* queue_remove(queue*);
short queue_isempty(queue*);
void queue_clean(queue*);

#endif