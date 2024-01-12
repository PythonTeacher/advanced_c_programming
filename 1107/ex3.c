#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *makeString(char *src);

int main()
{
    int student;    // �л� ��
    int subject;    // ���� ��
    int i, j;
    char temp[100];

    printf(">> �л� �� �Է� => ");
    scanf("%d", &student);

    printf(">> ���� �� �Է� => ");
    scanf("%d", &subject);
    getchar();

    // �л��� ��ŭ ������ �迭 ���� �Ҵ�
    int **score = (int **)malloc(student * sizeof(int *));
    if(score == NULL)
    {
        puts("Out of memory");
        exit(1);
    }

    // ����� ��ŭ ����� ���� �Ҵ�
    char **subjectName = (char **)malloc(subject * sizeof(char *));
    if(subjectName == NULL)
    {
        puts("Out of memory");
        exit(1);
    }

    puts(">> ����� �Է�");
    for(i=0; i<subject; i++)
    {
        printf("[%d] ��° ����� => ", i+1);
        gets(temp);
        subjectName[i] = makeString(temp);
    }
    puts("");

    for(i=0; i<student; i++)
    {
        // ����� ��ŭ ������ �迭 ���� �Ҵ� (�������� ����)
        score[i] = (int *)calloc(subject + 1, sizeof(int));
        if(score[i] == NULL)
        {
            puts("Out of memory!!!");
            exit(1);
        }
        for(j=0; j<subject; j++)
        {
            printf("[%d]�� �л��� [%s] ���� �Է� : ", i+1, subjectName[j]);
            scanf("%d", &score[i][j]);
            score[i][subject] += score[i][j];
        }
        puts("");
    }

    puts("----------------------------------------------");
    printf(" ��ȣ \t ");
    for(i=0; i<subject; i++)
    {
        printf("%s \t", subjectName[i]);
    }
    puts(" ���� \t ��� ");
    puts("----------------------------------------------");
    for(i=0; i<student; i++)
    {
        printf("   %d \t", i+1);
        for(j=0; j<subject+1; j++)
        {
            printf("%5d \t", score[i][j]);
        }
        printf("%.1f\n", score[i][j-1] / (double)subject);
    }

    // �޸� ����
    for(i=0; i<student; i++)
    {
        free(score[i]);
    }

    for(i=0; i<subject; i++)
    {
        free(subjectName[i]);
    }

    free(score);
    free(subjectName);

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
