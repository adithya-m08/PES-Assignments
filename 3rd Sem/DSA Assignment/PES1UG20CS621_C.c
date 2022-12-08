#include<stdio.h>
#include<stdlib.h>
#include"header.h"

int main()
{
    ll *p;
    init(&p);

    FILE *fp = fopen("input.txt","r");
    int start_x,start_y,goal_x,goal_y;

    fscanf(fp,"%d",&start_x);
    fscanf(fp,"%d",&start_y);
    fscanf(fp,"%d",&goal_x);
    fscanf(fp,"%d",&goal_y);

    char line[1000];
    int x = -1;

    while(fgets(line,1000,fp))
    {
        int y = 0;
        int i = 0;
        while(line[i]!='\0')
        {
            if(line[i] == '0')
                insert(&p,x,y);
            if(line[i] == ' ')
                y++;
            i++;
        }
        x++;
    }
    path(&p,start_x,start_y,goal_x,goal_y);
    fclose(fp);
    return 0;
}