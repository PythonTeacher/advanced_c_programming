#include <stdio.h>

int isLeap(int year);

int main()
{
    int days[12] = {31,28,31,30,31,30,31,31,30,31,30,31};
    int year, month, firstday;
    int i;

    printf("년도와 달 입력 : ");
    scanf("%d%d", &year, &month);


    printf("1일의 요일 입력(일:0, 월:1, 화:2, 수:3, 목:4, 금:5, 토:6) : ");
    scanf("%d", &firstday);

    printf("\n일\t월\t화\t수\t목\t금\t토\n");

    if(isLeap(year)) days[1]++;

    for(i=0; i<firstday; i++)
        printf("\t");

    for(i=1; i<=days[month-1]; i++)
    {
        printf("%2d\t", i);

        if((firstday + i) % 7 == 0)
            printf("\n");
    }
	return 0;
}

int isLeap(int year)
{
    if(year % 400 == 0 || (year % 4 == 0 && year % 100 != 0))
        return 1;
    else
        return 0;
}
