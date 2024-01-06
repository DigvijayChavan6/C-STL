#include<stdio.h>
#include<stdlib.h>
#include "list.h"

int main(){
    list *li=list_create("int");
    char val[20];
    int num;
    short choise;
    struct list_node *temp;
    while(1){
        printf("\n1.List push front\n2.List pop front\n3.list push back\n4.List pop back\n5.see\n6.List size\n7.Ispresent\n8.Reverse\n9.Exit\n");
        printf("\nEnter your choise:");
        scanf("%d",&choise);
        switch (choise){
            case 1:
                printf("\nEnter value to push front:");
                scanf("%d",&num);
                list_push_front(li,&num);
                break;
            case 2:
                if(!list_isempty(li)){
                    printf("\nPoped value from front:%d",*((int*)list_pop_front(li)));
                }
                else{
                    printf("\nlist is empty....");
                }
                break;
            case 3:
                printf("\nEnter value to push back:");
                scanf("%d",&num);
                list_push_back(li,&num);
                break;
            case 4:
                if(!list_isempty(li)){
                    printf("\nPoped value from front:%d",*((int*)list_pop_back(li)));
                }
                else{
                    printf("\nlist is empty....");
                }
                break;
            case 5:
                temp=li->head;
                while(temp!=NULL){
                    printf("\t%d",*((int*)temp->data));
                    temp=temp->next;
                }
                break;
            case 6:
                printf("The size of list:",list_size(li));
                break;
            case 7:
                printf("Enter the number is to find\n");
                scanf("%d",&num);
                if(list_ispresent(li,&num)){
                    printf("Element is present\n");
                }
                else{
                    printf("Element is not present\n");
                }
                break;
            case 8:
                list_reverse(li);
                break;
            case 9:
                list_clean(li);
                break;
            default :
                printf("\nInvalid input");
        }
        if(choise==9)break;
    }
    return 0;
}