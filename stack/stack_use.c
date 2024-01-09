#include<stdio.h>
#include<stdlib.h>
#include "stack.h"

int main(){
    stack *st=stack_create("string");
    stack *s=stack_create("string");
    char val[20];
    short choise;
    struct stack_node *temp;
    while(1){
        printf("\n1.Push\n2.Pop\n3.Peek\n4.Size\n5.Swap\n6.Is_present\n7.See\n8.Exit");
        printf("\nEnter your choise:");
        scanf("%d",&choise);
        switch (choise){
            case 1:
                printf("\nEnter value to push:");
                scanf("%s",val);
                stack_push(s,val);
                stack_push(st,val);
                break;
            case 2:
                if(!stack_isempty(st)){
                    printf("\nPoped value is %s",((char*)stack_pop(st)));
                }
                else{
                    printf("\nstack is empty...");
                }
                break;
            case 3:
                if(!stack_isempty(st)){
                    printf("\nvalue at peek is %s",((char*)stack_peek(st)));
                }
                else{
                    printf("\nstack is empty...");
                }
                break;
            case 4:
                printf("\nSize of stack is %d",stack_size(st));
                break;
            case 5:
                stack_swap(st,s);
                break;
            case 6:
                printf("\nEnter value to find:");
                scanf("%s",val);
                if(stack_ispresent(st,val)){
                    printf("\nValue is present");
                }
                else{
                    printf("\nValue is NOT present");
                }
                break;
            case 7:
                temp=st->top;
                while(temp!=NULL){
                    printf("\n%s",((char*)temp->data));
                    temp=temp->prev;
                }
                break;
            case 8:
                stack_clean(st);
                stack_clean(s);
                break;
            default :
                printf("\nInvalid input");
        }
        if(choise==8)break;
    }
    return 0;
}