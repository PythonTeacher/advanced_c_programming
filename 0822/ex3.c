#include <stdio.h>
#include <string.h>

int main()
{
    char str[100];
    char copy[100];
    int len, i, j=0;

    printf("문자열 입력 : ");
    gets(str);

    len = strlen(str);

    /*for(i=0, j=len-1; i<len/2; i++, j--)
    {
        if(str[i] != str[j])
        {
               printf("%s는 회문이 아닙니다!!\n", str);
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
        printf("%s는 회문입니다!!\n", str);
    else
        printf("%s는 회문이 아닙니다!!\n", str);

	return 0;
}
