#ifndef queue_h
#define queue_h

struct queueNode{
    void* data;
    struct queueNode *next;
};

typedef struct{
    struct queueNode *front , *rear;
    size_t size;
    char *type;
}queue;

queue* createQueue(char*);
void addToQueueC(queue* , void*);
void* removeFromQueueC(queue*);

#endif