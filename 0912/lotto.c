#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int input[6];
int lotto[7];       // 6개 + 보너스 1개

void inputLotto();
void generateLotto();
void printLotto();
int checkLotto();

#define LOTTO_CNT   45

int main(void)
{
    int rank;
    srand(time(NULL));

    inputLotto();       // 로또번호 입력

    generateLotto();    // 로또번호 생성

    printLotto();       // 로또번호 출력

    rank=checkLotto();       // 로또번호 체크

    if(rank >= 1 && rank <= 5)
        printf("\n축하합니다!! %d등에 당첨되셨습니다!!\n", rank);
    else
        printf("\n꽝!! 다음 기회에!!");

    return 0;
}

void inputLotto()
{
    int i;
    printf("로또 번호 6개를 입력하세요 (예: 1 14 22 38 40 42) : ");
    for(i=0; i<6; i++)
        scanf("%d", &input[i]);
}

void generateLotto()
{
    int i, num;
    int check[LOTTO_CNT]={0};
    for(i=0; i<7; i++) {  // 6개 + 보너스 1개
        do {
            num = rand() % LOTTO_CNT + 1; // 0~44 -> 1~45
        } while(check[num-1] != 0);
        check[num-1] = 1;
        lotto[i] = num;
    }
}

void printLotto()
{
    int i;
    printf("\n당첨 번호 6개와 보너스 번호 1개를 출력합니다 : ");
    for(i=0; i<7; i++)
    {
        if(i == 6) printf("| ");
        printf("%d ", lotto[i]);
    }
    printf("\n");
}

int checkLotto()
{
    int i, j;
    int count=0;

    // 당첨된 갯수에 따라 등수 출력
    // 1등 당첨번호 6개 번호 일치
    // 2등 당첨번호 5개 번호 일치+보너스 번호 일치
    // 3등 당첨번호 5개 번호 일치
    // 4등 당첨번호 4개 번호 일치
    // 5등 당첨번호 3개 번호 일치

    for(i=0; i<6; i++)
    {
        for(j=0; j<6; j++)
        {
            if(lotto[i] == input[j])
            {
                //printf("\n일치한 번호 : %d ", lotto[i]);
                count++;
                break;
            }
        }
    }

    printf("\n일치한 번호 갯수 : %d개\n", count);

    switch(count)
    {
        case 6: return 1;
        case 5:
            for(i=0; i<6; i++)
            {
                if(lotto[6] == input[i])
                {
                    printf("\n보너스 숫자 일치!!\n");
                    return 2;
                }
            }
            return 3;
        case 4: return 4;
        case 3: return 5;
        default: return 0;
    }
}
