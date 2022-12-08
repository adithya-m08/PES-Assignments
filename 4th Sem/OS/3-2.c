#include <stdio.h>
#include <sys/stat.h>
#include <time.h>
#include <stdlib.h>
#include <unistd.h>
#include <dirent.h>

int main()
{
    DIR *d;
    struct dirent *dir;
    struct stat st;
    struct tm date;

    char dirname[200];
    printf("Enter directory or . for current ");
    scanf("%s", dirname);
    d = opendir(dirname);

    if (!d)
    {
        printf("Error opening directory!");
        exit(0);
    }

    int dd, mm, yyyy;
    printf("dd ");
    scanf("%d", &dd);
    printf("mm ");
    scanf("%d", &mm);
    printf("yyyy ");
    scanf("%d", &yyyy);

    while ((dir = readdir(d)))
    {
        if (stat(dir->d_name, &st) == 0)
        {
            date = *gmtime(&st.st_ctime);
            int d = date.tm_mday;
            int m = date.tm_mon;
            int y = date.tm_year + 1900;
            if ((yyyy <= y) && (mm <= m) && (dd < d))
                printf("%s\n", dir->d_name);
            else if ((yyyy <= y) && (mm < m))
                printf("%s\n", dir->d_name);
            else if (yyyy < y)
                printf("%s\n", dir->d_name);
        }
    }
    closedir(d);

    return 0;
}