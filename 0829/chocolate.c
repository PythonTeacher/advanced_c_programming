#include <stdio.h>

void printCake();
int countChocolate(int row, int col);

#define ROW     5
#define COL     5
#define RANGE   3

int cake[ROW][COL]=
{
    {1,1,1,1,1},
    {1,1,2,2,2},
    {1,5,1,2,1},
    {1,1,2,2,2},
    {1,1,1,1,1}
};

int main()
{
    int i, j, max=0;
    int max_row=0, max_col=0;
    int cnt;

    printCake();

    for(i=0; i<RANGE; i++)
    {
        for(j=0; j<RANGE; j++)
        {
            cnt = countChocolate(i, j);
            if(max < cnt)
            {
                max = cnt;
                max_row = i;
                max_col = j;
            }
        }
    }

    printf("\n���� ��/����ȣ ��� => %d�� %d��\n", max_row, max_col);
    printf("�ִ� ���ݸ� �� : %d��\n", max);

    return 0;
}

void printCake()
{
    int i, j;

    for(i=0; i<ROW; i++)
    {
        for(j=0; j<COL; j++)
        {
            printf("%2d ", cake[i][j]);
        }
        printf("\n");
    }
}

int countChocolate(int row, int col)
{
    int i, j, sum=0;

    for(i=row; i<row+RANGE; i++)
    {
        for(j=col; j<col+RANGE; j++)
        {
            sum += cake[i][j];
        }
    }

    return sum;
}
