#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "header.h"

void init(Employees *p)
{
	p->head = NULL;
}

void display(Employees *p)
{
	if (p->head == NULL)
	{
		printf("Empty list");
	}
	else
	{
		node_t *present = p->head;
		while (present != NULL)
		{

			printf("SSN :%s\n", present->ssn);
			printf("Name :%s\n", present->name);
			printf("department name :%s\n", present->department->name);
			printf("department number :%d\n", present->department->number);
			printf("designation :%s\n", present->designation);
			printf("salary :%d\n", present->salary);
			printf("phone number :%d\n", present->phone_number);
			printf("age :%d\n", present->age);
			printf("\n");
			present = present->next;
		}
	}
}

node_t *createnode()
{
	node_t *temp = (node_t *)malloc(sizeof(node_t));
	Department *d = (Department *)malloc(sizeof(Department));
	temp->department = d;
	printf("SSN :");
	scanf("%s", temp->ssn);
	printf("Name :");
	scanf("%s", temp->name);
	printf("department name :");
	scanf("%s", temp->department->name);
	printf("department number :");
	scanf("%d", &temp->department->number);
	printf("designation :");
	scanf("%s", temp->designation);
	printf("salary :");
	scanf("%d", &temp->salary);
	printf("phone number :");
	scanf("%d", &temp->phone_number);
	printf("age :");
	scanf("%d", &temp->age);
	temp->next = NULL;
	temp->prev = NULL;
	printf("\n");

	return temp;
}

void insert(Employees *p)
{
	node_t *temp = createnode();
	if (p->head == NULL)
	{
		p->head = temp;
	}

	else
	{
		temp->next = p->head;
		p->head->prev = temp;
		p->head = temp;
	}
}

void delete_58(Employees *p)
{
	if (p->head == NULL)
	{
		printf("Empty!");
	}
	else
	{
		int state = 1;
		while (state == 1)
		{
			if (p->head == NULL)
			{
				state = 0;
			}
			else
			{
				node_t *present = p->head;
				node_t *prev = NULL;
				if (present->next == NULL && (present->age > 58))
				{
					free(present);
					p->head = NULL;
				}
				else
				{
					while (present != NULL && ((present->age) < 58))
					{
						prev = present;
						present = present->next;
					}
					if (present == NULL)
					{
						state = 0;
					}
					else if (prev == NULL)
					{
						p->head = present->next;
						p->head->prev = NULL;
						free(present);
					}
					else
					{
						prev->next = present->next;
						if (present->next != NULL)
							present->next->prev = prev;
						free(present);
					}
				}
			}
		}
	}
}
