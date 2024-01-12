/*-------- array3\ex8.c ---------*/

#include <stdio.h>

#define ROW 5
#define COL 5

int seats[ROW][COL];

void loadSeat();
void printMenu();
void reserveSeat(int row, int col);
void cancelSeat(int row, int col);
void printAllSeats();
void searchSeat(int row, int col);
void saveSeat();

int main()
{
    int i, j, menu;
    int rowSeat, colSeat;

    loadSeat();

    freopen("CON", "r", stdin);

    while(1)
    {
        printMenu();
        scanf("%d", &menu);
        if(menu == 9) break;

        if(menu == 1 || menu == 2 || menu == 4)
        {
            do
            {
                printf("좌석의 행을 입력하세요 (0~%d) => ", ROW-1);
                scanf("%d", &rowSeat);
            }while(rowSeat < 0 || rowSeat >= ROW);

            do
            {
                printf("좌석의 열을 입력하세요 (0~%d) => ", COL-1);
                scanf("%d", &colSeat);
            }while(colSeat < 0 || colSeat >= COL);
        }

        switch(menu)
        {
        case 1:
            reserveSeat(rowSeat, colSeat);  break;
        case 2:
            cancelSeat(rowSeat, colSeat);   break;
        case 3:
            printAllSeats();   break;
        case 4:
            searchSeat(rowSeat, colSeat);   break;
        default:
            printf("없는 메뉴입니다\n");
        }
    }

    saveSeat();

    return 0;
}

void loadSeat()
{
    FILE *fp = freopen("seat.txt", "r", stdin);
    int i, j;

    /*
    1 0 0 0 0
    0 1 0 0 1
    0 0 0 0 0
    0 0 1 0 0
    0 1 0 1 0
    */
    if(fp != NULL)
    {
        for(i=0; i<ROW; i++)
        {
            for(j=0; j<COL; j++)
            {
                scanf("%d ", &seats[i][j]);
            }
        }
    }
    fclose(fp);
}

void saveSeat()
{
    FILE *fp = freopen("seat.txt", "w", stdout);
    int i, j;

    if(fp != NULL)
    {
        for(i=0; i<ROW; i++)
        {
            for(j=0; j<COL; j++)
            {
                printf("%d ", seats[i][j]);
            }
            puts("");
        }
    }
    fclose(fp);
}

void printMenu()
{
    printf("------ << 메뉴 >> ------\n");
    printf("1. 좌석 예약\n");
    printf("2. 좌석 취소\n");
    printf("3. 좌석 조회\n");
    printf("4. 좌석 검색\n");
    printf("9. 종료\n");
    printf("-------------------------\n");
    printf("메뉴 입력 => ");
}

void reserveSeat(int row, int col)
{
    // 이미 예약된 자리이면 "이미 예약된 자리입니다" 출력
    // 예약 완료 후 "예약되었습니다" 출력
    if(seats[row][col] == 1)
    {
        printf("이미 예약된 자리입니다\n");
        return;
    }

    seats[row][col] = 1;
    printf("예약되었습니다\n");
}

void cancelSeat(int row, int col)
{
    // 예약된 자리가 아니면 "예약되지 않은 자리입니다" 출력
    // 취소 완료 후 "취소되었습니다" 출력
    if(seats[row][col] == 0)
    {
        printf("예약되지 않은 자리입니다\n");
        return;
    }

    seats[row][col] = 0;
    printf("취소되었습니다\n");
}

void printAllSeats()
{
    int i, j;
    for(i=0; i<ROW; i++)
    {
        for(j=0; j<COL; j++)
        {
            printf("%3d", seats[i][j]);
        }
        printf("\n");
    }
}

void searchSeat(int row, int col)
{
    char yn;

    if(seats[row][col] == 1)
        printf("예약된 좌석입니다\n");
    else
    {
        printf("예약 안된 좌석입니다\n");
        printf("\n예약하시겠습니까?");
        //fflush(stdin);
        while(getchar() != '\n');
        if((yn = getchar()) == 'y' || yn == 'Y')
            reserveSeat(row, col);
    }

}
