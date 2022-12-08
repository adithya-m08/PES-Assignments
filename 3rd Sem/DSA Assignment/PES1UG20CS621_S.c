#include<stdio.h>
#include<stdlib.h>
#include"header.h"

int max = -1;
void init(ll **p)
{
    *p = NULL;
}

ll* create_row(int x)
{
    ll *temp = (ll*)malloc(sizeof(ll));
    temp->x = x;
    temp->head = NULL;
    temp->next = NULL;
    return temp;
}

void insert_row(ll **p)
{
    if(*p == NULL)
        *p = create_row(0);
    else
    {
        ll *temp = *p;
        while(temp->next)
            temp = temp->next;
        temp->next  = create_row((temp->x) + 1);
    }
    max++;
}

node* create_node(int x,int y)
{
    node *temp = (node*)malloc(sizeof(node));
    temp->x = x;
    temp->y = y;
    temp->visit = 0;
    temp->right = NULL;
    temp->down = NULL;
    return temp;
}

void insert_node(ll **p,int x,int y)
{
    node *temp = create_node(x,y);
    node *temp_node = NULL;
    ll *temp_row = *p;

    while(temp_row->next)
        temp_row = temp_row->next;
    temp_node = temp_row->head;

    if(temp_node == NULL)
    {
        temp_row->head = temp;
    }
    else
    {
        while(temp_node->right)
            temp_node = temp_node->right;
        temp_node->right = temp;
    }
}

void insert(ll **p,int x,int y)
{
    if(x > max)
        insert_row(p);
    insert_node(p,x,y);
}

void linker(ll **p)
{
    ll *a = *p;
    ll *b = a->next;

    while(b)
    {
        node *temp1 = a->head;
        node *temp2 = b->head;
        while(temp1 && temp2)
        {
            if(temp1->y == temp2->y)
            {
                temp1->down = temp2;
                temp1 = temp1->right;
                temp2 = temp2->right;
            }
            else if(temp1->y > temp2->y)
                temp2 = temp2->right;
            else
                temp1 = temp1->right;

        }
        a = a->next;
        b = b->next;
    }
}

int filled(ll **p,int x,int y)
{
    int status = 0;
    ll *temp = *p;
    while(temp->next!=NULL && temp->x!=x)
        temp = temp->next;
    
    node *temp_node = temp->head;
    while(temp_node)
    {
        if(temp_node->y == y)
        {
            status = 1;
            break;
        }
        temp_node = temp_node->right;    
    }
    return status;
}

node *pop(ll **p,int x,int y)
{
    ll *temp = *p;
    while(temp->next!=NULL && temp->x!=x)
        temp = temp->next;
    
    node *temp_node = temp->head;
    while(temp_node)
    {
        if(temp_node->y == y)
        {
            break;
        }
        temp_node = temp_node->right;    
    }
    return temp_node;
}

void export(node *arr[],int n,int status)
{
    FILE *fp = fopen("output.txt","w");
    if(status)
    for(int i=0;i<=n;i++)
    {
        fprintf(fp,"%d %d\n",arr[i]->x,arr[i]->y);
        printf("%d: %d %d\n",i,arr[i]->x,arr[i]->y);
    }
    else
    {
        fprintf(fp,"-1\n");
        printf("No Path Found!\n");
    }
    fclose(fp);
}

void path(ll **p,int start_x,int start_y,int end_x,int end_y)
{
    node *arr[1000];
    linker(p);

    if(start_x > end_x || start_y > end_y)
        export(arr,0,0);
    else if(start_x == end_x && start_y == end_y)
    {
        arr[0] = pop(p,start_x,start_y);
        export(arr,0,1);
    }
    else if(filled(p,start_x,start_y) && filled(p,end_x,end_y))
    {
        int move = 0;
        int status = 1;
        arr[0] = pop(p,start_x,start_y);
        while(status)
        {
            if(arr[move]->right != NULL && !arr[move]->right->visit && (arr[move]->right->y - arr[move]->y)==1)
            {
                arr[move + 1] = arr[move]->right;
                arr[move + 1]->visit = 1;
                move++;
                if(arr[move]->x == end_x && arr[move]->y == end_y)
                {
                    status = 0;
                }
            }
            else if(arr[move]->down != NULL && !arr[move]->down->visit)
            {
                arr[move + 1] = arr[move]->down;
                arr[move + 1]->visit = 1;
                move++;
                if(arr[move]->x == end_x && arr[move]->y == end_y)
                {
                    status = 0;
                }
            }
            else
            {
                arr[move] = NULL;
                move--;
            }
            if(arr[0] == NULL)
            {
                status = 0;
            }
        }
        if(arr[0] != NULL)
            export(arr,move,1);
        else
            export(arr,0,0);
    }

    else
        export(arr,0,0);
}