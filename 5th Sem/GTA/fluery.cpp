#include <iostream>
#include <vector>
#include <bits/stdc++.h>
#define MAX 5
using namespace std;
int graph[MAX][MAX] = {{0, 1, 1, 1, 1},
                       {1, 0, 1, 1, 0},
                       {1, 1, 0, 1, 0},
                       {1, 1, 1, 0, 1},
                       {1, 0, 0, 1, 0}};
int temp[MAX][MAX];

int start_vertex()
{
    for (int i = 0; i < MAX; i++)
    {
        int deg = 0;
        for (int j = 0; j < MAX; j++)
        {
            if (temp[i][j])
                deg++;
        }
        if (deg % 2 != 0)
            return i;
    }
    return 0;
}

bool isBridge(int u, int v)
{
    int deg = 0;
    for (int i = 0; i < MAX; i++)
        if (temp[v][i])
            deg++;
    if (deg > 1)
        return false;
    return true;
}

int edgeCount()
{
    int count = 0;
    for (int i = 0; i < MAX; i++)
        for (int j = i; j < MAX; j++)
            if (temp[i][j])
                count++;
    return count;
}

void fleury(int start)
{
    static int edge = edgeCount();
    for (int v = 0; v < MAX; v++)
    {
        if (temp[start][v])
        {
            if (edge <= 1 || !isBridge(start, v))
            {
                cout << start << "--" << v << " ";
                temp[start][v] = temp[v][start] = 0;
                edge--;
                fleury(v);
            }
        }
    }
}

int main()
{
    for (int i = 0; i < MAX; i++)
        for (int j = 0; j < MAX; j++)
            temp[i][j] = graph[i][j];
    fleury(start_vertex());
}