#include <stdio.h>

int main()
{
    int score[7];
    int i, max=0, min=10, before_sum=0, after_sum=0;
    double avg;

    printf("7���� ���� ������ �Է��ϼ���\n");

    for(i=0; i<7; i++)
    {
        printf("ä���� %d : ", i+1);
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

    printf("\n7�� ���� ������ �� = %d\n", before_sum);
    printf("�ְ��� = %d\n", max);
    printf("������ = %d\n", min);

    printf("\n�ְ����� �������� ������ ������ �� = %d\n", after_sum);
    printf("������ ��� ���� = %.1lf\n", avg);

    return 0;
}
