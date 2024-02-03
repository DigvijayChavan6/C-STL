#include<stdio.h>
#include "Vector.h"

int main(){
    printf("Hello Dear");
    Vector *vec=createVector("string",sizeof(char*));
    char *a="demo";
    char *y="dingo";
    pushBackInVector(vec,a);
    pushBackInVector(vec,y);
    return 0;
}