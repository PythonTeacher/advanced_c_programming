#include <stdio.h>

int main()
{
    int i, sum=0;
    for(i = 1; i <= 20; i++)
    {
        if(i % 3 == 0) continue;
        sum += i;
        if(sum > 15) break;
        printf("%d, %d\n", i, sum);
    }
    return 0;
}
