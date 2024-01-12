/*---------- Message Length -----------*/
#define NAME_LEN            20
#define MOBILE_NUMBER_LEN   13
#define MOBILE_COMPANY_LEN  3
#define LEVEL_LEN           1

/*---------- Structure ----------------*/
// 카드회사 고객정보
typedef struct customer
{
    char name[NAME_LEN+1];                      // 고객명
    char mobileNumber[MOBILE_NUMBER_LEN+1];     // 휴대폰 번호
    char mobileCompany[MOBILE_COMPANY_LEN+1];   // 휴대폰 회사
    char level[LEVEL_LEN+1];                    // 고객 등급 (1: 일반, 2: 우대, 3: VIP)
} Customer;

/*---------- Function Prototype --------*/
int isEmpty(char *s);
void rtrim(char *s, int length);
void printCustomer(Customer c);
char *getLevel(char *s);
