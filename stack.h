#ifndef stack_h
#define stack_h

struct stackNode{
    void* data;
    struct stackNode *prev;
};

typedef struct{
    struct stackNode *top;
    unsigned int size;
    char *type;
}stack;

stack* createStack(char*);
void pushC(stack* , void*);
void* popC(stack*);

#endif