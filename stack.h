#ifndef stack_h
#define stack_h

struct stack_node{
    void* data;
    struct stack_node *prev;
};

typedef struct{
    struct stack_node *top;
    size_t size;
    char *type;
}stack;

stack* stack_create(char*);
void stack_push(stack* , void*);
void* stack_pop(stack*);
void* stack_peek(stack*);
short stack_isempty(stack*);
void stack_clean(stack*);

#endif