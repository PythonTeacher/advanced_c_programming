#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *makeString(char *src);

int main()
{
    int groupNum;
    char temp[100];
    int i, j;

    printf("���̵� �׷� ���� �Է� => ");
    scanf("%d", &groupNum);
    getchar();

    // ���̵� �׷��� ������ �迭
    char ***member = (char ***)malloc(groupNum * sizeof(char **));

    // ���̵� �׷�� ������ �迭
    char **name = (char **)malloc(groupNum * sizeof(char *));

    int *number = (int *)malloc(groupNum * sizeof(int));

    if(member == NULL || name == NULL || number == NULL)
    {
        puts("Out of memory");
        exit(1);
    }

    for(i=0; i<groupNum; i++)
    {
        printf("[%d]��° ���̵� �׷�� �Է� => ", i+1);
        gets(temp);
        name[i] = makeString(temp);
    }

    for(i=0; i<groupNum; i++)
    {
        printf("\n[%s] ���̵� �׷��� ����� �Է� => ", name[i]);
        scanf("%d", &number[i]);
        getchar();

        member[i] = (char **)malloc(number[i] * sizeof(char *));
        if(member[i] == NULL)
        {
            puts("Out of memory!!");
            exit(1);
        }

        for(j=0; j<number[i]; j++)
        {
            printf("[%d]��° ����� => ", j+1);
            gets(temp);
            member[i][j] = makeString(temp);
        }
    }

    puts("\n<< ���̵� �׷� ��� >>");

    for(i=0; i<groupNum; i++)
    {
        printf("[%s] �׷� ��� (%d��)\n", name[i], number[i]);
        for(j=0; j<number[i]; j++)
        {
            printf("\t %s \n", member[i][j]);
        }
        puts("");
    }

    for(i=0; i<groupNum; i++)
    {
        for(j=0; j<number[i]; j++)
        {
            free(member[i][j]);
        }
        free(member[i]);
        free(name[i]);
    }

    free(member);
    free(name);
    free(number);

    return 0;
}

char *makeString(char *src)
{
    char *dest = (char *)malloc(strlen(src) + 1);
    if(dest == NULL)
    {
        puts("Out of memory!!");
        exit(1);
    }
    strcpy(dest, src);
    return dest;
}
