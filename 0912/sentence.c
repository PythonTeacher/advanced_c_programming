#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#define CNT 4

int main()
{
    char who[CNT][10]={"�����", "������", "������", "�ξƴ�"};
    char when[CNT][20]={"�����ֿ�", "������", "����", "���� ��ħ��"};
    char where[CNT][20]={"�Ĵ翡��", "PC�濡��", "����������", "���ǿ���"};
    char what[CNT][50]={"���� �Ծ���.", "������ �ߴ�.", "���θ� �ߴ�.", "������ �ߴ�."};
    char sentence[CNT][100];

    int i, j, num;
    srand(time(NULL));

    for(i=0; i<CNT; i++)
    {
        strcpy(sentence[i], who[i]);
        for(j=0; j<3; j++)
        {
            num = rand() % 4;   // 0~3
            strcat(sentence[i], " ");
            if(j == 0)
                strcat(sentence[i], when[num]);
            else if(j == 1)
                strcat(sentence[i], where[num]);
            else
                strcat(sentence[i], what[num]);
        }

        printf("%d��° �ϼ��� ������? %s\n", i+1, sentence[i]);
    }

    return 0;
}
