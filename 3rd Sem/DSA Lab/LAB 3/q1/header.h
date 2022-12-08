typedef struct Node{
    char name[20];
    int phone_number;
    char address[30];
    char area[20];
    struct Node *next,*prev;
}node_t;

typedef struct customerDetails
{
    node_t *head;
}customerDetails;

void init(customerDetails *p);
void insert(customerDetails *p);
void display(customerDetails *p);
