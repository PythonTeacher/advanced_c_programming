#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *makeString(char *src);

// ���� ���� ������ �λ縻�� �����ϴ� ������ �迭�� �����ϱ�
int main()
{
    // 5������ �λ縻�� ��� ������ �迭 ����
    char *nation[5];
    char *greeting[5];
    int i;
    char temp[100];

    for(i=0; i<5; i++)
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
