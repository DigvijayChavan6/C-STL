#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "Vector.h"


Vector* createVector(size_t size){
    Vector *vec=(Vector*)malloc(sizeof(Vector));
    vec->array=NULL;
    vec->size=0;
    vec->dataSize=size;
    return vec;
}

void pushBackInVector(Vector *vec, void *val){
    vec->array=realloc(vec->array,(vec->size + 1)*vec->dataSize)
    void *dest = (char *)vec->array + vec->size*vec->dataSize;
    memcpy(dest, val, vec->dataSize);
    vec->size++;
}

void* popBackFromVector(Vector *vec){
    if (vec == NULL || vec->array == NULL || vec->size == 0)return NULL;
    void *val = (char *)vec->array + (vec->size - 1) * vec->dataSize;
    vec->array = realloc(vec->array, (vec->size - 1) * vec->dataSize);
    vec->size--;
    return val;
}

void insertInVector(Vector *vec, void *val, size_t position){
    if(position > vec->size)return;
    for (size_t index = vec->size; index > position; index--){
        void *dest = (char *)vec->array + index * vec->dataSize;
        void *src = (char *)vec->array + (index - 1) * vec->dataSize;
        memcpy(dest, src, vec->dataSize);
    }
    dest=(char *)vec->array + position * vec->dataSize;
    
    memcpy(dest, val, vec->dataSize);
    vec->size++;
}

void removeFromVector(Vector *vec, size_t position){
    if(position>=vec->size)return;
    if(strcmp("STRING",vec->type)==0){
        free((char*)vec->array[position]);
    }
    for(size_t index = position; index < vec->size - 1; index++){
        void *dest = (char *)vec->array + index * vec->dataSize;
        void *src = (char *)vec->array + (index + 1) * vec->dataSize;
        memcpy(dest, src, vec->dataSize);
    }
    vec->array = realloc(vec->array, (vec->size - 1) * vec->dataSize);
    if (vec->array == NULL && vec->size > 1)exit(EXIT_FAILURE);
    vec->size--;
}

size_t sizeOfVector(Vector *vec){
    if(vec == NULL)return 0;
    return vec->size;
}

void swapTwoVectors(Vector *vec1, Vector *vec2){
    if(vec1->dataSize == vec2->dataSize){
        Vector temp=*vec1;
        *vec1=*vec2;
        *vec2=temp;
    }
}

short isPresentInVector(Vector *vec, void *val){
    if(vec==NULL)return 0;
    for(size_t index = 0; index < vec->size; index++){
        void *currentElement = (char *)vec->array + index * vec->dataSize;
        if(memcmp(currentElement, val, vec->dataSize) == 0)return 1;
    }
    return 0;
}

short isEmptyVector(Vector *vec){
    if(vec==NULL || vec->array==NULL || vec->size==0)return 1;
    return 0;
}

void cleanVector(Vector *vec){
    if(strcmp("STRING",vec->type)==0){
        for(size_t i=0;i<vec->size;i++){
            free((char*)vec->array[i]);
        }
    }
    free(vec->array);
    free(vec->type);
    free(vec);
}