#include <stdio.h>
#include <string.h>

int main()
{
    char str[100];
    char copy[100];
    int len, i, j=0;

    printf("���ڿ� �Է� : ");
    gets(str);

    len = strlen(str);

    /*for(i=0, j=len-1; i<len/2; i++, j--)
    {
        if(str[i] != str[j])
        {
               printf("%s�� ȸ���� �ƴմϴ�!!\n", str);
               return 0;
        }
    }
     */
     for(i=len-1; i>=0; i--)
     {
         copy[j++] = str[i];
     }
     copy[j] = '\0';

     if(strcmp(str, copy) == 0)
        printf("%s�� ȸ���Դϴ�!!\n", str);
    else
        printf("%s�� ȸ���� �ƴմϴ�!!\n", str);

	return 0;
}
