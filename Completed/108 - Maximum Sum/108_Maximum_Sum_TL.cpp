#include <iostream>
#include <cstdio>
#define NEGATIVE_MAX -999999999

using namespace std;


int n;
int numbers[110][110];
int sumhistory[110][110][110][110];
int maxSum;

void constructor ()
{
    maxSum = NEGATIVE_MAX;
    for ( int i = 0; i < n; i++ ) {
        for(int j = 0; j < n; j++){
            numbers[i][j] = -128;
        }
    }
    /**for ( int i = 0; i < n; i++ ) {
        for(int j = 0; j < n; j++){
            for ( int k = 0; k < n; k++ ) {
                for(int l = 0; l < n; l++){
                    sumhistory[i][j][k][l] = -128;
                }
            }
        }
    }*/
}
void printnumbers(){
    printf("\n\nInput numbers:\n");
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            printf(" %d",numbers[i][j]);
        }
        printf("\n");
    }
    printf("\n\n");
}
void takeInput(){
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            cin >> numbers[i][j];
}
bool valid(int i, int j, int rowsize, int colsize){
    /**if(i < 0 || j < 0 || rowsize <= 0 || colsize <= 0)
        return false;
    else */if(i + rowsize > n)
        return false;
    else if(j + colsize > n)
        return false;
    return true;
}
int getsum(int index_i, int index_j, int rowsize, int colsize){
    int sum = 0;
    for(int i=0;i<rowsize;i++){
        for(int j=0;j<colsize;j++){
            sum += numbers[i + index_i][j + index_j];
        }
    }
    /**printf("i: %d j: %d row: %d col: %d sum: %d\n",index_i,index_j,rowsize,colsize,sum);*/
    return sum;
}
void process(){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            for(int rowsize = 1; rowsize <= n; rowsize++){
                for(int colsize = 1; colsize <= n; colsize++){
                    if(!valid(i,j,rowsize,colsize))
                        continue;
                    int sum = getsum(i,j,rowsize,colsize);
                    if(sum > maxSum)
                        maxSum = sum;
                }
            }
        }
    }
}

int main(){
    while ( cin >> n ) {
        if(n <= 0)
            continue;
        constructor ();
        takeInput();
        /**printnumbers();*/
        process();

        cout << maxSum << "\n";
    }

    return 0;
}

