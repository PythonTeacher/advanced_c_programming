#include <stdio.h>

int main()
{
    int days, firstday;
    int i;

    printf("�ִ� �ϼ� �Է� : ");
    scanf("%d", &days);

    printf("1���� ���� �Է� : ");
    scanf("%d", &firstday);

    printf("\n��\t��\tȭ\t��\t��\t��\t��\n");

    for(i=0; i<firstday; i++)
        printf("\t");

    for(i=1; i<=days; i++)
    {
        printf("%d\t", i);
        if((firstday + i) % 7 == 0)
            printf("\n");
    }
	return 0;
}
