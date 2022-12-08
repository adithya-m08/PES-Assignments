#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
	int data;
	struct node *left;
	struct node *right;
}node;

typedef struct tree
{
	node *root;
}tree;

void init(tree *t)
{
    t->root=NULL;
}

void insert(tree *t)
{
    int n;
    node *temp, *p, *q;
    printf("Enter number of elements\n");
    scanf("%d",&n);
    
    printf("Enter root element\n");
    t->root=(node*)malloc(sizeof(node));
	t->root->left=NULL;
	t->root->right=NULL;
	scanf("%d",&t->root->data);
	
	for(int i=0;i<n-1;i++)
	{
	    temp=(node*)malloc(sizeof(node));
		temp->left=NULL;
		temp->right=NULL;
		
		printf("Enter the next node\n");
		scanf("%d",&temp->data);
		q=NULL;
		p=t->root;
		
		while(p!=NULL) 
		{
			q=p;
			if(temp->data < p->data)	
				p=p->left;
			else
				p=p->right;
		}
		
		if(temp->data < q->data) 
			q->left=temp;
		else
			q->right=temp;
	}
}

void inorder(node *p)
{
	if(p!=NULL)
	{
		inorder(p->left);
		printf("%d\n",p->data);
		inorder(p->right);
	}
}

void traversal(tree *t) 
{
	inorder(t->root);
}

node* min(node *p)
{
    node *q=p;
    while(q && q->left!=NULL)
        q=q->left;
        
    return q;
}

node* delete(node *t, int ele)
{
    node *temp;
    if(t==NULL)
    {
        printf("Element not found\n");
        return t;
    }
    
    if(ele < t->data)
        t->left=delete(t->left,ele);
    
    else if(ele>t->data)
        t->right=delete(t->right,ele);
        
    else
    {
        if(t->left==NULL && t->right ==NULL)
            return NULL;
            
        else if (t->left == NULL) 
        {
			temp = t->right;
			free(t);
			return temp;
		}
		
		else if (t->right == NULL) 
		{
			temp = t->left;
			free(t);
			return temp;
		}
		
		temp = min(t->right);
		t->data = temp->data;
		t->right = delete(t->right, temp->data);
    }
    return t;
}


int main()
{
    tree *t;
    int ch,ele;
    do
    {
        printf("1) Create   2) Inorder   3) Delete   ");
        scanf("%d",&ch);
        
        switch(ch)
        {
            case 1:
                insert(t);
                break;
            
            case 2:
                traversal(t);
                break;
            case 3:
                printf("Enter element ");
                scanf("%d",&ele);
                t->root=delete(t->root, ele);
                break;
        }
        
    }while(ch<4);    
}
