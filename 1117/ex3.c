/********************************************
 * 파 일 명 : ex3.c
 * 학습내용 : 카드회사 고객관리
 * 처리방식 : 전문 입력, 전문 출력
 *
 * 작 성 자 : 홍 길 동
 * 작 성 일 : 2014. 11. 14
 *******************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "card_upgrade.h"

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
     *      응답코드   CHAR(3)      000 (정상)
     *                              001 (전문길이 오류)
     *                              002 (고객명 미입력)
     *                              003 (고객등급 미입력)
     *                              004 (기타 오류)
     *      --------------------
     *        전체길이 40
     *******************************************************/
    Customer customer = {0};
    char in_buf[1024];
    char out_buf[1024]={0};

    puts("<< 고객 정보 입력 (전문 방식) >>");
    puts("1234567890123456789012345678901234567890");
    //gets(in_buf);
    fgets(in_buf, sizeof(in_buf), stdin);
    in_buf[strlen(in_buf)-1]='\0';

    if(checkLength(&customer, in_buf, out_buf) < 0)
    {
        puts("\n<< 출력 전문 >>");
        printf("%s\n", out_buf);
        return 1;
    }

    // 입력 전문 처리
    if(procInput(&customer, in_buf) == 0)
    {
        // 고객 정보 출력
        printCustomer(customer);
    }

    // 출력 전문 처리
    puts("\n<< 출력 전문 >>");
    printf("%s\n", procOutput(&customer, in_buf, out_buf));

    return 0;
}

int checkLength(Customer *customer, char *in_buf, char *out_buf)
{
    if(strlen(in_buf) != 40)
    {
        printf("오류코드:[%s], 오류메시지:[%s]\n전문길이:[%d]\n",
                "001", "전문 길이 오류", strlen(in_buf));
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
    // 고객명
    strncpy(customer->name, buf, NAME_LEN);
    if(isEmpty(customer->name))
    {
        printf("오류코드:[%s], 오류메시지:[%s]\n", "002", "고객명 미입력");
        strcpy(customer->resCode, "002");
        return -1;
    }
    rtrim(customer->name, NAME_LEN);

    // 휴대폰 번호
    strncpy(customer->mobileNumber, buf+NAME_LEN, MOBILE_NUMBER_LEN);
    rtrim(customer->mobileNumber, MOBILE_NUMBER_LEN);

    // 휴대폰 회사
    strncpy(customer->mobileCompany,
            buf+NAME_LEN+MOBILE_NUMBER_LEN,
            MOBILE_COMPANY_LEN);
    rtrim(customer->mobileCompany, MOBILE_COMPANY_LEN);

    // 고객 등급
    strncpy(customer->level,
            buf+NAME_LEN+MOBILE_NUMBER_LEN+MOBILE_COMPANY_LEN,
            LEVEL_LEN);

    if(isEmpty(customer->level))
    {
        printf("오류코드:[%s], 오류메시지:[%s]\n", "003", "고객 등급 미입력");
        strcpy(customer->resCode, "003");
        return -1;
    }

    // 정상인 경우 "000" 셋팅
    strncpy(customer->resCode, "000", RES_CODE_LEN);

    return 0;
}

char *procOutput(Customer *customer, char *in_buf, char *out_buf)
{
    // 에러 발생 시 입력전문을 그대로 복사하여 출력전문으로 만들고
    // 에러코드 셋팅하여 리턴하기
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
