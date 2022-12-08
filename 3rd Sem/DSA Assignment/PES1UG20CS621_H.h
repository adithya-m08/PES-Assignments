typedef struct node
{
    int x;
    int y;
    int visit;
    struct node *right;
    struct node *down;
}node;

typedef struct ll
{
    int x;
    node *head;
    struct ll *next;
}ll;

void init(ll **p);
void insert(ll **p,int x,int y);
void path(ll **p,int start_x,int start_y,int goal_x,int goal_y);