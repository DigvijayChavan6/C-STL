#ifndef Vector_h
#define Vector_h

typedef struct{
    void *array;
    size_t size, dataSize;
}Vector;

Vector *createVector(size_t);

void pushBackInVector(Vector*, void*);
void *popBackFromVector(Vector*);
void insertInVector(Vector*,void*,size_t);
void removeFromVector(Vector*,size_t);

size_t sizeOfVector(Vector*);
void swapTwoVectors(Vector*,Vector*);
short isPresentInVector(Vector*,void*);
short isEmptyVector(Vector*);
void cleanVector(Vector*);

#endif