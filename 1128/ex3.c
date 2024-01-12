/********************************************
 * �� �� �� : student.c
 * ��    �� : �л� �⼮�� �ý���
 * �� �� �� : ȫ �� ��
 * �� �� �� : 2014. 11. 7
 *******************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*---------- Global Variable --------------*/
int stdLstNum;             // �л� ���� ��ȣ

/*---------- Function Prototype -----------*/
void inputStudent(char **student);
void getMenu(int *menu);
char **movein(char **student);
void moveout(char **student);
void output(char **student);
char *makeString();
void saveStudent(char **student);
void freeStudent(char **student);
void _fflush();

/*
 * Function : main
 * @brief   : �л� �⼮�� �ý��� ���� �Լ�
 * @param   : void
 * @return  : int
 */
int main()
{
    int menu=0;

    FILE *fp = freopen("student.txt", "r", stdin);
    if(fp == NULL)
    {
        puts("file does not exist!!");
        return 1;
    }

    //printf("�л� �� �Է� => ");
    scanf("%d", &stdLstNum);

    char **student = (char **)malloc(stdLstNum * sizeof(char *));
    if(student == NULL)
    {
        puts("�޸� �Ҵ� ����!!");
        exit(1);
    }

    inputStudent(student);

    freopen("CON", "r", stdin);

    while(menu != 9)
    {
        getMenu(&menu);

        switch(menu)
        {
        case 1: output(student);  break;            // �л� ���
        case 2: student = movein(student);  break;  // ����
                //movein(&student);       // ����������
        case 3: moveout(student); break;            // ����
        case 9: puts("Bye~~"); break;               // ����
        default: puts("���� �޴��Դϴ�");
        }
    }

    saveStudent(student);

    freeStudent(student);

    fclose(fp);

    return 0;
}

/*
 * Function : inputStudent
 * @brief   : �л� ����� �Է¹޴� �Լ� (�޸� ���� �Ҵ� �̿�)
 * @param   : char **student
 * @return  : void
 */
void inputStudent(char **student)
{
    int i;
    _fflush();
    for(i=0; i<stdLstNum; i++)
    {
        //printf("[%d]�� �л� �Է� => ", i+1);
        student[i] = makeString();
    }
}

/*
 * Function : getMenu
 * @brief   : �޴��� ó���ϴ� �Լ�
 * @param   : int *menu
 * @return  : void
 */
void getMenu(int *menu)
{
    puts("\n<< �޴� ��� >>");
    puts("1. �л� ���");
    puts("2. ����");
    puts("3. ����");
    puts("9. ����");
    puts("--------------");
    printf(">> �޴� �Է� => ");
    scanf("%d", menu);
    _fflush();
}

/*
 * Function : output
 * @brief   : ��ü �л� ����� ����ϴ� �Լ�
 *           (���� �л��� ��� "[����]"�� ��µ�)
 * @param   : char **student
 * @return  : void
 */
void output(char **student)
{
    int i;
    for(i=0; i<stdLstNum; i++)
    {
        if(student[i] != NULL)
            printf("[%d]�� �л� => %s\n", i+1, student[i]);
        else
            printf("[%d]�� �л� => %s\n", i+1, "[����]");
    }
}

/*
 * Function : movein
 * @brief   : ������ ó���ϴ� �Լ� (�޸� ���� �Ҵ� �̿�)
 * @param   : char **student
 * @return  : void
 */
char **movein(char **student)
{
    char **newStudent = (char **)realloc(student, (stdLstNum+1) * sizeof(char *));
    if(newStudent == NULL)
    {
        puts("out of memory");
        exit(1);
    }

    printf("���� �л� �̸��� �Է��ϼ��� => ");
    newStudent[stdLstNum] = makeString();
    stdLstNum++;
    puts(">> ����ó���Ǿ����ϴ�!!");
    return newStudent;
}

/*
 * Function : moveout
 * @brief   : ������ ó���ϴ� �Լ�
 *            1. ��ȣ üũ
 *            2. �� ���⿩�� üũ
 *            3. ���� ó��
 * @param   : char **student
 * @return  : void
 */
void moveout(char **student)
{
    int i, flag=0;
    int num;

    printf("������ �л� ��ȣ�� �Է��ϼ��� => ");
    scanf("%d", &num);

    // ��ȣ üũ
    if(num < 1 || num > stdLstNum)
    {
        puts("�ùٸ��� ���� ��ȣ�Դϴ�.");
        return;
    }

    // ������ ���� üũ
    if(student[num-1] == NULL)
    {
        puts("�̹� ����� �л��Դϴ�.");
        return;
    }

    free(student[num-1]);
    student[num-1] = NULL;

    puts(">> ����ó���Ǿ����ϴ�!!");

    //num_of_student--;     // ����ǵ� ��ȣ�� �״�� ������
}

/*
 * Function : makeString
 * @brief   : ���ڿ��� ����� �Լ� (�޸� ���� �Ҵ� �̿�)
 * @param   : void
 * @return  : char *
 */
char *makeString()
{
    char temp[100];         // �ӽ� �迭
    gets(temp);

    if(strncmp(temp, "NULL", 4) == 0) return NULL;

    char *p = (char *)malloc(strlen(temp) + 1);
    if(p == NULL)
    {
        puts("out of memory");
        exit(1);
    }
    strcpy(p, temp);
    return p;
}

void saveStudent(char **student)
{
    int i;
    FILE *fp = freopen("student.txt", "w", stdout);
    if(fp == NULL)
    {
        puts("file open error!!");
        return;
    }

    printf("%d\n", stdLstNum);

    for(i=0; i<stdLstNum; i++)
    {
        if(student[i] != NULL)
            puts(student[i]);
        else
            puts("NULL");
    }

    fclose(fp);
}

/*
 * Function : freeStudent
 * @brief   : �����Ҵ� ���� �޸𸮸� �����ϴ� �Լ�
 * @param   : char **student
 * @return  : void
 */
void freeStudent(char **student)
{
    int i;
    for(i=0; i<stdLstNum; i++)
    {
        if(student[i] != NULL)
        {
            free(student[i]);
            student[i] = NULL;
        }
    }

    free(student);
}

/*
 * Function : _fflush
 * @brief   : �Է� ���۸� clear�ϴ� �Լ� (����Ű����)
 * @param   : void
 * @return  : void
 */
void _fflush()
{
    while(getchar() != '\n');
}
