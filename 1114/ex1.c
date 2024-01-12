/********************************************
 * 파 일 명 : ex1.c
 * 학습내용 : 카드회사 고객관리
 * 처리방식 : 화면 입력, 화면 출력
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
    Customer customer={0};
    char buf[1024];

    puts("<< 고객 정보 입력 >>");

    // 고객명
    printf("고객명 => ");
    gets(buf);

    strncpy(customer.name, buf, NAME_LEN);
    if(isEmpty(customer.name))
    {
        printf("오류코드:[%s], 오류메시지:[%s]\n", "002", "고객명 미입력");
        exit(1);
    }
    rtrim(customer.name, NAME_LEN);

    // 휴대폰 번호
    printf("휴대폰 번호 => ");
    gets(buf);

    strncpy(customer.mobileNumber, buf, MOBILE_NUMBER_LEN);
    rtrim(customer.mobileNumber, MOBILE_NUMBER_LEN);

    // 휴대폰 회사
    printf("휴대폰 회사 => ");
    gets(buf);

    strncpy(customer.mobileCompany, buf, MOBILE_COMPANY_LEN);
    rtrim(customer.mobileCompany, MOBILE_COMPANY_LEN);

    // 고객 등급
    printf("고객 등급 => ");
    gets(buf);

    strncpy(customer.level, buf, LEVEL_LEN);
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
