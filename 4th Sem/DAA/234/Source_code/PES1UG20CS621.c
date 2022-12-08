#include "header.h"
#include <limits.h>

// ANY STATIC FUNCTIONS ARE UP HERE

static void init(int n, int v[n])
{
    for (int i = 0; i < n; i++)
        v[i] = 0;
}

static void swap(airport_t *a, airport_t *b)
{
    airport_t t = *a;
    *a = *b;
    *b = t;
}

static int length(const char c[])
{
    int i = 0;
    for (i = 0;; i++)
    {
        if (c[i] == '\0')
            return i;
    }
}

static int check_path(int s, int d, int n, int v[n], const connection_t connections[n][n])
{
    v[s] = 1;
    for (int i = 0; i < n; i++)
    {
        if ((connections[s][i].distance != INT_MAX && connections[s][i].distance != 0) && !v[i])
        {
            if ((i == d) || check_path(i, d, n, v, connections))
                return 1;
        }
    }
    return 0;
}

static int path(int s, int d, int n, int v[n], int *length, const connection_t connections[n][n])
{
    v[s] = 1;
    for (int i = 0; i < n; i++)
    {
        if ((connections[s][i].distance != INT_MAX) && !v[i])
        {
            ++*length;
            if ((i == d) || path(i, d, n, v, length, connections))
            {
                return 1;
            }
        }
    }
    --*length;
    return 0;
}

static int cycle(int s, int d, int n, int v[n], const connection_t connections[n][n])
{
    v[s] = 1;
    v[d] = 0;
    for (int i = 0; i < n; i++)
    {
        if ((connections[s][i].distance != INT_MAX && connections[s][i].distance != 0) && !v[i])
        {
            if ((i == d) || cycle(i, d, n, v, connections))
                return 1;
        }
    }
    return 0;
}

static void heapify(int n, int (*predicate_func)(const airport_t *, const airport_t *), airport_t airport_list[n], int i)
{
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;
    if (l < n && predicate_func(&airport_list[largest], &airport_list[l]))
        largest = l;
    if (r < n && predicate_func(&airport_list[largest], &airport_list[r]))
        largest = r;
    if (largest != i)
    {
        swap(&airport_list[i], &airport_list[largest]);
        heapify(n, predicate_func, airport_list, largest);
    }
}

static void heapsort(int n, int (*predicate_func)(const airport_t *, const airport_t *), airport_t airport_list[n])
{
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(n, predicate_func, airport_list, i);
    for (int i = n - 1; i >= 0; i--)
    {
        swap(&airport_list[0], &airport_list[i]);
        heapify(i, predicate_func, airport_list, 0);
    }
}

static void shift_table(const char p[], int table[])
{
    int i, j, m;
    m = length(p);
    for (i = 0; i < 150; i++)
        table[i] = m;
    for (j = 0; j < m - 1; j++)
        table[p[j]] = m - j;
}

static int cycle_path(int s, int d, int n, int v[n], int *tim, int *length, int trip_order[n - 1], const connection_t connections[n][n])
{
    v[s] = 1;
    v[d] = 0;
    for (int i = 0; i < n; i++)
    {
        if ((connections[s][i].distance != INT_MAX) && (connections[s][i].distance != 0) && !v[i])
        {
            trip_order[(*length)++] = i;
            *tim = *tim + connections[s][i].distance;
            if ((i == d) || cycle_path(i, d, n, v, tim, length, trip_order, connections))
                return 1;
        }
    }
    (*length)--;
    return 0;
}

static void create_mst(int V, int parent[], const connection_t graph[V][V], pair_t edges[V - 1])
{
    for (int i = 1; i < V; i++)
    {
        edges[i - 1].first = parent[i];
        edges[i - 1].second = i;
    }
}

static int min_time(int n, pair_t edges[], const connection_t graph[n][n], int parent[])
{
    int res = 0;
    for (int i = 0; i < n - 1; i++)
        res = res + graph[edges[i].first][edges[i].second].time;
    return res;
}

static int min_key(int n, int key[], int mst[])
{
    int min = INT_MAX, min_index;

    for (int v = 0; v < n; v++)
        if (mst[v] == 0 && key[v] < min)
            min = key[v], min_index = v;

    return min_index;
}

// YOUR SOLUTIONS BELOW

int q1(int n, const connection_t connections[n][n])
{
    int v[n];
    int t;
    init(n, v);
    for (int j = 0; j < n; j++)
    {
        for (int k = 0; k < n; k++)
        {
            if (j != k)
            {
                t = check_path(j, k, n, v, connections);
                if (t == 0)
                    return 0;
                init(n, v);
            }
        }
    }
    return t;
}

int q2(const airport_t *src, const airport_t *dest, int n, int k, const connection_t connections[n][n])
{
    int v[n];
    init(n, v);
    int l = 0;
    path(src->num_id, dest->num_id, n, v, &l, connections);
    if ((l == 0) || (l > k))
        return 0;
    return 1;
}

int q3(const airport_t *src, int n, const connection_t connections[n][n])
{
    int v[n];
    init(n, v);
    int res = cycle(src->num_id, src->num_id, n, v, connections);
    return res;
}

void q4(int n, int (*predicate_func)(const airport_t *, const airport_t *), airport_t airport_list[n])
{
    heapsort(n, predicate_func, airport_list);
}

pair_t q5(int n, airport_t airports[n])
{
    pair_t ans = {-1, -1};
    int match = 0;
    int flag = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = n - 1; j > i; j--)
        {
            for (int k = 0; k < length(airports[j].airport_name); k++)
            {
                if (airports[i].airport_name[k] == airports[j].airport_name[k])
                    flag++;
            }
            if (flag > match)
            {
                match = flag;
                ans.first = i;
                ans.second = j;
            }
            flag = 0;
        }
    }
    return ans;
}

int q6(int n, int amount, const int entry_fee[n])
{
    for (int i = 1; i <= n; i++)
    {
        if (entry_fee[n - i] <= amount)
            return (n + 1 - i);
    }
    return 0;
}

void q7(int n, const char *pat, int contains[n], const airport_t airports[n])
{
    int table[150];
    init(150, table);
    init(n, contains);
    int len = length(pat);
    shift_table(pat, table);
    for (int i = 0; i < n; i++)
    {
        int m = len - 1;
        while (m < n)
        {
            int k = 0;
            while ((contains[i] == 0) && (k <= m) && (*(pat + len - 1 - k) == airports[i].airport_name[m - k]))
                k++;
            if (k == len)
                contains[i] = 1;
            else
                m += table[airports[i].airport_name[m]];
        }
    }
}

int q8(int n, int trip_order[n - 1], const connection_t connections[n][n])
{
    int v[n], t_order[n - 1], dummy, len = 0, k, m = 0, min = INT_MAX, time = 0;
    int x = n - 1;
    for (int z = 0; z < x; z++)
        t_order[z] = -1;
    init(n, v);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            k = 0;
            m = 0;
            init(n, v);
            v[i] = 1;
            if (i != j)
            {
                dummy = cycle_path(j, j, n, v, &time, &len, t_order, connections);
                if (dummy == 1)
                    v[j] = 1;
                while ((k < n) && (m == 0))
                {
                    if (v[k] == 0)
                        m = 1;
                    k++;
                }
                if (m == 0 && min > time)
                {
                    min = time;
                    for (int z = 0; z < x; z++)
                        trip_order[z] = t_order[z];
                }
                time = 0;
                len = 0;
            }
        }
    }
    if (min == INT_MAX)
        return -1;
    return min;
}

int q9(int n, pair_t edges[n - 1], const connection_t connections[n][n])
{
    int parent[n];
    int key[n];
    int mst[n];

    for (int i = 1; i < n; i++)
        key[i] = INT_MAX, mst[i] = 0;

    key[0] = 0;
    parent[0] = -1;
    for (int count = 0; count < n - 1; count++)
    {

        int u = min_key(n, key, mst);
        mst[u] = 1;
        for (int v = 0; v < n; v++)
            if (connections[u][v].time && mst[v] == 0 && connections[u][v].time < key[v])
                parent[v] = u, key[v] = connections[u][v].time;
    }
    create_mst(n, parent, connections, edges);
    return min_time(n, edges, connections, parent);
}

void q10(int n, int k, const airport_t *src, const connection_t connections[n][n], const int destinations[k], int costs[k])
{
    int route[n][n], i, j, r;
    int s = src->num_id;
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            route[i][j] = connections[i][j].time;

    for (r = 0; r < n; r++)
    {
        for (j = 0; j < n; j++)
        {
            if (route[s][r] != INT_MAX && route[r][destinations[j]] != INT_MAX)
            {
                if (route[s][r] + route[r][destinations[j]] < route[s][destinations[j]])
                    route[s][destinations[j]] = route[s][r] + route[r][destinations[j]];
            }
        }
    }
    for (int l = 0; l < k; l++)
        costs[l] = route[s][destinations[l]];
}

// END