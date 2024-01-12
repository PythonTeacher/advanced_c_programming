#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *makeString(char *src);

int main()
{
    int student;    // 학생 수
    int subject;    // 과목 수
    int i, j;
    char temp[100];

    printf(">> 학생 수 입력 => ");
    scanf("%d", &student);

    printf(">> 과목 수 입력 => ");
    scanf("%d", &subject);
    getchar();

    // 학생수 만큼 포인터 배열 동적 할당
    int **score = (int **)malloc(student * sizeof(int *));
    if(score == NULL)
    {
        puts("Out of memory");
        exit(1);
    }

    // 과목수 만큼 과목명 동적 할당
    char **subjectName = (char **)malloc(subject * sizeof(char *));
    if(subjectName == NULL)
    {
        puts("Out of memory");
        exit(1);
    }

    puts(">> 과목명 입력");
    for(i=0; i<subject; i++)
    {
        printf("[%d] 번째 과목명 => ", i+1);
        gets(temp);
        subjectName[i] = makeString(temp);
    }
    puts("");

    for(i=0; i<student; i++)
    {
        // 과목수 만큼 정수형 배열 동적 할당 (총점까지 포함)
        score[i] = (int *)calloc(subject + 1, sizeof(int));
        if(score[i] == NULL)
        {
            puts("Out of memory!!!");
            exit(1);
        }
        for(j=0; j<subject; j++)
        {
            printf("[%d]번 학생의 [%s] 점수 입력 : ", i+1, subjectName[j]);
            scanf("%d", &score[i][j]);
            score[i][subject] += score[i][j];
        }
        puts("");
    }

    puts("----------------------------------------------");
    printf(" 번호 \t ");
    for(i=0; i<subject; i++)
    {
        printf("%s \t", subjectName[i]);
    }
    puts(" 총점 \t 평균 ");
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

    // 메모리 해제
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
