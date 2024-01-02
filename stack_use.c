#include<stdio.h>
#include<stdlib.h>
#include "stack.h"

int main(){
    stack *st=stack_create("string");
    char val[20];
    short choise;
    struct stack_node *t;
    while(1){
        printf("\n1.Push\n2.Pop\n3.Peek\n4.See\n5.Exit");
        printf("\nEnter your choise:");
        scanf("%d",&choise);
        switch (choise){
            case 1:
                printf("\nEnter value to push:");
                scanf("%s",val);
                stack_push(st,val);
                break;
            case 2:
                if(st->top!=NULL){
                    printf("\nPoped value is %s",((char*)stack_pop(st)));
                }
                else{
                    printf("\nstack is empty...");
                }
                break;
            case 3:
                if(st->top!=NULL){
                    printf("\nvalue at peek is %s",((char*)stack_peek(st)));
                }
                else{
                    printf("\nstack is empty...");
                }
                break;
            case 4:
                t=st->top;
                while(t!=NULL){
                    printf("\n%s",((char*)t->data));
                    t=t->prev;
                }
                break;
            case 5:
                //stack_clean(st);
                while(st->top!=NULL){
                    struct stack_node *t=st->top;
                    st->top=st->top->prev;
                    free(t);
                }
                free(st);
                break;
            default :
                printf("\nInvalid input");
        }
        if(choise==5)break;
    }
    return 0;
}