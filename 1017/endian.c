#include <stdio.h>

int main()
{
    int num = 10;     // 00000000 00000000 00000000 00001010
    int i;
    char *p = NULL;

    p = (char *)&num;

    // Little Endian 이므로 LSB가 먼저 출력됨
    // 00001010 00000000 00000000 00000000
    for(i=0; i<4; i++)
    {
        printf("[%p] %d ", p+i, p[i]);
    }
    printf("\n");

    // 00000000 00000000 00000000 00001010
    for(i=3; i>=0; i--)
    {
        printf("[%p] %d ", p+i, p[i]);
    }

    return 0;
}
