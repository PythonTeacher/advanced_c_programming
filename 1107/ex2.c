#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *makeString(char *src);
void checkNULL(char **p);

// ���� ���� ������ �λ縻�� �����ϴ� ������ �迭�� �����ϱ�
int main()
{
    // ������ ������ �Է¹޾� ������ �迭�� �����Ҵ� �ϱ�
    int i, num;
    char temp[100];

    printf("���� ���� �Է� => ");
    scanf("%d", &num);
    getchar();

    char **nation = (char **)malloc(num * sizeof(char *));
    checkNULL(nation);

    char **greeting = (char **)malloc(num * sizeof(char *));
    checkNULL(greeting);

    for(i=0; i<num; i++)
    {
        printf("\n[%d]��° ���� �Է� => ", i+1);
        gets(temp);
        nation[i] = makeString(temp);

        printf("[%s] �λ縻 �Է� => ", nation[i]);
        gets(temp);
        greeting[i] = makeString(temp);
    }

    puts("");
    puts("<< ���� �λ縻 ��� >>");
    for(i=0; i<num; i++)
    {
        printf("[%s] %s\n", nation[i], greeting[i]);
    }

    // �޸� ����
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
