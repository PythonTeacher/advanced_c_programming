#include <stdio.h>

int main()
{
    int score[7];
    int i, max=0, min=10, before_sum=0, after_sum=0;
    double avg;

    printf("7명의 심판 점수를 입력하세요\n");

    for(i=0; i<7; i++)
    {
        printf("채점관 %d : ", i+1);
        scanf("%d", &score[i]);
    }

    for(i=0; i<7; i++)
    {
        before_sum += score[i];
        if(max < score[i])
            max = score[i];

        if(min > score[i])
            min = score[i];
    }

    after_sum = before_sum - max - min;
    avg = after_sum / (double)5;

    printf("\n7명 심판 점수의 합 = %d\n", before_sum);
    printf("최고점 = %d\n", max);
    printf("최하점 = %d\n", min);

    printf("\n최고점과 최하점을 제외한 점수의 합 = %d\n", after_sum);
    printf("선수의 평균 점수 = %.1lf\n", avg);

    return 0;
}
