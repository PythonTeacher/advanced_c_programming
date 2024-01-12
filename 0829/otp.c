#include <stdio.h>

#define ROW 4
#define COL 5

int otp[ROW][COL];

void makeOTPNumber();

int main()
{
    int i, random;
    int input, cnt=0;
    int row, col;
    int check[20]={0};

    srand(time(NULL));
    makeOTPNumber();

    for(i=1; i<=3; i++)
    {
        // �ߺ�üũ
        do
        {
            random = rand() % (ROW * COL) + 1;      // 0~19 -> 1~20;
        }while(check[random-1] == 1);

        check[random-1] = 1;
        printf("\n[%dȸ] %d�� OTP ��ȣ�� �Է��ϼ��� => ", i, random);
        scanf("%d", &input);

        row = (random-1) / COL;
        col = (random-1) % COL;

        //printf("row:%d, col:%d\n", row, col);

        if(otp[row][col] == input)
            cnt++;
    }

    if(cnt == 3) printf("OTP ī�� ��ȣ ��ġ!!\n");
    else printf("OTP ī�� ��ȣ�� Ʋ���ϴ�!!\n");

    return 0;
}

void makeOTPNumber()
{
    int i, j;

    for(i=0; i<ROW; i++)
    {
        for(j=0; j<COL; j++)
        {
            // 4�ڸ� OTP��ȣ �ߺ�üũ�� ������
            otp[i][j] = rand() % 9999 + 1; // 0~9998 -> 1~9999
            printf("[%2d] %4d ", COL*i+j+1, otp[i][j]);
        }
        printf("\n");
    }
}
