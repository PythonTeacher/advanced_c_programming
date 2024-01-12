#include <stdio.h>
#include <string.h>

int main()
{
    const char song[][100] = {"겨울비",
                              "봄여름가을겨울",
                              "봄날은 간다",
                              "가을이 오면",
                              "가을 우체국 앞에서",
                              "흐린 가을 하늘에 편지를 써"};

    const char season[4][10]={"봄", "여름", "가을", "겨울"};

    int i, j;
    int size = sizeof(song) / sizeof(song[0]);

    //printf("찾고자 하는 계절을 입력 => ");
    //gets(season);

    for(i=0; i<4; i++)
    {
        printf("<< %s이 들어간 노래 >>\n", season[i]);
        for(j=0; j<size; j++)
        {
            if(strstr(song[j], season[i]) != NULL)
            {
                puts(song[j]);
            }
        }
        puts("");
    }

    return 0;
}
