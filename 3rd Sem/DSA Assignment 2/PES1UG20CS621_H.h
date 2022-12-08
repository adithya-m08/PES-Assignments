#define MAX 100

typedef struct node
{
    int info, x, y;
    struct node *next;
} node_t;

typedef struct queue
{
    int arr[MAX];
} queue;

typedef struct coordinate
{
    int x, y;
} coordinate;

typedef struct vector
{
    int i;
    int prev;
} vector;

int label_id(int arr[][10], int label[][10]);
void create_graph(node_t *a[], int arr[][10], int label[][10], int id);
int dfs(int src, int dest, node_t *arr[], int path1[]);
int path_lenght();
coordinate co_ordinate(int arr[][10], int k);
int indexof(int i, vector path[]);
void bfs(int src, int dest, node_t *arr[], int label[][10]);