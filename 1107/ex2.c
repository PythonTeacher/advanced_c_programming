#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *makeString(char *src);
void checkNULL(char **p);

// 세계 여러 나라의 인사말을 저장하는 포인터 배열을 생성하기
int main()
{
    // 나라의 갯수를 입력받아 포인터 배열을 동적할당 하기
    int i, num;
    char temp[100];

    printf("나라 갯수 입력 => ");
    scanf("%d", &num);
    getchar();

    char **nation = (char **)malloc(num * sizeof(char *));
    checkNULL(nation);

    char **greeting = (char **)malloc(num * sizeof(char *));
    checkNULL(greeting);

    for(i=0; i<num; i++)
    {
        printf("\n[%d]번째 나라 입력 => ", i+1);
        gets(temp);
        nation[i] = makeString(temp);

        printf("[%s] 인사말 입력 => ", nation[i]);
        gets(temp);
        greeting[i] = makeString(temp);
    }

    puts("");
    puts("<< 나라별 인사말 출력 >>");
    for(i=0; i<num; i++)
    {
        printf("[%s] %s\n", nation[i], greeting[i]);
    }

    // 메모리 해제
    for(i=0; i<num; i++)
    {
        free(nation[i]);
        free(greeting[i]);
    }

    free(nation);
    free(greeting);

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

void checkNULL(char **p)
{
    if(p == NULL)
    {
        puts("Out of memory");
        exit(1);
    }
}
