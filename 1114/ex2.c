/********************************************
 * �� �� �� : ex2.c
 * �н����� : ī��ȸ�� ������
 * ó����� : ���� �Է�, ȭ�� ���
 *
 * �� �� �� : ȫ �� ��
 * �� �� �� : 2014. 11. 14
 *******************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "card.h"

int main()
{
    /*******************************************************
     * ���� ���
     * 1. Delimiter ��� (��) CSV, |, ^
     * 2. Fixed Length ��� : �����Ϳ� Delimiter�� ���ԵǾ� ������
     *                        �ȵǹǷ� 2��° ����� ���� ��
     * (��) ����     CHAR(20)     �ʼ�
     *      �޴�����ȣ CHAR(13)
     *      �޴���ȸ�� CHAR(3)
     *      �����   CHAR(1)      �ʼ�
     *      FILLER     CHAR(3)
     *      --------------------
     *        ��ü���� 40
     *******************************************************/
    Customer customer = {0};
    char buf[1024];

    puts("<< �� ���� �Է� (���� ���) >>");
    puts("1234567890123456789012345678901234567890");
    //gets(buf);
    fgets(buf, sizeof(buf), stdin);
    buf[strlen(buf)-1]='\0';

    if(strlen(buf) != 40)
    {
        char msg[100];
        snprintf(msg, sizeof(msg), "�����ڵ�:[%s], �����޽���:[%s]\n��������:[%d]",
                "001", "���� ���� ����", strlen(buf));
        puts(msg);
        exit(1);
    }

    // ����
    strncpy(customer.name, buf, NAME_LEN);
    if(isEmpty(customer.name))
    {
        printf("�����ڵ�:[%s], �����޽���:[%s]\n", "002", "���� ���Է�");
        exit(1);
    }
    rtrim(customer.name, NAME_LEN);

    // �޴��� ��ȣ
    strncpy(customer.mobileNumber, buf+NAME_LEN, MOBILE_NUMBER_LEN);
    rtrim(customer.mobileNumber, MOBILE_NUMBER_LEN);

    // �޴��� ȸ��
    strncpy(customer.mobileCompany,
            buf+NAME_LEN+MOBILE_NUMBER_LEN,
            MOBILE_COMPANY_LEN);
    rtrim(customer.mobileCompany, MOBILE_COMPANY_LEN);

    // �� ���
    strncpy(customer.level,
            buf+NAME_LEN+MOBILE_NUMBER_LEN+MOBILE_COMPANY_LEN,
            LEVEL_LEN);
    if(isEmpty(customer.level))
    {
        printf("�����ڵ�:[%s], �����޽���:[%s]\n", "003", "�� ��� ���Է�");
        exit(1);
    }

    // �� ���� ���
    printCustomer(customer);

    return 0;
}

int isEmpty(char *s)
{
    int i;
    int len=strlen(s);
    for(i=0; i<len; i++)
        if(!isspace(s[i]))
            return 0;
    return 1;
}

void rtrim(char *s, int length)
{
    int i;
    for(i=strlen(s)-1; isspace(s[i]) && i>=0; i--);   // skip right side white spaces
    s[i+1] = '\0';
}

void printCustomer(Customer c)
{
    puts("\n<< �� ���� ��� >>");
    printf("���� : [%s]\n", c.name);
    printf("�޴��� ��ȣ : [%s]\n", c.mobileNumber);
    printf("�޴��� ȸ�� : [%s]\n", c.mobileCompany);
    printf("�� ��� : [%s]\n", getLevel(c.level));
}

char *getLevel(char *s)
{
    if(!strcmp(s, "1")) return "�Ϲ�";
    else if(!strcmp(s, "2")) return "���";
    else if(!strcmp(s, "3")) return "VIP";

    return "None";
}
