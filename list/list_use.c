#include<stdio.h>
#include<stdlib.h>
#include "list.h"

int main(){
    list *li=list_create("int");
    list *lt=list_create("int");
    int num;
    size_t pos;
    short choise;
    struct list_node *temp;
    while(1){
        printf("\n1.Push front\n2.Pop front\n3.Push back\n4.Pop back\n5.Insert\n6.Remove\n7.Size\n8.Swap\n9.Ispresent\n10.Reverse\n11.See\n12.Exit\n");
        printf("\nEnter your choise:");
        scanf("%d",&choise);
        switch (choise){
            case 1:
                printf("\nEnter value to push front:");
                scanf("%d",&num);
                list_push_front(li,&num);
                list_push_front(lt,&num);
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
                list_push_back(lt,&num);
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
                printf("\nEnter value for insert:");
                scanf("%d",&num);
                printf("\nEnter position for insert:");
                scanf("%d",&pos);
                list_insert(li,pos,&num);
                break;
            case 6:
                printf("\nEnter position for remove:");
                scanf("%d",&pos);
                if(!list_isempty(li)){
                    list_remove(li,pos);
                    printf("\nValue is removed");
                }
                else{
                    printf("\nlist is empty....");
                }
                break;
            case 7:
                printf("\nThe size of list : %d",list_size(li));
                break;
            case 8:
                list_swap(li,lt);
                break;
            case 9:
                printf("\nEnter the number is to find :");
                scanf("%d",&num);
                if(list_ispresent(li,&num)){
                    printf("\nElement is present");
                }
                else{
                    printf("\nElement is not present");
                }
                break;
            case 10:
                list_reverse(li);
                break;
            case 11:
                temp=li->head;
                while(temp!=NULL){
                    printf("\t%d",*((int*)temp->data));
                    temp=temp->next;
                }
                break;
            case 12:
                list_clean(li);
                list_clean(lt);
                break;
            default :
                printf("\nInvalid input");
        }
        if(choise==12)break;
    }
    return 0;
}