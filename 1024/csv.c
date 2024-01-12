#include <stdio.h>
#include <string.h>
#include <stdlib.h>     // atoi

#define SIZE 5

void copyArray(char (*data)[100], char (*copy)[100]);
void printMember(char (*name)[20], char (*position)[20],
                 int *height, char (*nickname)[20]);

int main()
{
    char data[SIZE][100] = {"채치수,센터,197,괴물고릴라",
                            "정대만,슈팅가드,184,불꽃남자",
                            "송태섭,포인트가드,168,에이스가드",
                            "서태웅,스몰포워드,187,수퍼루키",
                            "강백호,파워포워드,189,자칭천재"};

    char copy[SIZE][100];
    char name[SIZE][20] = {0};
    char position[SIZE][20] = {0};
    int height[SIZE];
    char nickname[SIZE][20] = {0};

    int i;
    char *p;

    //copyArray(data, copy);
    memcpy(copy, data, sizeof(data));

    for(i=0; i<SIZE; i++)
    {
        p = strtok(copy[i], ",");       // 이름
        strncpy(name[i], p, sizeof(name[i]));

        p = strtok(NULL, ",");          // 포지션
        strncpy(position[i], p, sizeof(position[i]));

        p = strtok(NULL, ",");          // 키
        height[i] = atoi(p);

        p = strtok(NULL, ",");          // 별명
        strncpy(nickname[i], p, sizeof(nickname[i]));
    }

    printMember(name, position, height, nickname);

    return 0;
}

void printMember(char (*name)[20], char (*position)[20],
                 int *height, char (*nickname)[20])
{
    int i;
    char buf[100];

    puts("<< 슬램덩크 멤버 >>");
    for(i=0; i<SIZE; i++)
    {
        snprintf(buf, sizeof(buf),
                 "[%d] 이름 : %s, 포지션 : %10s, 키 : %d, 별명 : %s",
                 i+1, name[i], position[i], height[i], nickname[i]);
        puts(buf);
    }
}


void copyArray(char (*data)[100], char (*copy)[100])
{
    int i;
    for(i=0; i<SIZE; i++)
    {
        strncpy(copy[i], data[i], sizeof(copy[i]));
    }
}

