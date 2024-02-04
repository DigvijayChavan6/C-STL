#ifndef vector_h
#define vector_h

typedef struct{
    void *array;
    size_t size,data_size;
    char *type;
}vector;

vector *vector_create(size_t);

void vector_push_back(vector*, void*);
void *vector_pop_back(vector*);
void vector_insert(vector*,void*,size_t);
void vector_remove(vector*,size_t);

size_t vector_size(vector*);
void vector_swap(vector*,vector*);
short vector_ispresent(vector*,void*);
short vector_isempty(vector*);
void vector_clean(vector*);
void vector_reverse(vector*);

#endif