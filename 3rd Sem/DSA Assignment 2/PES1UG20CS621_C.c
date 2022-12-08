#include <stdio.h>
#include <stdlib.h>
#include "PES1UG20CS621_H.h"
int main()
{
    FILE *ptr1;
    ptr1 = fopen("input.txt", "r");
    int start_r, start_c, end_r, end_c, arr[10][10], label[10][10], id_count;
    fscanf(ptr1, "%d %d", &start_r, &start_c);
    fscanf(ptr1, "%d %d", &end_r, &end_c);

    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
            fscanf(ptr1, "%d", &arr[i][j]);
    }

    node_t *a[100];
    id_count = label_id(arr, label);

    int path[100];
    create_graph(a, arr, label, id_count);
    int start = label[start_r][start_c];
    int end = label[end_r][end_c];
    int r = dfs(start, end, a, path);

    FILE *ptr2 = fopen("outdfs.txt", "w");
    if (r != 0)
    {
        int i = path_lenght();
        for (int l = 0; l < i; l++)
            fprintf(ptr2, "%d %d\n", co_ordinate(label, path[l]).x, co_ordinate(label, path[l]).y);
    }
    else
        fprintf(ptr2, "%d ", -1);
    bfs(start, end, a, label);
    return 0;
}