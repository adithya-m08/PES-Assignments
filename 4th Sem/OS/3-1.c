#include <stdio.h>
#include <stdlib.h>

struct list
{
    int seg;
    int b;
    int l;
    struct list *next;
} * p;

void insert(struct list *q, int b, int l, int seg)
{
    if (p == NULL)
    {
        p = malloc(sizeof(struct list));
        p->l = l;
        p->b = b;
        p->seg = seg;
        p->next = NULL;
    }

    else
    {
        while (q->next != NULL)
        {
            q = q->next;
            printf("yes");
        }

        q->next = malloc(sizeof(struct list));
        q->next->l = l;
        q->next->b = b;
        q->next->seg = seg;
        q->next->next = NULL;
    }
}

int find(struct list *q, int seg)
{
    while (q->seg != seg)
        q = q->next;

    return q->l;
}

int search(struct list *q, int seg)
{
    while (q->seg != seg)
        q = q->next;
    return q->b;
}

void main()
{
    p = NULL;
    int seg, offset, l, b, c, s, physical;
    printf("Enter Segment Table (-1 to exit)\n");

    do
    {
        printf("Enter Segment Number ");
        scanf("%d", &seg);
        if (seg != -1)
        {
            printf("Enter Base Value ");
            scanf("%d", &b);
            printf("Enter Value for Limit ");
            scanf("%d", &l);
            insert(p, b, l, seg);
        }
    } while (seg != -1);

    printf("Enter offset ");
    scanf("%d", &offset);
    printf("Enter bsegmentation number ");
    scanf("%d", &seg);
    c = find(p, seg);
    s = search(p, seg);
    if (offset < c)
    {
        physical = s + offset;
        printf("Address in physical memory %d\n", physical);
    }

    else
    {
        printf("Error");
    }
}