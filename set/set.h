#ifndef set_h
#define set_h

struct set_node{
    void *data;
    struct set_node *left,*right;
};

typedef struct{
    struct set_node *root;
    size_t size;
    char *type;
}set;

set* set_create(char* data_type);

void set_insert(set*, void*);
void* set_remove(set*);

// size_t set_size(set*);
// void set_swap(set*,set*);
// short set_ispresent(set*,void*);
// short set_isempty(set*);
// void set_clean(set*);
// void set_reverse(set*);
// void* set_peek(set*);

#endif