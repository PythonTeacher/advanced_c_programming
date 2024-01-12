/********************************************
 * 파 일 명 : ex2.c
 * 학습내용 : 카드회사 고객관리
 * 처리방식 : 전문 입력, 화면 출력
 *
 * 작 성 자 : 홍 길 동
 * 작 성 일 : 2014. 11. 14
 *******************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "card.h"

int main()
{
    /*******************************************************
     * 전문 방식
     * 1. Delimiter 방식 (예) CSV, |, ^
     * 2. Fixed Length 방식 : 데이터에 Delimiter가 포함되어 있으면
     *                        안되므로 2번째 방식을 많이 씀
     * (예) 고객명     CHAR(20)     필수
     *      휴대폰번호 CHAR(13)
     *      휴대폰회사 CHAR(3)
     *      고객등급   CHAR(1)      필수
     *      FILLER     CHAR(3)
     *      --------------------
     *        전체길이 40
     *******************************************************/
    Customer customer = {0};
    char buf[1024];

    puts("<< 고객 정보 입력 (전문 방식) >>");
    puts("1234567890123456789012345678901234567890");
    //gets(buf);
    fgets(buf, sizeof(buf), stdin);
    buf[strlen(buf)-1]='\0';

    if(strlen(buf) != 40)
    {
        char msg[100];
        snprintf(msg, sizeof(msg), "오류코드:[%s], 오류메시지:[%s]\n전문길이:[%d]",
                "001", "전문 길이 오류", strlen(buf));
        puts(msg);
        exit(1);
    }

    // 고객명
    strncpy(customer.name, buf, NAME_LEN);
    if(isEmpty(customer.name))
    {
        printf("오류코드:[%s], 오류메시지:[%s]\n", "002", "고객명 미입력");
        exit(1);
    }
    rtrim(customer.name, NAME_LEN);

    // 휴대폰 번호
    strncpy(customer.mobileNumber, buf+NAME_LEN, MOBILE_NUMBER_LEN);
    rtrim(customer.mobileNumber, MOBILE_NUMBER_LEN);

    // 휴대폰 회사
    strncpy(customer.mobileCompany,
            buf+NAME_LEN+MOBILE_NUMBER_LEN,
            MOBILE_COMPANY_LEN);
    rtrim(customer.mobileCompany, MOBILE_COMPANY_LEN);

    // 고객 등급
    strncpy(customer.level,
            buf+NAME_LEN+MOBILE_NUMBER_LEN+MOBILE_COMPANY_LEN,
            LEVEL_LEN);
    if(isEmpty(customer.level))
    {
        printf("오류코드:[%s], 오류메시지:[%s]\n", "003", "고객 등급 미입력");
        exit(1);
    }

    // 고객 정보 출력
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
    puts("\n<< 고객 정보 출력 >>");
    printf("고객명 : [%s]\n", c.name);
    printf("휴대폰 번호 : [%s]\n", c.mobileNumber);
    printf("휴대폰 회사 : [%s]\n", c.mobileCompany);
    printf("고객 등급 : [%s]\n", getLevel(c.level));
}

char *getLevel(char *s)
{
    if(!strcmp(s, "1")) return "일반";
    else if(!strcmp(s, "2")) return "우대";
    else if(!strcmp(s, "3")) return "VIP";

    return "None";
}
