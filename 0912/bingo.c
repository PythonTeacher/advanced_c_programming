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

    printf("가로, 세로, 대각선 몇 개 완성 시 종료할까요? ");
    scanf("%d", &totLines);

    puts("\n###### 빙고 게임 시작!! ######\n");

    makeBoard();       // 게임판 만들기

    while(1)
    {
        printBoard();

        inputNumber();

        if(checkBingo(totLines))
        {
            printBoard();
            printf("\n빙고!!!!\n");
            printf("빙고 게임을 종료합니다\n");
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
        printf("1~%d 사이의 숫자를 입력하세요 (종료:0)=> ", SIZE*SIZE);
        scanf("%d", &num);
        if(num == 0)
        {
            printf("프로그램을 종료합니다\n");
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

    // 가로선 체크
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
            printf("# 가로선 빙고 => 총 %d개\n", lineCnt);
        }
    }

    // 세로선 체크
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
            printf("# 세로선 빙고 => 총 %d개\n", lineCnt);
        }
    }

    // 내려가는 대각선 체크
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
        printf("# 내려가는 대각선 빙고 => 총 %d개\n", lineCnt);
    }

    // 올라가는 대각선 체크
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
        printf("# 올라가는 대각선 빙고 => 총 %d개\n", lineCnt);
    }

    if(lineCnt == totLines)
        return 1;
    else
        return 0;
}
