#include <stdio.h>
#include <string.h>
#include <stdlib.h>     // atoi

#define SIZE 5

void copyArray(char (*data)[100], char (*copy)[100]);
void printMember(char (*name)[20], char (*position)[20],
                 int *height, char (*nickname)[20]);

int main()
{
    char data[SIZE][100] = {"äġ��,����,197,��������",
                            "���븸,���ð���,184,�Ҳɳ���",
                            "���¼�,����Ʈ����,168,���̽�����",
                            "���¿�,����������,187,���۷�Ű",
                            "����ȣ,�Ŀ�������,189,��Īõ��"};

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
        p = strtok(copy[i], ",");       // �̸�
        strncpy(name[i], p, sizeof(name[i]));

        p = strtok(NULL, ",");          // ������
        strncpy(position[i], p, sizeof(position[i]));

        p = strtok(NULL, ",");          // Ű
        height[i] = atoi(p);

        p = strtok(NULL, ",");          // ����
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

    puts("<< ������ũ ��� >>");
    for(i=0; i<SIZE; i++)
    {
        snprintf(buf, sizeof(buf),
                 "[%d] �̸� : %s, ������ : %10s, Ű : %d, ���� : %s",
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

