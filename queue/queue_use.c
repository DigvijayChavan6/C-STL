#include<stdio.h>
#include<stdlib.h>
#include "queue.h"

int main(){
    queue *qu=queue_create("string");
    queue *q=queue_create("string"),*t;
    char val[20];
    short choise;
    struct queue_node *temp;
    while(1){
        printf("\n1.Push\n2.Pop\n3.Size\n4.Swap\n5.Is_present\n6.Reverse\n7.See\n8.Peek\n9.Exit");
        printf("\nEnter your choise:");
        scanf("%d",&choise);
        switch (choise){
            case 1:
                printf("\nEnter value to push:");
                scanf("%s",val);
                queue_push(q,val);
                queue_push(qu,val);
                break;
            case 2:
                if(!queue_isempty(qu)){
                    printf("\nPoped value is %s",((char*)queue_pop(qu)));
                }
                else{
                    printf("\nqueue is empty...");
                }
                break;
            case 3:
                printf("\nSize of queue is %d",queue_size(qu));
                break;
            case 4:
                queue_swap(qu,q);
                break;
            case 5:
                printf("\nEnter value to find:");
                scanf("%s",val);
                if(queue_ispresent(qu,val)){
                    printf("\nValue is present");
                }
                else{
                    printf("\nValue is NOT present");
                }
                break;
            case 6:
                queue_reverse(qu);
                break;
            case 7:
                temp=qu->front;
                while(temp!=NULL){
                    printf("<- %s ",((char*)temp->data));
                    temp=temp->next;
                }
                break;
            case 9:
                queue_clean(qu);
                queue_clean(q);
                break;
            case 8:
                if(!queue_isempty(qu)){
                    printf("\nPeeked value is %s",((char*)queue_pop(qu)));
                }
                else{
                    printf("\nqueue is empty...");
                }
                break;
                default :
                printf("\nInvalid input");
        }
        if(choise==9)break;
    }
    return 0;
}