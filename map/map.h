#ifndef map_h
#define map_h

struct map_node{
    void *key , *value;
    struct map_node *left,*right;
};

typedef struct{
    struct map_node *root;
    size_t size;
    char *type;
}map;

map* map_create(char*,char*);
void map_insert(map*,void*,void*);
size_t map_size(map*);
short map_isempty(map*);
void map_clean(map*);


#endif
