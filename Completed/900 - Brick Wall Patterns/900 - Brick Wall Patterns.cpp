#include <cstdio>

int main()
{
    int n = 50;
    unsigned long long int series[50];
    series[0] = 1;
    series[1] = 2;
    //printf("%llu\n%llu\n",a,b);
    for(int i = 2;i<50;i++)
    {
        series[i] = series[i - 1] + series[i - 2];
        //printf("%llu\n",series[i]);
    }
    while(scanf("%d",&n) > 0)
    {
        //printf("Hello\n");
        if(n <= 0)
            break;
        printf("%llu\n",series[n - 1]);
    }
    return 0;
}
