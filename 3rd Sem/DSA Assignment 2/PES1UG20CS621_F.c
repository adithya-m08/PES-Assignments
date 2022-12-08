#include <stdio.h>
#include <stdlib.h>
#include "PES1UG20CS621_H.h"

int visited[100] = {0};
int f = -1, re = -1;
void enque(queue *q, int i)
{
    if (re == 199)
        return;
    re++;
    q->arr[re] = i;
}

int deque(queue *q)
{
    f++;
    int u = q->arr[f];
    return u;
}

int isempty(queue q)
{
    if (f == re)
        return 1;
    return 0;
}

int label_id(int arr[][10], int label[][10])
{
    int id = 0;
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            if (arr[i][j] == 0)
            {
                id++;
                label[i][j] = id;
            }
        }
    }
    return id;
}

void insert_node_front(node_t *a[], int src, int dest, int i, int j)
{
    node_t *temp;

    if (a[src] == NULL)
    {
        temp = (node_t *)malloc(sizeof(node_t));
        temp->next = NULL;
        temp->info = dest;
        temp->x = i;
        temp->y = j;
        a[src] = temp;
    }
    else
    {

        temp = (node_t *)malloc(sizeof(node_t));
        temp->next = a[src];
        temp->info = dest;
        temp->x = i;
        temp->y = j;
        a[src] = temp;
    }
}

void create_graph(node_t *a[], int arr[][10], int label[][10], int id)
{
    for (int i = 1; i <= id; i++)
        a[i] = NULL;

    for (int i = 0; i < 10; i++)
    {

        for (int j = 0; j < 10; j++)
        {
            if (arr[i][j] == 0)
            {
                if (i != 9)
                {

                    if (arr[i + 1][j] == 0)
                    {
                        insert_node_front(a, label[i][j], label[i + 1][j], i + 1, j);
                    }
                }
                if (j != 9)
                {

                    if (arr[i][j + 1] == 0)
                        insert_node_front(a, label[i][j], label[i][j + 1], i, j + 1);
                }
            }
        }
    }
}

int i = 0;
int dfs(int src, int dest, node_t *arr[], int path[])
{

    node_t *temp;
    int r;

    if (visited[src] == 0)
    {

        temp = arr[src];
        path[i] = src;
        i++;
        visited[src] = 1;

        while (temp != NULL)
        {
            if (visited[temp->info] == 0)
            {

                if (temp->info == dest)
                {
                    path[i] = temp->info;
                    i++;
                    return 1;
                }
                r = dfs(temp->info, dest, arr, path);
                if (r == 1)
                {
                    break;
                }
            }
            temp = temp->next;
        }
    }
    if (temp != NULL)
    {
        return 1;
    }
    i--;
    return 0;
}

int path_lenght()
{
    return i;
}

coordinate co_ordinate(int arr[][10], int k)
{
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            if (arr[i][j] == k)
            {
                coordinate co_od;
                co_od.x = i;
                co_od.y = j;
                return co_od;
            }
        }
    }
}

int indexof(int i, vector path[])
{
    int k = 0;
    for (k = 0; k < 100; k++)
    {
        if (path[k].i == i)
            break;
    }
    return k;
}

void bfs(int src, int dest, node_t *arr[], int label[][10])
{

    int u, found = 0;
    int iv = 0;
    node_t *t;
    queue q;
    vector pathV[100], p;

    enque(&q, src);
    visited[src] = 1;
    while (!isempty(q))
    {
        u = deque(&q);
        t = arr[u];

        while (t != NULL)
        {
            if (t->info == dest)
            {
                p.i = t->info;
                p.prev = u;
                pathV[iv] = p;
                iv++;
                found = 1;
                break;
            }
            p.i = t->info;
            p.prev = u;
            pathV[iv] = p;
            iv++;
            enque(&q, t->info);
            t = t->next;
        }
        if (found == 1)
            break;
    }

    FILE *ptr = fopen("outbfs.txt", "w");
    if (found == 1)
    {
        int bfspath[30], b = 0;
        iv--;
        while (1)
        {
            bfspath[b] = pathV[iv].i;
            b++;
            iv = indexof(pathV[iv].prev, pathV);

            if (pathV[iv].i == src)
            {
                bfspath[b] = src;
                b++;
                break;
            }
        }
        for (int i = b - 1; i >= 0; i--)
            fprintf(ptr, "%d %d\n", co_ordinate(label, bfspath[i]).x, co_ordinate(label, bfspath[i]).y);
    }
    else
        fprintf(ptr, "%d ", -1);
}
