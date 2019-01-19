#include<stdio.h>

int arr[999], N, total, sub_sum;

int main()
{
    int i, j;
    scanf("%d", &N);
    for (i = 0; i<N; i++)
    {
        scanf("%d", &arr[i]);
        total += arr[i];
    }
    total /= 2;
    for (i = 0; i<N; i++)
    {
        sub_sum = 0;
        for (j=0; j<N; j+=2)
            sub_sum += arr[(i + j) % N];
        printf("%d\n", sub_sum - total);
    }
    return 0;
}
