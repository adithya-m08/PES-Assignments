#include <stdio.h>
#include <stdlib.h>
#include "header.h"

int main()
{
	Employees e;
	int n;

	init(&e);
	while (1)
	{
		printf("1. ADD  2. DELETE   3. DISPLAY  4.EXIT\n");
		scanf("%d", &n);

		switch (n)
		{
		case 1:
			insert(&e);
			break;
		case 2:
			delete_58(&e);
			break;
		case 3:
			display(&e);
			break;
		}
	}
}
