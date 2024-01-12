#include <stdio.h>

int main()
{
    int num, cnt=0, sum=0;

    printf("정수를 입력하세요 : ");
    scanf("%d", &num);

    while(num != 0)
    {
        sum = sum + num % 10;   // 5 + 4 + 3
        num = num / 10; // 34 -> 3 -> 0
        cnt++;  // 1 -> 2 -> 3
    }

    printf("정수의 자리수 : %d\n", cnt);
    printf("각 자리의 합 : %d\n", sum);

	return 0;
}
