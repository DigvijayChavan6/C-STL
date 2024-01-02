#include<stdio.h>
#include "stack.h"

int main(){
    stack *st=stack_create("int");
    int n=1;
    int val;
    
    while (n!=-1){
        printf("\nYou wan't pop or push:");
        char k;
        scanf(" %c",&k);
        if(k=='y'){
            printf("\nEnter value:");
            scanf("%d",&val);
            stack_push(st,&val);
        }
        else{
            if(st->top!=NULL)printf("\npoped value is %d",*((int*)stack_pop(st)));
            else{
                printf("\nstack is empty...");
            }
        }
        printf("\nEnter to continue:");
        scanf("%d",&n);
    }
    
    return 0;
}