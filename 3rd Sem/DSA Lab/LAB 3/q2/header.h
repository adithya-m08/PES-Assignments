typedef struct Department
{
	char name[20];
	int number;
} Department;

typedef struct Node
{
	char ssn[20];
	char name[20];
	Department *department;
	char designation[20];
	int salary;
	int phone_number;
	int age;
	struct Node *next, *prev;

} node_t;

typedef struct Employees
{
	node_t *head;

} Employees;

void init(Employees *p);
void insert(Employees *p);
void display(Employees *p);
void delete_58(Employees *p);
