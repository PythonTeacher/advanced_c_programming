#include <stdio.h>

int main()
{
	/* �� ��ȣ, �� ��ȣ, �ִ� ��� ��ġ */
	int row, col, limit;

	printf("���ڸ� �Է����ּ��� : ");
	scanf("%d", &limit);

	/* ����� �ﰢ�� ��� */
	for(row = 1; row <= limit; row++)
	{
		for(col = limit - row; col > 0; col--)
			printf(" ");
		for(col = 1; col < row*2; col++)
			printf("*");
		printf("\n");
	}
	/* �ϴ��� ���ﰢ�� ��� */
	for(row = limit - 1; row > 0; row--)
	{
		for(col = limit - row; col > 0; col--)
			printf(" ");
		for(col = 1; col < row*2; col++)
			printf("*");
		printf("\n");
	}

	return 0;
}
