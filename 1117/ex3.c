/********************************************
 * �� �� �� : ex3.c
 * �н����� : ī��ȸ�� ������
 * ó����� : ���� �Է�, ���� ���
 *
 * �� �� �� : ȫ �� ��
 * �� �� �� : 2014. 11. 14
 *******************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "card_upgrade.h"

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
     *      �����ڵ�   CHAR(3)      000 (����)
     *                              001 (�������� ����)
     *                              002 (���� ���Է�)
     *                              003 (����� ���Է�)
     *                              004 (��Ÿ ����)
     *      --------------------
     *        ��ü���� 40
     *******************************************************/
    Customer customer = {0};
    char in_buf[1024];
    char out_buf[1024]={0};

    puts("<< �� ���� �Է� (���� ���) >>");
    puts("1234567890123456789012345678901234567890");
    //gets(in_buf);
    fgets(in_buf, sizeof(in_buf), stdin);
    in_buf[strlen(in_buf)-1]='\0';

    if(checkLength(&customer, in_buf, out_buf) < 0)
    {
        puts("\n<< ��� ���� >>");
        printf("%s\n", out_buf);
        return 1;
    }

    // �Է� ���� ó��
    if(procInput(&customer, in_buf) == 0)
    {
        // �� ���� ���
        printCustomer(customer);
    }

    // ��� ���� ó��
    puts("\n<< ��� ���� >>");
    printf("%s\n", procOutput(&customer, in_buf, out_buf));

    return 0;
}

int checkLength(Customer *customer, char *in_buf, char *out_buf)
{
    if(strlen(in_buf) != 40)
    {
        printf("�����ڵ�:[%s], �����޽���:[%s]\n��������:[%d]\n",
                "001", "���� ���� ����", strlen(in_buf));
        strcpy(customer->resCode, "001");

        memcpy(out_buf, in_buf, 40);
        rpad(out_buf, NAME_LEN+MOBILE_NUMBER_LEN+MOBILE_COMPANY_LEN+LEVEL_LEN);
        strncpy(out_buf+NAME_LEN+MOBILE_NUMBER_LEN+MOBILE_COMPANY_LEN+LEVEL_LEN,
                customer->resCode, RES_CODE_LEN);

        return -1;
    }
    return 0;
}

int procInput(Customer *customer, char *buf)
{
    // ����
    strncpy(customer->name, buf, NAME_LEN);
    if(isEmpty(customer->name))
    {
        printf("�����ڵ�:[%s], �����޽���:[%s]\n", "002", "���� ���Է�");
        strcpy(customer->resCode, "002");
        return -1;
    }
    rtrim(customer->name, NAME_LEN);

    // �޴��� ��ȣ
    strncpy(customer->mobileNumber, buf+NAME_LEN, MOBILE_NUMBER_LEN);
    rtrim(customer->mobileNumber, MOBILE_NUMBER_LEN);

    // �޴��� ȸ��
    strncpy(customer->mobileCompany,
            buf+NAME_LEN+MOBILE_NUMBER_LEN,
            MOBILE_COMPANY_LEN);
    rtrim(customer->mobileCompany, MOBILE_COMPANY_LEN);

    // �� ���
    strncpy(customer->level,
            buf+NAME_LEN+MOBILE_NUMBER_LEN+MOBILE_COMPANY_LEN,
            LEVEL_LEN);

    if(isEmpty(customer->level))
    {
        printf("�����ڵ�:[%s], �����޽���:[%s]\n", "003", "�� ��� ���Է�");
        strcpy(customer->resCode, "003");
        return -1;
    }

    // ������ ��� "000" ����
    strncpy(customer->resCode, "000", RES_CODE_LEN);

    return 0;
}

char *procOutput(Customer *customer, char *in_buf, char *out_buf)
{
    // ���� �߻� �� �Է������� �״�� �����Ͽ� ����������� �����
    // �����ڵ� �����Ͽ� �����ϱ�
    if(strncmp(customer->resCode, "000", RES_CODE_LEN))
    {
        strncpy(out_buf, in_buf,
                NAME_LEN+MOBILE_NUMBER_LEN+MOBILE_COMPANY_LEN+LEVEL_LEN);
        strncpy(out_buf+NAME_LEN+MOBILE_NUMBER_LEN+MOBILE_COMPANY_LEN+LEVEL_LEN,
                customer->resCode, RES_CODE_LEN);
    }
    else
    {
        strncpy(out_buf, rpad(customer->name, NAME_LEN), NAME_LEN);
        strncpy(out_buf+NAME_LEN,
                rpad(customer->mobileNumber, MOBILE_NUMBER_LEN),
                MOBILE_NUMBER_LEN);
        strncpy(out_buf+NAME_LEN+MOBILE_NUMBER_LEN,
                rpad(customer->mobileCompany, MOBILE_COMPANY_LEN),
                MOBILE_COMPANY_LEN);
        strncpy(out_buf+NAME_LEN+MOBILE_NUMBER_LEN+MOBILE_COMPANY_LEN,
                customer->level, LEVEL_LEN);
        strncpy(out_buf+NAME_LEN+MOBILE_NUMBER_LEN+MOBILE_COMPANY_LEN+LEVEL_LEN,
                customer->resCode, RES_CODE_LEN);
    }

    return out_buf;
}

char *rpad(char *s, int length)
{
    int i;
    for(i=strlen(s); i<length; i++)
    {
        s[i] = ' ';
    }
    return s;
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
