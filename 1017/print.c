#include <stdio.h>
#include <string.h>

void printStr1(char *p);
void printStr2(char *p);

int main()
{
    char str[100];
    gets(str);

    printStr1(str);
    printStr2(str);

    return 0;
}

void printStr1(char *p)
{
    int i, j;
    int size = strlen(p);

    for(i=0; i<size; i++)
    {
        printf("%s", p+i);
        for(j=0; j<i*2; j++)
            printf(" ");
        printf("%s\n", p+i);
    }
}

void printStr2(char *p)
{
    int i, j;
    int size = strlen(p);

    for(i=size-1; i>=0; i--)
    {
        printf("%s", p+i);
        for(j=0; j<i*2; j++)
            printf(" ");
        printf("%s\n", p+i);
    }
}
