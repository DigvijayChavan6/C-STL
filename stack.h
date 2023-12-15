#ifndef stack_h
#define stack_h

typedef struct{
    void* data;
    stackNode *prev;
}stackNode;

typedef struct{
    stackNode *top;
    size_t size;
    char *type;
}stack;

stack* createStack(char*);
void push(stack* , void*);
void* pop(stack*);

#endif
