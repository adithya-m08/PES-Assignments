    #include<stdio.h>
#include<stdlib.h>
#include<string.h>


typedef struct node
{
    char srn[20];
    struct node *left;
    struct node *right;
}node;

typedef struct tree
{
    node *root;
}tree;

void insert(tree *t)
{
    int choice;
    node *p,*q, *temp;
    printf("Enter Root SRN\n");
    t->root=(node*)malloc(sizeof(node));
    t->root->left=NULL;
    t->root->right=NULL;
    scanf("%s",t->root->srn);
    
    do
    {
        printf("Enter the next SRN\n");
        temp=(node*)malloc(sizeof(node));
        temp->left=NULL;
        temp->right=NULL;
        scanf("%s",temp->srn);
        p=t->root;
        q=NULL;
        
        while(p!=NULL)
        {
            q=p;
            if(strcmp(p->srn,temp->srn)>0)
                p=p->left;
            else
                p=p->right;
        }
        
        if(strcmp(q->srn,temp->srn)>0)
            q->left=temp;
        else
            q->right=temp;
        
        printf("Do you wish to add more SRNs? (1/0)\n");
        scanf("%d",&choice);
    }while(choice);
}

void search(tree *t, char s[20])
{
    node *p=t->root;
    
    while(strcmp(p->srn,s)&&p!=NULL)
    {
        if(strcmp(p->srn,s)>0)
            p=p->left;
        else
            p=p->right;
    }
    
    if(p!=NULL)
        printf("SRN Found\n");
    else
        printf("SRN Not Found\n");
}

void inorder(node *p)
{
    if(p!=NULL)
    {
        inorder(p->left);
        printf("%s\n",p->srn);
        inorder(p->right);
    }
}

void display(tree *t)
{
    inorder(t->root);
}

int main()
{
    char c[20];
    tree t;
    
    insert(&t);
    
    display(&t);
    
    printf("Enter SRN to search\n");
    scanf("%s",c);
    search(&t,c);
    
    return 0;
}


