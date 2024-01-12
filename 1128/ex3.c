/********************************************
 * 파 일 명 : student.c
 * 내    용 : 학생 출석부 시스템
 * 작 성 자 : 홍 길 동
 * 작 성 일 : 2014. 11. 7
 *******************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*---------- Global Variable --------------*/
int stdLstNum;             // 학생 최종 번호

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
 * @brief   : 학생 출석부 시스템 메인 함수
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

    //printf("학생 수 입력 => ");
    scanf("%d", &stdLstNum);

    char **student = (char **)malloc(stdLstNum * sizeof(char *));
    if(student == NULL)
    {
        puts("메모리 할당 실패!!");
        exit(1);
    }

    inputStudent(student);

    freopen("CON", "r", stdin);

    while(menu != 9)
    {
        getMenu(&menu);

        switch(menu)
        {
        case 1: output(student);  break;            // 학생 출력
        case 2: student = movein(student);  break;  // 전입
                //movein(&student);       // 삼중포인터
        case 3: moveout(student); break;            // 전출
        case 9: puts("Bye~~"); break;               // 종료
        default: puts("없는 메뉴입니다");
        }
    }

    saveStudent(student);

    freeStudent(student);

    fclose(fp);

    return 0;
}

/*
 * Function : inputStudent
 * @brief   : 학생 명단을 입력받는 함수 (메모리 동적 할당 이용)
 * @param   : char **student
 * @return  : void
 */
void inputStudent(char **student)
{
    int i;
    _fflush();
    for(i=0; i<stdLstNum; i++)
    {
        //printf("[%d]번 학생 입력 => ", i+1);
        student[i] = makeString();
    }
}

/*
 * Function : getMenu
 * @brief   : 메뉴를 처리하는 함수
 * @param   : int *menu
 * @return  : void
 */
void getMenu(int *menu)
{
    puts("\n<< 메뉴 출력 >>");
    puts("1. 학생 출력");
    puts("2. 전입");
    puts("3. 전출");
    puts("9. 종료");
    puts("--------------");
    printf(">> 메뉴 입력 => ");
    scanf("%d", menu);
    _fflush();
}

/*
 * Function : output
 * @brief   : 전체 학생 명단을 출력하는 함수
 *           (전출 학생의 경우 "[전출]"로 출력됨)
 * @param   : char **student
 * @return  : void
 */
void output(char **student)
{
    int i;
    for(i=0; i<stdLstNum; i++)
    {
        if(student[i] != NULL)
            printf("[%d]번 학생 => %s\n", i+1, student[i]);
        else
            printf("[%d]번 학생 => %s\n", i+1, "[전출]");
    }
}

/*
 * Function : movein
 * @brief   : 전입을 처리하는 함수 (메모리 동적 할당 이용)
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

    printf("전입 학생 이름을 입력하세요 => ");
    newStudent[stdLstNum] = makeString();
    stdLstNum++;
    puts(">> 전입처리되었습니다!!");
    return newStudent;
}

/*
 * Function : moveout
 * @brief   : 전출을 처리하는 함수
 *            1. 번호 체크
 *            2. 기 전출여부 체크
 *            3. 전출 처리
 * @param   : char **student
 * @return  : void
 */
void moveout(char **student)
{
    int i, flag=0;
    int num;

    printf("전출할 학생 번호를 입력하세요 => ");
    scanf("%d", &num);

    // 번호 체크
    if(num < 1 || num > stdLstNum)
    {
        puts("올바르지 않은 번호입니다.");
        return;
    }

    // 기전출 여부 체크
    if(student[num-1] == NULL)
    {
        puts("이미 전출된 학생입니다.");
        return;
    }

    free(student[num-1]);
    student[num-1] = NULL;

    puts(">> 전출처리되었습니다!!");

    //num_of_student--;     // 전출되도 번호는 그대로 유지됨
}

/*
 * Function : makeString
 * @brief   : 문자열을 만드는 함수 (메모리 동적 할당 이용)
 * @param   : void
 * @return  : char *
 */
char *makeString()
{
    char temp[100];         // 임시 배열
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
 * @brief   : 동적할당 받은 메모리를 해제하는 함수
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
 * @brief   : 입력 버퍼를 clear하는 함수 (엔터키까지)
 * @param   : void
 * @return  : void
 */
void _fflush()
{
    while(getchar() != '\n');
}
