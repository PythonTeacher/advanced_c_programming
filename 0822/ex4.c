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
            printf("\n출고할 제품번호와 수량을 입력하세요 : ");
            scanf("%d%d", &num, &quantity);
            if(validate(num, quantity) < 0)
                break;
            if(items[num-1] < quantity)
            {
                printf("\n재고가 부족합니다!! (현재 재고 : %d개)\n", items[num-1]);
                break;
            }
            items[num-1] -= quantity;
            break;
        case 2:
            printf("\n입고할 제품번호와 수량을 입력하세요 : ");
            scanf("%d%d", &num, &quantity);
            if(validate(num, quantity) < 0)
                break;
            items[num-1] += quantity;
            break;
        case 3:
            printf("\n-----------------\n");
            printf("제품번호 재고수량\n");
            printf("-----------------\n");
            for(i=0; i<SIZE; i++)
            {
                printf("%d번 \t %2d개\n", i+1, items[i]);
            }
            printf("-----------------\n");
            break;
        case 9:
            printf("\n프로그램을 종료합니다\n");
            return 0;
        default:
            printf("\n없는 메뉴입니다\n");
        }
    }

    return 0;
}

void printMenu()
{
    printf("----------------\n");
    printf("<< Menu 출력 >>\n");
    printf("1. 제품 출고\n");
    printf("2. 제품 입고\n");
    printf("3. 재고 조회\n");
    printf("9. 종료\n");
    printf("----------------\n");
    printf("메뉴입력 => ");
}

int validate(int num, int quantity)
{
   if(num < 1 || num > 5)
   {
       printf("\n없는 제품번호입니다\n");
       return -1;
   }
   if(quantity < 1)
   {
       printf("\n수량은 1이상이어야 합니다.\n");
       return -2;
   }

   return 0;
}
