#include <stdio.h>

int main()
{
    int no, age;
    double batting;

    printf("���ȣ : ");
    scanf("%d", &no);

    printf("Ÿ�� : ");
    scanf("%lf", &batting);

    printf("���� : ");
    scanf("%d", &age);

    printf("%d��-����Ź-���ݼ�\n", no);
    printf("Ÿ���� %.2lf�̰�, ���̴� %d����\n", batting, age);

    return 0;
}
