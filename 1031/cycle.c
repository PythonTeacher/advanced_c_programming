/**
 학습 내용 : 배열과 포인터
**/
#include<stdio.h>

void cycle(int *pa);

#define SIZE    5

int main(){
    int arr[SIZE] = {1, 6, 3, 7, 9};
    int i, j;

    for(i=0; i<SIZE; i++)
        printf("%d ", arr[i]);
    puts("");

    for(i=0; i<SIZE; i++)
    {
        cycle(arr);
        for(j=0; j<SIZE; j++)
            printf("%d ", arr[j]);
        puts("");
    }

    return 0;
}

void cycle(int *pa){
    int i;
    int temp = pa[SIZE-1];
    for(i=SIZE-2; i>=0; i--)
    {
        pa[i+1] = pa[i];
    }
    pa[0] = temp;
}
