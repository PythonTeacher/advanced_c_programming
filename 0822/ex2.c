#include <stdio.h>
#include <string.h>

int main()
{
    char str[100];
    int len, i;

    printf("���ڿ� �Է� : ");
    gets(str);

    len = strlen(str);  // 5

    //puts(str);  // apple

    for(i=len; i>0; i--)
    {
        str[i] = '\0';
        puts(str);
    }

	return 0;
}
