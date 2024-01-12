#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int input[6];
int lotto[7];       // 6�� + ���ʽ� 1��

void inputLotto();
void generateLotto();
void printLotto();
int checkLotto();

#define LOTTO_CNT   45

int main(void)
{
    int rank;
    srand(time(NULL));

    inputLotto();       // �ζǹ�ȣ �Է�

    generateLotto();    // �ζǹ�ȣ ����

    printLotto();       // �ζǹ�ȣ ���

    rank=checkLotto();       // �ζǹ�ȣ üũ

    if(rank >= 1 && rank <= 5)
        printf("\n�����մϴ�!! %d� ��÷�Ǽ̽��ϴ�!!\n", rank);
    else
        printf("\n��!! ���� ��ȸ��!!");

    return 0;
}

void inputLotto()
{
    int i;
    printf("�ζ� ��ȣ 6���� �Է��ϼ��� (��: 1 14 22 38 40 42) : ");
    for(i=0; i<6; i++)
        scanf("%d", &input[i]);
}

void generateLotto()
{
    int i, num;
    int check[LOTTO_CNT]={0};
    for(i=0; i<7; i++) {  // 6�� + ���ʽ� 1��
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
    printf("\n��÷ ��ȣ 6���� ���ʽ� ��ȣ 1���� ����մϴ� : ");
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

    // ��÷�� ������ ���� ��� ���
    // 1�� ��÷��ȣ 6�� ��ȣ ��ġ
    // 2�� ��÷��ȣ 5�� ��ȣ ��ġ+���ʽ� ��ȣ ��ġ
    // 3�� ��÷��ȣ 5�� ��ȣ ��ġ
    // 4�� ��÷��ȣ 4�� ��ȣ ��ġ
    // 5�� ��÷��ȣ 3�� ��ȣ ��ġ

    for(i=0; i<6; i++)
    {
        for(j=0; j<6; j++)
        {
            if(lotto[i] == input[j])
            {
                //printf("\n��ġ�� ��ȣ : %d ", lotto[i]);
                count++;
                break;
            }
        }
    }

    printf("\n��ġ�� ��ȣ ���� : %d��\n", count);

    switch(count)
    {
        case 6: return 1;
        case 5:
            for(i=0; i<6; i++)
            {
                if(lotto[6] == input[i])
                {
                    printf("\n���ʽ� ���� ��ġ!!\n");
                    return 2;
                }
            }
            return 3;
        case 4: return 4;
        case 3: return 5;
        default: return 0;
    }
}
