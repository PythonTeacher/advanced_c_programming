#include <stdio.h>

int isLeap(int year);

int main()
{
    int days[12] = {31,28,31,30,31,30,31,31,30,31,30,31};
    int year, month, firstday;
    int i;

    printf("�⵵�� �� �Է� : ");
    scanf("%d%d", &year, &month);


    printf("1���� ���� �Է�(��:0, ��:1, ȭ:2, ��:3, ��:4, ��:5, ��:6) : ");
    scanf("%d", &firstday);

    printf("\n��\t��\tȭ\t��\t��\t��\t��\n");

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
