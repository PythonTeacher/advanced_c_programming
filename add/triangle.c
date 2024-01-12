#include <stdio.h>

int main (void)
{
	int lineCtrl;	/* 줄 제어 */
	int numCtrl;	/* 숫자 제어 */
	int limit;	/* 최대 출력 위치 */

	/* 사용자에게 줄 번호를 입력 받는다. */
	printf("\nPlease enter a number between 1 and 9: ");
	scanf("%d", &limit);

	/* 몇 줄을 출력하는가를 제어하는 for문 */
	for (lineCtrl = 1; lineCtrl <= limit; lineCtrl++)
	{
	    /* 한 줄에 일련의 숫자를 출력한다. */
	    for (numCtrl = 1; numCtrl <= lineCtrl; numCtrl++)
	       printf("%1d", numCtrl);

	    printf("\n");
	}
	return 0;
}
