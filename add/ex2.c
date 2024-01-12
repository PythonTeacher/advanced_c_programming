#include <stdio.h>

int main()
{
    int kor, eng, mat, tot;

    printf("¼¼ °ú¸ñ Á¡¼ö : ");
    scanf("%d %d %d", &kor, &eng, &mat);

    tot = kor + eng + mat;

    printf("ÃÑÁ¡ : %dÁ¡\n", tot);
    printf("Æò±Õ : %.1lfÁ¡", tot / 3.0);

    return 0;
}
