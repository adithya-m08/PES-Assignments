#include<stdio.h>
#include<stdlib.h>
#include"header.h"

int main()
{
        customerDetails c;
        init(&c);
        insert(&c);
        insert(&c);
        insert(&c);
        display(&c);
        return 0;
}
