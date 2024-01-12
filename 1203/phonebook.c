#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _phoneBook
{
    char *name;
    char *phoneNum;
}PhoneBook;

int num;

int getMenu();
void loadPhoneBook(PhoneBook *phoneBook);
void printPhoneBook(PhoneBook *phoneBook);
void searchPhoneBook(PhoneBook *phoneBook);
PhoneBook *addPhoneBook(PhoneBook *phoneBook);
void updatePhoneBook(PhoneBook *phoneBook);
PhoneBook *deletePhoneBook(PhoneBook *phoneBook);
void savePhoneBook(PhoneBook *phoneBook);
void freePhoneBook(PhoneBook *phoneBook);
char *makeString();

int main()
{
    int menu = 0;

    FILE *ifp = freopen("phonebook.txt", "r", stdin);

    if(ifp == NULL)
    {
        puts("file does not exist!!");
        return 1;
    }

    scanf("%d", &num);
    getchar();

    PhoneBook *phoneBook = (PhoneBook *)malloc(num * sizeof(PhoneBook));

    if(phoneBook == NULL)
    {
        puts("memory allocation error!!");
        return 1;
    }

    loadPhoneBook(phoneBook);

    freopen("CON", "r", stdin);

    while(menu != 9)
    {
        menu = getMenu();

        switch(menu)
        {
        case 1: printPhoneBook(phoneBook);   break;
        case 2: searchPhoneBook(phoneBook);  break;
        case 3: phoneBook = addPhoneBook(phoneBook);     break;
        case 4: updatePhoneBook(phoneBook);  break;
        case 5: phoneBook = deletePhoneBook(phoneBook);  break;
        case 9: savePhoneBook(phoneBook);    break;
        default: puts("없는 메뉴입니다.");
        }

        getch();
        system("cls");
    }

    puts("Bye!!");
    freePhoneBook(phoneBook);

    return 0;
}

int getMenu()
{
    int menu;

    puts("------<< PhoneBook Menu >>-------");
    puts(" 1. print phonebook");
    puts(" 2. search phonebook");
    puts(" 3. add phonebook");
    puts(" 4. update phonebook");
    puts(" 5. delete phonebook");
    puts(" 9. exit");
    puts("---------------------------------");
    printf(">> input menu => ");
    scanf("%d", &menu);
    getchar();

    return menu;
}

void loadPhoneBook(PhoneBook *phoneBook)
{
    int i;
    for(i=0; i<num; i++)
    {
        phoneBook[i].name = makeString();
        phoneBook[i].phoneNum = makeString();
    }
}

void printPhoneBook(PhoneBook *phoneBook)
{
    int i;
    for(i=0; i<num; i++)
    {
        printf("[%d] %s %s\n", i+1,
                               phoneBook[i].name,
                               phoneBook[i].phoneNum);
    }
}

void searchPhoneBook(PhoneBook *phoneBook)
{
    int i;
    char name[100];

    printf("input name for search => ");
    fgets(name, sizeof(name), stdin);
    name[strlen(name)-1] = '\0';

    for(i=0; i<num; i++)
    {
        if(strstr(phoneBook[i].name, name) != NULL)
        {
            printf("[%d] %s %s\n", i+1,
                                   phoneBook[i].name,
                                   phoneBook[i].phoneNum);
        }
    }
}

PhoneBook *addPhoneBook(PhoneBook *phoneBook)
{
    phoneBook = (PhoneBook *)realloc(phoneBook, (num+1) * sizeof(PhoneBook));
    if(phoneBook == NULL)
    {
        puts("memory allocation error!!");
        exit(1);
    }

    printf("input name => ");
    phoneBook[num].name = makeString();

    printf("input phone number => ");
    phoneBook[num].phoneNum = makeString();

    num++;

    return phoneBook;
}

void updatePhoneBook(PhoneBook *phoneBook)
{
    int no;
    printPhoneBook(phoneBook);
    puts("");
    printf("input no for update => ");
    scanf("%d", &no);
    getchar();

    if(no < 0 || no > num)
    {
        printf("[%d] is wrong number\n", no);
        return;
    }

    //전화번호만 바뀐 경우임
    //free(phoneBook[no-1].name);
    free(phoneBook[no-1].phoneNum);

    //printf("input name for update => ");
    //phoneBook[no-1].name = makeString();

    printf("input phone number for update => ");
    phoneBook[no-1].phoneNum = makeString();

}

PhoneBook *deletePhoneBook(PhoneBook *phoneBook)
{
    int no, i;
    printPhoneBook(phoneBook);
    puts("");

    printf("input no for delete => ");
    scanf("%d", &no);
    getchar();

    if(no < 0 || no > num)
    {
        printf("[%d] is wrong number\n", no);
        return;
    }

    printf("Do you wanna delete [%s]'s phone number?", phoneBook[no-1].name);
    char ch = getchar();
    if(ch == 'Y' || ch == 'y')
    {
        free(phoneBook[no-1].name);
        free(phoneBook[no-1].phoneNum);

        for(i=no; i<num; i++)
        {
            phoneBook[i-1] = phoneBook[i];
        }

        num--;

        phoneBook = (PhoneBook *)realloc(phoneBook, num * sizeof(PhoneBook));
        if(phoneBook == NULL)
        {
            puts("memory allocation error!!");
            exit(1);
        }
    }
    return phoneBook;
}

void savePhoneBook(PhoneBook *phoneBook)
{
    int i;

    FILE *ofp = fopen("phonebook.txt", "w");
    if(ofp == NULL)
    {
        puts("file open error!!");
        exit(1);
    }

    fprintf(ofp, "%d\n", num);
    for(i=0; i<num; i++)
    {
        fprintf(ofp, "%s\n%s\n", phoneBook[i].name, phoneBook[i].phoneNum);
    }

    fclose(ofp);
}

void freePhoneBook(PhoneBook *phoneBook)
{
    int i;

    for(i=0; i<num; i++)
    {
        free(phoneBook[i].name);
        free(phoneBook[i].phoneNum);
    }

    free(phoneBook);
}

char *makeString()
{
    char temp[100];
    fgets(temp, sizeof(temp), stdin);
    temp[strlen(temp)-1] = '\0';

    char *p = (char *)malloc(strlen(temp) + 1);
    strcpy(p, temp);

    return p;
}
