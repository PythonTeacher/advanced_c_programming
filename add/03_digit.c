#include <stdio.h>

int main()
{
    int num, cnt=0, sum=0;

    printf("������ �Է��ϼ��� : ");
    scanf("%d", &num);

    while(num != 0)
    {
        sum = sum + num % 10;   // 5 + 4 + 3
        num = num / 10; // 34 -> 3 -> 0
        cnt++;  // 1 -> 2 -> 3
    }

    printf("������ �ڸ��� : %d\n", cnt);
    printf("�� �ڸ��� �� : %d\n", sum);

	return 0;
}
