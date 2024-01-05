#include<stdio.h>
#include<stdlib.h>
#include "list.h"

int main(){
    list *li=list_create("int");
    char val[20];
    short choise;
    struct list_node *temp;
    while(1){
        printf("\n1.List push front\n2.List pop front\n3.list push back\n4.List pop back\n5.see\n6.List size\n7.Exit");
        printf("\nEnter your choise:");
        scanf("%d",&choise);
        switch (choise){
            case 1:
                printf("\nEnter value to push front:");
                scanf("%s",val);
                list_push_front(li,val);
                break;
            case 2:
                if(!list_isempty(li)){
                    printf("\nPoped value from front:%s",((char*)list_pop_front(li)));
                }
                else{
                    printf("\nlist is empty....");
                }
                break;
            case 3:
                printf("\nEnter value to push back:");
                scanf("%s",val);
                list_push_back(li,val);
                break;
            case 4:
                if(!list_isempty(li)){
                    printf("\nPoped value from front:%s",((char*)list_pop_back(li)));
                }
                else{
                    printf("\nlist is empty....");
                }
                break;
            case 5:
                temp=li->head;
                while(temp!=NULL){
                    printf("\t%s",((char*)temp->data));
                    temp=temp->next;
                }
                break;
            case 6:
                printf("The size of list:",list_size(li));
            case 7:
                list_clean(li);
                break;
            default :
                printf("\nInvalid input");
        }
        if(choise==7)break;
    }
    return 0;
}