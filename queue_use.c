#include<stdio.h>
#include<stdlib.h>
#include "queue.h"

int main(){
    queue *q=queue_create("string");
    char val[20];
    short choise;
    struct queue_node *temp;
    while(1){
        printf("\n1.push\n2.pop\n3.see all data\n4.size of queue\n5.Ispresent\n6.queue reverse\n7.Exit\n");
        printf("\nEnter your choise:");
        scanf("%d",&choise);
        switch (choise){
            case 1:
                printf("\nEnter value to push:");
                scanf("%s",val);
                queue_push(q,val);
                break;
            case 2:
                if(!queue_isempty(q)){
                    printf("\nPoped value is %s",((char*)queue_pop(q)));
                }
                else{
                    printf("\nqueue is empty...");
                }
                break;
            case 3:
                temp=q->front;
                while(temp!=NULL){
                    printf("-> %s ",((char*)temp->data));
                    temp=temp->next;
                }
                break;
            case 4:
                printf("\nsize of dequeue is %d",queue_size(q));
                break;
            case 5:
                printf("Enter the element to find\n");
                scanf("%s",val);
                if(queue_ispresent(q,val))printf("Element is present\n");
                else printf("Element is not present\n");
                break;
            case 6:
                queue_reverse(q);
                break;
            case 7:
                queue_clean(q);
                break;
            default :
                printf("\nInvalid input");
        }
        if(choise==7)break;
    }
    return 0;
}