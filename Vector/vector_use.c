#include<stdio.h>
#include<stdlib.h>
#include "vector.h"

int main(){
    vector *vec=vector_create(sizeof(float));
    vector *swp=vector_create(sizeof(float));
    float val;
    size_t position;
    short choise;
    while(1){
        printf("\n1.Push\n2.Pop\n3.Insert\n4.Remove\n5.Size\n6.Swap\n7.Is_present\n8.Reverse\n9.See\n10.Exit");
        printf("\nEnter your choise:");
        scanf("%d",&choise);
        switch (choise){
            case 1:
                printf("\nEnter value to push:");
                scanf("%f",&val);
                vector_push_back(vec,&val);
                vector_push_back(swp,&val);
                break;
            case 2:
                if(!vector_isempty(vec)){
                    void *temp=vector_pop_back(vec);
                    printf("\nPoped value is %f",*(float*)temp);
                    free(temp);
                }
                else{
                    printf("\nVector is empty...");
                }
                break;
            case 3:
                printf("\nEnter value to insert:");
                scanf("%f",&val);
                printf("\nEnter position for insert:");
                scanf("%d",&position);
                vector_insert(vec,&val,position);
                break;
            case 4:
                printf("\nEnter position for remove:");
                scanf("%d",&position);
                vector_remove(vec,position);
                break;
            case 5:
                printf("\nSize of vector is %d",vector_size(vec));
                break;
            case 6:
                vector_swap(vec,swp);
                break;
            case 7:
                printf("\nEnter value to find:");
                scanf("%f",&val);
                if(vector_ispresent(vec,&val)){
                    printf("\nValue is present");
                }
                else{
                    printf("\nValue is NOT present");
                }
                break;
            case 8:
                vector_reverse(vec);
                break;
            case 9:
                for(size_t i=0;i<vec->size;i++){
                    printf("\t%.2f",((float*)vec->array)[i]);
                }
                break;
            case 10:
                vector_clean(vec);
                vector_clean(swp);
                break;
            default :
                printf("\nInvalid input");
        }
        if(choise==10)break;
    }
    return 0;
}