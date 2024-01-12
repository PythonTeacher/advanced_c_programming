#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct menu
{
    char *main;
    char *soup;
    char *side;
    char *dessert;
} Menu;

void inputMenu(Menu *menu);
char *makeString();
void outputMenu(Menu *menu);
void freeMenu(Menu *menu);

int num;

int main()
{
    FILE *fp = freopen("menu.txt", "r", stdin);
    if(fp == NULL)
    {
        puts("file does not exist!!");
        return 1;
    }

    scanf("%d", &num);      // 메뉴 개수 입력
    getchar();

    Menu *menu = (Menu *)malloc(num * sizeof(Menu));

    inputMenu(menu);
    outputMenu(menu);
    freeMenu(menu);

    return 0;
}

void inputMenu(Menu *menu)
{
    int i;

    for(i=0; i<num; i++)
    {
        menu[i].main = makeString();
        menu[i].soup = makeString();
        menu[i].side = makeString();
        menu[i].dessert = makeString();
    }
}

char *makeString()
{
    char temp[100];
    fgets(temp, sizeof(temp), stdin);
    temp[strlen(temp)-1] = '\0';

    char *p = (char *)malloc(strlen(temp) + 1);
    strcpy(p, temp);

    return p;
}

void outputMenu(Menu *menu)
{
    int i;

    for(i=0; i<num; i++)
    {
        printf("<< %d번째 메뉴 >>\n", i+1);
        printf("메인 : %s\n", menu[i].main);
        printf("국 : %s\n", menu[i].soup);
        printf("반찬 : %s\n", menu[i].side);
        printf("후식 : %s\n\n", menu[i].dessert);
    }
}

void freeMenu(Menu *menu)
{
    int i;

    for(i=0; i<num; i++)
    {
        free(menu[i].main);
        free(menu[i].soup);
        free(menu[i].side);
        free(menu[i].dessert);
    }

    free(menu);
}
