#include <stdio.h>

int main()
{
    int kor, eng, mat, tot;

    printf("�� ���� ���� : ");
    scanf("%d %d %d", &kor, &eng, &mat);

    tot = kor + eng + mat;

    printf("���� : %d��\n", tot);
    printf("��� : %.1lf��", tot / 3.0);

    return 0;
}
