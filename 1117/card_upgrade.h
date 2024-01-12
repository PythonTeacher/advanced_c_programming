/*---------- Message Length -----------*/
#define NAME_LEN            20
#define MOBILE_NUMBER_LEN   13
#define MOBILE_COMPANY_LEN  3
#define LEVEL_LEN           1
#define RES_CODE_LEN        3

/*---------- Structure ----------------*/
// 카드회사 고객정보
typedef struct customer
{
    char name[20+1];                // 고객명
    char mobileNumber[13+1];        // 휴대폰 번호
    char mobileCompany[3+1];        // 휴대폰 회사
    char level[1+1];                // 고객 등급 (1: 일반, 2: 우대, 3: VIP)
    char resCode[3+1];              // 응답코드
} Customer;

/*---------- Function Prototype --------*/
int checkLength(Customer *customer, char *in_buf, char *out_buf);
int procInput(Customer *customer, char *buf);
char *procOutput(Customer *customer, char *in_buf, char *out_buf);
int isEmpty(char *s);
void rtrim(char *s, int length);
void printCustomer(Customer c);
char *getLevel(char *s);
char *rpad(char *s, int length);
