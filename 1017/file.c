#include <stdio.h>

int main()
{
    char *path = "c:/a/b.txt";
    char str[255] = {0};
    getcwd(str, 255);
    printf("current dir : %s\n", str);

    int i, j;
    int len = strlen(path); // 10

    for(i=len-1; i>=0; i--)
    {
        if(path[i] == '/')
            break;
    }

    printf("File Name : %s\n", path+i+1);

    printf("Directory Name : ");
    for(j=0; j<i; j++)
    {
        putchar(path[j]);
    }

    return 0;
}
