#include<stdio.h>
#include<stdlib.h>
#include "dqueue.h"

int main(){
    dqueue *q=dqueue_create("string");
    char val[20];
    short choise;
    struct dqueue_node *temp;
    while(1){
        printf("\n1.push_back\n2.push_front\n3.pop_back\n4.pop_front\n5.see all data\n6.size of dqueue\n7.Ispresent\n8.Dqueue reverse\n9.Exit\n");
        printf("\nEnter your choise:");
        scanf("%d",&choise);
        switch (choise){
            case 1:
                printf("\nEnter value to push_back:");
                scanf("%s",val);
                dqueue_push_back(q,val);
                break;
            case 2:
                printf("\nEnter value to push_front:");
                scanf("%s",val);
                dqueue_push_front(q,val);
                break;
            case 3:
                if(!dqueue_isempty(q)){
                    printf("\nPoped value from back is %s",((char*)dqueue_pop_back(q)));
                }
                else{
                    printf("\ndqueue is empty...");
                }
                break;
            case 4:
                if(!dqueue_isempty(q)){
                    printf("\nPoped value from front is %s",((char*)dqueue_pop_front(q)));
                }
                else{
                    printf("\ndqueue is empty...");
                }
                break;
            case 5:
                temp=q->front;
                while(temp!=NULL){
                    printf("-> %s ",((char*)temp->data));
                    temp=temp->next;
                }
                break;
            case 6:
                printf("\nsize of dequeue is %d",dqueue_size(q));
                break;
            case 7:
                printf("Enter the element to find\n");
                scanf("%s",val);
                if(dqueue_ispresent(q,val)){
                    printf("Element is present\n");
                }
                else{
                    printf("Element is not present\n");
                }
                break;
            case 8:
                dqueue_reverse(q);
                break;
            case 9:
                dqueue_clean(q);
                break;
            default :
                printf("\nInvalid input");
        }
        if(choise==9)break;
    }
    return 0;
}