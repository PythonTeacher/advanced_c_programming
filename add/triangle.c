#include <stdio.h>

int main (void)
{
	int lineCtrl;	/* �� ���� */
	int numCtrl;	/* ���� ���� */
	int limit;	/* �ִ� ��� ��ġ */

	/* ����ڿ��� �� ��ȣ�� �Է� �޴´�. */
	printf("\nPlease enter a number between 1 and 9: ");
	scanf("%d", &limit);

	/* �� ���� ����ϴ°��� �����ϴ� for�� */
	for (lineCtrl = 1; lineCtrl <= limit; lineCtrl++)
	{
	    /* �� �ٿ� �Ϸ��� ���ڸ� ����Ѵ�. */
	    for (numCtrl = 1; numCtrl <= lineCtrl; numCtrl++)
	       printf("%1d", numCtrl);

	    printf("\n");
	}
	return 0;
}
