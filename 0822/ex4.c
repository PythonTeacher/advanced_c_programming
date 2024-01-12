#include <stdio.h>

void printMenu();
int validate(int num, int quantity);

#define SIZE 5

int main()
{
    int items[SIZE] = {10, 10, 10, 10, 10};
    int menu, i;
    int num, quantity;

    while(1)
    {
        printMenu();
        scanf("%d", &menu);

        switch(menu)
        {
        case 1:
            printf("\n����� ��ǰ��ȣ�� ������ �Է��ϼ��� : ");
            scanf("%d%d", &num, &quantity);
            if(validate(num, quantity) < 0)
                break;
            if(items[num-1] < quantity)
            {
                printf("\n��� �����մϴ�!! (���� ��� : %d��)\n", items[num-1]);
                break;
            }
            items[num-1] -= quantity;
            break;
        case 2:
            printf("\n�԰��� ��ǰ��ȣ�� ������ �Է��ϼ��� : ");
            scanf("%d%d", &num, &quantity);
            if(validate(num, quantity) < 0)
                break;
            items[num-1] += quantity;
            break;
        case 3:
            printf("\n-----------------\n");
            printf("��ǰ��ȣ ������\n");
            printf("-----------------\n");
            for(i=0; i<SIZE; i++)
            {
                printf("%d�� \t %2d��\n", i+1, items[i]);
            }
            printf("-----------------\n");
            break;
        case 9:
            printf("\n���α׷��� �����մϴ�\n");
            return 0;
        default:
            printf("\n���� �޴��Դϴ�\n");
        }
    }

    return 0;
}

void printMenu()
{
    printf("----------------\n");
    printf("<< Menu ��� >>\n");
    printf("1. ��ǰ ���\n");
    printf("2. ��ǰ �԰�\n");
    printf("3. ��� ��ȸ\n");
    printf("9. ����\n");
    printf("----------------\n");
    printf("�޴��Է� => ");
}

int validate(int num, int quantity)
{
   if(num < 1 || num > 5)
   {
       printf("\n���� ��ǰ��ȣ�Դϴ�\n");
       return -1;
   }
   if(quantity < 1)
   {
       printf("\n������ 1�̻��̾�� �մϴ�.\n");
       return -2;
   }

   return 0;
}
