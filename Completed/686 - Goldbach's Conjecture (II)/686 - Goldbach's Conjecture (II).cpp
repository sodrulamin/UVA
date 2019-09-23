#include <cstdio>
#include <vector>
#include <iostream>

using namespace std;


#define MAX_NUM 32768


vector<int> primeNumbers;

bool isPrime(int n)
{
    int i = 2;
    while(i * i <= n)
    {
        if(n % i == 0)
            return false;
        i++;
    }
    return true;
}
int findRecusive(int leftIndex,int rightIndex,int n)
{
    if(leftIndex <= rightIndex)
    {
        //printf("left: %d right: %d leftprime: %d rightprime: %d\n",leftIndex,rightIndex,primeNumbers[leftIndex],primeNumbers[rightIndex]);
        if(primeNumbers[leftIndex] + primeNumbers[rightIndex] == n)
        {
            leftIndex++;
            rightIndex--;
            return 1 + findRecusive(leftIndex,rightIndex,n);
        }
        else if(primeNumbers[leftIndex] + primeNumbers[rightIndex] > n)
        {
            return findRecusive(leftIndex,rightIndex - 1,n);
        }
        else
        {
            return findRecusive(leftIndex + 1,rightIndex,n);
        }
    }
    return 0;
}

int main()
{
    for(int i = 2;i<= MAX_NUM;i++)
    {
        if(isPrime(i))
        {
            primeNumbers.push_back(i);
        }
    }
    unsigned int n;
    while(scanf("%u",&n))
    {
        if(n == 0)
            break;
        int primeCount = 0;
        while(primeNumbers[primeCount] <= n && primeCount < primeNumbers.size())
        {
            primeCount++;
        }
        int leftIndex = 0,rightIndex = primeCount - 1;
        int foundPair = findRecusive(leftIndex,rightIndex,n);
        printf("%d\n",foundPair);
    }
    return 0;
}
