/*---------- Message Length -----------*/
#define NAME_LEN            20
#define MOBILE_NUMBER_LEN   13
#define MOBILE_COMPANY_LEN  3
#define LEVEL_LEN           1

/*---------- Structure ----------------*/
// ī��ȸ�� ������
typedef struct customer
{
    char name[NAME_LEN+1];                      // ����
    char mobileNumber[MOBILE_NUMBER_LEN+1];     // �޴��� ��ȣ
    char mobileCompany[MOBILE_COMPANY_LEN+1];   // �޴��� ȸ��
    char level[LEVEL_LEN+1];                    // �� ��� (1: �Ϲ�, 2: ���, 3: VIP)
} Customer;

/*---------- Function Prototype --------*/
int isEmpty(char *s);
void rtrim(char *s, int length);
void printCustomer(Customer c);
char *getLevel(char *s);
