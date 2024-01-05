#ifndef map_h
#define map_h

struct map_node{
    void *key , *value;
    struct map_node *next;
};

typedef struct{
    struct map_node *head;
    size_t size;
    char *type;
}map;

map* map_create(char*,char*);
void map_push(map*,void*,void*);

size_t map_size(map*);
short map_isempty(map*);
void map_clean(map*);
#include<stdio.h>

#endif
// this is just comment