#ifndef stack_h
#define stack_h

struct stackNode{
    void* data;
    struct stackNode *prev;
};

struct stack{
    struct stackNode *top;
    int size;
    char *type;
};

stack* createStack(char*);
void push(struct stack* , void*);
void* pop(struct stack*);

#endif
