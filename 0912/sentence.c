#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#define CNT 4

int main()
{
    char who[CNT][10]={"유라는", "혜리는", "소진은", "민아는"};
    char when[CNT][20]={"지난주에", "그저께", "어제", "오늘 아침에"};
    char where[CNT][20]={"식당에서", "PC방에서", "도서관에서", "교실에서"};
    char what[CNT][50]={"밥을 먹었다.", "오락을 했다.", "공부를 했다.", "숙제를 했다."};
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

        printf("%d번째 완성된 문장은? %s\n", i+1, sentence[i]);
    }

    return 0;
}
