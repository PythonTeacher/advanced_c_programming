#include <stdio.h>

int main()
{
	int i, j, num;

	printf("������ �Է��ϼ��� : ");
	scanf("%d", &num);

	// ��� �ﰢ�� ���
	for(i=1; i<=num; i++)
    {
        for(j=1; j<=i; j++)
            printf("*");
        printf("\n");
    }

    // �ϴ� �ﰢ�� ���
    for(i=1; i<=num; i++)
    {
        // Space ���
        for(j=1; j<=num; j++)
            printf(" ");
        // �ﰢ�� ���
        for(j=1; j<i; j++)
            printf(" ");
        for(j=1; j<=num-i+1; j++)
            printf("*");
        printf("\n");
    }

	return 0;
}
