#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "vector.h"


vector* vector_create(size_t size){
    vector *vec=(vector*)malloc(sizeof(vector));
    vec->array=NULL;
    vec->size=0;
    vec->data_size=size;
    return vec;
}

void vector_push_back(vector *vec, void *val){
    vec->array=realloc(vec->array,(vec->size+1)*vec->data_size);
    memcpy((char*)vec->array+vec->data_size*vec->size,val,vec->data_size);
    vec->size++;
}

void* vector_pop_back(vector *vec){
    if (vec == NULL || vec->array == NULL || vec->size == 0)return NULL;
    void *val = malloc(vec->data_size);
    memcpy(val,(char *)vec->array + (vec->size - 1) * vec->data_size,vec->data_size);
    vec->array = realloc(vec->array, (vec->size - 1) * vec->data_size);
    vec->size--;
    return val;
}

void vector_insert(vector *vec, void *val, size_t position){
    if(position > vec->size+1)return;
    vec->array=realloc(vec->array,(vec->size+1)*vec->data_size);
    for (size_t index = vec->size; index > position; index--){
        void *dest = (char *)vec->array + index * vec->data_size;
        void *src = (char *)vec->array + (index - 1) * vec->data_size;
        memcpy(dest, src, vec->data_size);
    }
    void *dest=(char *)vec->array + position * vec->data_size;
    memcpy(dest, val, vec->data_size);
    vec->size++;
}

void vector_remove(vector *vec, size_t position){
    if(position>=vec->size)return;
    for(size_t index = position; index < vec->size - 1; index++){
        void *dest = (char *)vec->array + index * vec->data_size;
        void *src = (char *)vec->array + (index + 1) * vec->data_size;
        memcpy(dest, src, vec->data_size);
    }
    vec->array = realloc(vec->array, (vec->size - 1) * vec->data_size);
    vec->size--;
}

size_t vector_size(vector *vec){
    if(vec == NULL)return 0;
    return vec->size;
}

void vector_swap(vector *vec1, vector *vec2){
    if(vec1->data_size == vec2->data_size){
        vector *temp=malloc(sizeof(vector));
        *temp=*vec1;
        *vec1=*vec2;
        *vec2=*temp;
        free(temp);
    }
}

short vector_ispresent(vector *vec, void *val){
    if(vec==NULL)return 0;
    for(size_t index = 0; index < vec->size; index++){
        void *currentElement = (char *)vec->array + index * vec->data_size;
        if(memcmp(currentElement, val, vec->data_size) == 0)return 1;
    }
    return 0;
}

short vector_isempty(vector *vec){
    if(vec==NULL || vec->array==NULL || vec->size==0)return 1;
    return 0;
}

void vector_clean(vector *vec){
    free(vec->array);
    free(vec);
}

void vector_reverse(vector *vec){
    if(vec==NULL)return;
    void *temp=malloc(vec->data_size);
    for(size_t index = 0 ,back=vec->size-1; index < vec->size/2; index++,back--){
        void *dex = (char*)vec->array + index * vec->data_size;
        void *ack = (char*)vec->array + back * vec->data_size;
        memcpy(temp,dex,vec->data_size);
        memcpy(dex,ack,vec->data_size);
        memcpy(ack,temp,vec->data_size);
    }
    free(temp);
}