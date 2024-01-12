#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>

#define SIZE    3
#define HANDLE  GetStdHandle(STD_OUTPUT_HANDLE)
#define RED     SetConsoleTextAttribute(HANDLE, \
                                          BACKGROUND_INTENSITY | FOREGROUND_INTENSITY \
                                        | BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE \
                                        | FOREGROUND_RED );
#define BLACK   SetConsoleTextAttribute(HANDLE, \
                                          BACKGROUND_INTENSITY \
                                        | BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE );

int bingo[SIZE][SIZE];
int check[SIZE][SIZE];

void makeBoard();
void printBoard();
void inputNumber();
int checkBingo(int);

int main()
{
    int totLines, num, result;

    printf("����, ����, �밢�� �� �� �ϼ� �� �����ұ��? ");
    scanf("%d", &totLines);

    puts("\n###### ���� ���� ����!! ######\n");

    makeBoard();       // ������ �����

    while(1)
    {
        printBoard();

        inputNumber();

        if(checkBingo(totLines))
        {
            printBoard();
            printf("\n����!!!!\n");
            printf("���� ������ �����մϴ�\n");
            break;
        }
    }
}

void makeBoard()
{
    int i, j, num;
    int flag[SIZE*SIZE]={0};

    srand(time(NULL));

    for(i=0; i<SIZE; i++)
    {
        for(j=0; j<SIZE; j++)
        {
            do
            {
                num = rand() % (SIZE * SIZE) + 1;
            }while(flag[num-1] != 0);
            flag[num-1] = 1;
            bingo[i][j] = num;
        }
    }
}

void printBoard()
{
    int i, j;

    puts("");
    for(i=0; i<SIZE; i++)
    {
        for(j=0; j<SIZE; j++)
        {
            if(check[i][j] == 1) RED
            else BLACK
            printf("%2d   ", bingo[i][j]);
        }
        printf("\n");
    }
    BLACK
}

void inputNumber()
{
    int num, i, j;

    do
    {
        printf("1~%d ������ ���ڸ� �Է��ϼ��� (����:0)=> ", SIZE*SIZE);
        scanf("%d", &num);
        if(num == 0)
        {
            printf("���α׷��� �����մϴ�\n");
            exit(0);
        }
    } while(num < 1 || num > SIZE * SIZE);

    for(i=0; i<SIZE; i++)
    {
        for(j=0; j<SIZE; j++)
        {
            if(bingo[i][j] == num)
            {
                check[i][j] = 1;
                return;
            }
        }
    }
}

int checkBingo(int totLines)
{
    int i, j, flag;
    int lineCnt = 0;

    // ���μ� üũ
    for(i=0; i<SIZE; i++)
    {
        flag = 1;
        for(j=0; j<SIZE; j++)
        {
            if(check[i][j] == 0)
            {
                flag = 0;
                break;
            }
        }
        if(flag) {
            lineCnt++;
            printf("# ���μ� ���� => �� %d��\n", lineCnt);
        }
    }

    // ���μ� üũ
    for(i=0; i<SIZE; i++)
    {
        flag = 1;
        for(j=0; j<SIZE; j++)
        {
            if(check[j][i] == 0)
            {
                flag = 0;
                break;
            }
        }
        if(flag)
        {
            lineCnt++;
            printf("# ���μ� ���� => �� %d��\n", lineCnt);
        }
    }

    // �������� �밢�� üũ
    flag = 1;
    for(i=0; i<SIZE; i++)
    {
        if(check[i][i] == 0)
        {
            flag = 0;
            break;
        }
    }
    if(flag)
    {
        lineCnt++;
        printf("# �������� �밢�� ���� => �� %d��\n", lineCnt);
    }

    // �ö󰡴� �밢�� üũ
    flag = 1;
    for(i=0; i<SIZE; i++)
    {
        for(j=0; j<SIZE; j++)
        {
            if((i+j == SIZE-1) && check[i][j] == 0)
            {
                flag = 0;
                break;
            }
        }
        if(flag == 0) break;
    }
    if(flag)
    {
        lineCnt++;
        printf("# �ö󰡴� �밢�� ���� => �� %d��\n", lineCnt);
    }

    if(lineCnt == totLines)
        return 1;
    else
        return 0;
}
