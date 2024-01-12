/*---------- Message Length -----------*/
#define NAME_LEN            20
#define MOBILE_NUMBER_LEN   13
#define MOBILE_COMPANY_LEN  3
#define LEVEL_LEN           1
#define RES_CODE_LEN        3

/*---------- Structure ----------------*/
// ī��ȸ�� ������
typedef struct customer
{
    char name[20+1];                // ����
    char mobileNumber[13+1];        // �޴��� ��ȣ
    char mobileCompany[3+1];        // �޴��� ȸ��
    char level[1+1];                // �� ��� (1: �Ϲ�, 2: ���, 3: VIP)
    char resCode[3+1];              // �����ڵ�
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
