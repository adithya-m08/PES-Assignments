#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"header.h"

void init(customerDetails *p)
{
        p->head=NULL;
}

node_t* createnode()
{
        node_t *temp=(node_t*)malloc(sizeof(node_t));
        printf("Name :");
        scanf("%s",temp->name);
        printf("phone number :");
        scanf("%d",&temp->phone_number);
        printf("address :");
        scanf("%s",temp->address);
        printf("area :");
        scanf("%s",temp->area);
        temp->next=NULL;
        temp->prev=NULL;
        printf("\n");
        
        return temp;
}
void insert(customerDetails *p)
{
        node_t *temp=createnode();
        if(p->head==NULL)
        {
                p->head=temp;
        }       
        
        else
        {
                node_t *pres=p->head;
                node_t *prev=NULL;
                while((pres!=NULL) && (strcmp(pres->name,temp->name)<0))
                {
                        prev=pres;
                        pres=pres->next;
                }
                if(prev==NULL)
                {
                        temp->next=pres;
                        pres->prev=temp;
                        p->head=temp;
                }
                else if(pres==NULL)
                {
                        prev->next=temp;
                        temp->prev=prev;
                }
                else
                {
                        prev->next=temp;
                        temp->prev=prev;
                        pres->prev=temp;
                        temp->next=pres;
                }
        }
}

void display(customerDetails *p)
{
        if(p->head==NULL)
        {
                printf("Empty list");
        }
        else
        {
             node_t *pres=p->head;   
             while(pres!=NULL)
             {
                printf("%s %d %s %s\n",pres->name,pres->phone_number,pres->address,pres->area);
                pres=pres->next;
             }
        }
}
