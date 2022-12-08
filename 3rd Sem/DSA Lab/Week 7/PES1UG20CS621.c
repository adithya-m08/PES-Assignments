#include<stdio.h>
#define MAX 10

void insert(int *a,int n)
{
    printf("Enter the elements\n");
    for(int i=0;i<n;++i)
        scanf("%d",&a[i]);
}
void display(int *a,int n)
{
    for(int i=0;i<n;++i)
    {
        printf("%d\n",a[i]);
    }
}

void heapifynode(int *a,int n,int i)
{
    if(i<0)
        return;
    int minimum=i;
    int l,r;
    l=2*i+1;
    r=2*i+2;
    
    if(l<n && a[l]<a[i])
        minimum=l;
        
    if(r<n && a[r]<a[minimum])
        minimum=r;
    
    if(minimum !=i)
    {
        int swap =a[minimum];
        a[minimum]=a[i];
        a[i]=swap;
    }
}


void heapify(int *a,int n)
{
    for(int i=0;i<n;++i)
        heapifynode(a,n,(i-1)/2);
}

int main()
{
    int a[MAX],n,ch;
    do
    {
       printf("1) Create   2) Heapify   3) Display   ");
       scanf("%d",&ch);
       
       switch(ch)
       {
            case 1:
                    printf("Enter number of elements ");
                    scanf("%d",&n);
                    insert(a,n);
                    break;
            case 2:
                    heapify(a,n);
                    break;
            case 3:
                    display(a,n);
                    break;
        }
        
     }while(ch<4);
     return 0;
}
