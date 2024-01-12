#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *makeString(char *src);

int main()
{
    int groupNum;
    char temp[100];
    int i, j;

    printf("아이돌 그룹 갯수 입력 => ");
    scanf("%d", &groupNum);
    getchar();

    // 아이돌 그룹멤버 포인터 배열
    char ***member = (char ***)malloc(groupNum * sizeof(char **));

    // 아이돌 그룹명 포인터 배열
    char **name = (char **)malloc(groupNum * sizeof(char *));

    int *number = (int *)malloc(groupNum * sizeof(int));

    if(member == NULL || name == NULL || number == NULL)
    {
        puts("Out of memory");
        exit(1);
    }

    for(i=0; i<groupNum; i++)
    {
        printf("[%d]번째 아이돌 그룹명 입력 => ", i+1);
        gets(temp);
        name[i] = makeString(temp);
    }

    for(i=0; i<groupNum; i++)
    {
        printf("\n[%s] 아이돌 그룹의 멤버수 입력 => ", name[i]);
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
            printf("[%d]번째 멤버명 => ", j+1);
            gets(temp);
            member[i][j] = makeString(temp);
        }
    }

    puts("\n<< 아이돌 그룹 출력 >>");

    for(i=0; i<groupNum; i++)
    {
        printf("[%s] 그룹 멤버 (%d명)\n", name[i], number[i]);
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
