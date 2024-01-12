#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *makeString(char *src);

// 세계 여러 나라의 인사말을 저장하는 포인터 배열을 생성하기
int main()
{
    // 5개국의 인사말을 담는 포인터 배열 선언
    char *nation[5];
    char *greeting[5];
    int i;
    char temp[100];

    for(i=0; i<5; i++)
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
    for(i=0; i<5; i++)
    {
        printf("[%s] %s\n", nation[i], greeting[i]);
        free(nation[i]);
        free(greeting[i]);
    }

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
