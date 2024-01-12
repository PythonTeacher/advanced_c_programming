#include <stdio.h>
#include <string.h>

#define MAX_NUM 5

int memberCnt;  // ���� ��ϵ� �����
char member[MAX_NUM][20];

void getMenu(int *menu);        // �޴� ��ȸ �� �Է�
void printAllMember();          // ��� ��ȸ
void insertMember();            // ��� ���
int searchMember(char name[]);  // ��� �˻� (�޴��� �ƴ�)
void updateMember();            // ��� ����
void deleteMember();            // ��� ����

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
            printf("���� �޴��Ӵ�!!");
        }

    }

    return 0;
}

void getMenu(int *menu)
{
    printf("\n=======<< �޴� >>======\n");
    printf("1. ��� ��ȸ\n");
    printf("2. ��� ���\n");   // �ߺ� üũ
    printf("3. ��� ����\n");
    printf("4. ��� ����\n");
    printf("9. ����\n");
    printf("=======================\n");
    printf("�޴� �Է� => ");
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
        printf("���̻� ����� �� �����ϴ� (�ִ� ����� : %d��)\n", memberCnt);
    }
    else
    {
        printf("����� ������� �Է��ϼ��� => ");
        gets(name);
        // �ߺ�üũ
        if(searchMember(name) >= 0)
        {
            printf("�̹� ��ϵ� ����Դϴ�\n");
            return;
        }

        strcpy(member[memberCnt], name);
        memberCnt++;
    }
    printf("## ��ϵǾ����ϴ�!!\n");
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
    printf("������ ������� �Է��ϼ��� => ");
    gets(name);
    // ��ϵ� ������� üũ
    idx = searchMember(name);
    if(idx < 0)
    {
        printf("����� �ȵ� ����Դϴ�\n");
        return;
    }

    printf("������ �̸��� �Է��ϼ��� => ");
    gets(name);

    strcpy(member[idx], name);
    printf("## ����Ǿ����ϴ�!!\n");
}

void deleteMember()
{
    char name[100];
    int idx, i;
    printf("������ ������� �Է��ϼ��� => ");
    gets(name);
    // ��ϵ� ������� üũ
    idx = searchMember(name);
    if(idx < 0)
    {
        printf("����� �ȵ� ����Դϴ�\n");
        return;
    }

    //������ idx���� ��ĭ�� �̵�
    for(i=idx; i<memberCnt-1; i++)
    {
        strcpy(member[i], member[i+1]);
    }
    memberCnt--;
    printf("## �����Ǿ����ϴ�!!\n");
}
