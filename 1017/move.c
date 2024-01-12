#include <stdio.h>
#include <windows.h>

int main()
{
    char msg[] = "I Love You, You Love me~~";
    int i, j;
    int len = strlen(msg);

    while(1)
    {
        for(i=0; i<len; i++)
        {
            printf("%s", msg+i);
            for(j=0; j<i; j++)
                printf("%c", msg[j]);
            Sleep(1000);
            system("cls");
        }
    }

    /*
    #include <unistd.h>
    usleep(1000000);
    system("clear");
    */

    return 0;
}
