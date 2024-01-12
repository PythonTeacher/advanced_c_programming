#include <stdio.h>

int main()
{
    int no, age;
    double batting;

    printf("등번호 : ");
    scanf("%d", &no);

    printf("타율 : ");
    scanf("%lf", &batting);

    printf("나이 : ");
    scanf("%d", &age);

    printf("%d번-마동탁-유격수\n", no);
    printf("타율은 %.2lf이고, 나이는 %d살임\n", batting, age);

    return 0;
}
