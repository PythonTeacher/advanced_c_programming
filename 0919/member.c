#include <stdio.h>
#include <string.h>

#define MAX_NUM 5

int memberCnt;  // 현재 등록된 멤버수
char member[MAX_NUM][20];

void getMenu(int *menu);        // 메뉴 조회 및 입력
void printAllMember();          // 멤버 조회
void insertMember();            // 멤버 등록
int searchMember(char name[]);  // 멤버 검색 (메뉴는 아님)
void updateMember();            // 멤버 수정
void deleteMember();            // 멤버 삭제

int main()
{
    int menu;

    while(1)
    {
        getMenu(&menu);

        switch(menu)
        {
        case 1:
            printAllMember(); break;
        case 2:
            insertMember(); break;
        case 3:
            updateMember(); break;
        case 4:
            deleteMember(); break;
        case 9:
            printf("Bye!!"); return 0;
        default:
            printf("없는 메뉴임당!!");
        }

    }

    return 0;
}

void getMenu(int *menu)
{
    printf("\n=======<< 메뉴 >>======\n");
    printf("1. 멤버 조회\n");
    printf("2. 멤버 등록\n");   // 중복 체크
    printf("3. 멤버 수정\n");
    printf("4. 멤버 삭제\n");
    printf("9. 종료\n");
    printf("=======================\n");
    printf("메뉴 입력 => ");
    scanf("%d", menu);
    while(getchar() != '\n');
}

void printAllMember()
{
    int i;

    for(i=0; i<memberCnt; i++)
    {
        printf("[%d] %s\n", i+1, member[i]);
    }
}

void insertMember()
{
    char name[100];
    if(memberCnt == MAX_NUM)
    {
        printf("더이상 등록할 수 없습니다 (최대 멤버수 : %d명)\n", memberCnt);
    }
    else
    {
        printf("등록할 멤버명을 입력하세요 => ");
        gets(name);
        // 중복체크
        if(searchMember(name) >= 0)
        {
            printf("이미 등록된 멤버입니다\n");
            return;
        }

        strcpy(member[memberCnt], name);
        memberCnt++;
    }
    printf("## 등록되었습니다!!\n");
}

int searchMember(char name[])
{
    int i;
    for(i=0; i<memberCnt; i++)
    {
        if(strcmp(member[i], name) == 0)
            return i;
    }
    return -1;
}

void updateMember()
{
    char name[100];
    int idx;
    printf("수정할 멤버명을 입력하세요 => ");
    gets(name);
    // 등록된 멤버인지 체크
    idx = searchMember(name);
    if(idx < 0)
    {
        printf("등록이 안된 멤버입니다\n");
        return;
    }

    printf("변경할 이름을 입력하세요 => ");
    gets(name);

    strcpy(member[idx], name);
    printf("## 변경되었습니다!!\n");
}

void deleteMember()
{
    char name[100];
    int idx, i;
    printf("삭제할 멤버명을 입력하세요 => ");
    gets(name);
    // 등록된 멤버인지 체크
    idx = searchMember(name);
    if(idx < 0)
    {
        printf("등록이 안된 멤버입니다\n");
        return;
    }

    //삭제할 idx부터 한칸씩 이동
    for(i=idx; i<memberCnt-1; i++)
    {
        strcpy(member[i], member[i+1]);
    }
    memberCnt--;
    printf("## 삭제되었습니다!!\n");
}
