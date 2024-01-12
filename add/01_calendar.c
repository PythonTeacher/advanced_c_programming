#include <stdio.h>

int main()
{
    int days, firstday;
    int i;

    printf("최대 일수 입력 : ");
    scanf("%d", &days);

    printf("1일의 요일 입력 : ");
    scanf("%d", &firstday);

    printf("\n일\t월\t화\t수\t목\t금\t토\n");

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
