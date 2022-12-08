#include <bits/stdc++.h>
using namespace std;

#define MAX 5

void printSolution(int path[]);

bool isSafe(int v, bool graph[MAX][MAX], int path[], int pos)
{
    if (graph[path[pos - 1]][v] == 0)
        return false;

    for (int i = 0; i < pos; i++)
        if (path[i] == v)
            return false;

    return true;
}

bool ham(bool graph[MAX][MAX], int path[], int pos)
{
    if (pos == MAX)
    {
        if (graph[path[pos - 1]][path[0]] == 1)
            return true;
        else
            return false;
    }

    for (int v = 1; v < MAX; v++)
    {
        if (isSafe(v, graph, path, pos))
        {
            path[pos] = v;

            if (ham(graph, path, pos + 1) == true)
                return true;

            path[pos] = -1;
        }
    }

    return false;
}

bool hamCycle(bool graph[MAX][MAX])
{
    int *path = new int[MAX];
    for (int i = 0; i < MAX; i++)
        path[i] = -1;

    path[0] = 0;
    if (ham(graph, path, 1) == false)
    {
        cout << "\nSolution does not exist";
        return false;
    }

    printSolution(path);
    return true;
}

void printSolution(int path[])
{
    for (int i = 0; i < MAX; i++)
        cout << path[i] << " ";

    cout << path[0] << " ";
    cout << endl;
}

int main()
{
    bool graph[MAX][MAX] = {{0, 1, 1, 1, 1},
                            {1, 0, 1, 1, 0},
                            {1, 1, 0, 1, 0},
                            {1, 1, 1, 0, 1},
                            {1, 0, 0, 1, 0}};

    hamCycle(graph);

    return 0;
}