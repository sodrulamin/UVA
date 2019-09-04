#include <iostream>
#include <cstdio>
#define NEGATIVE_MAX -999999999
#define ARRAY_SIZE 110

using namespace std;


int n;
int numbers[ARRAY_SIZE][ARRAY_SIZE];
int sumhistory[ARRAY_SIZE][ARRAY_SIZE][ARRAY_SIZE][ARRAY_SIZE];
int maxSum;

void constructor ()
{
    maxSum = NEGATIVE_MAX;
    for ( int i = 0; i < n; i++ ) {
        for(int j = 0; j < n; j++){
            numbers[i][j] = -128;
        }
    }
    for ( int i = 0; i < n; i++ ) {
        for(int j = 0; j < n; j++){
            for ( int k = 0; k <= n; k++ ) {
                for(int l = 0; l <= n; l++){
                    sumhistory[i][j][k][l] = NEGATIVE_MAX;
                }
            }
        }
    }
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
        for(int j=0;j<n;j++){
            cin >> numbers[i][j];
            sumhistory[i][j][1][1] = numbers[i][j];
        }
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
    if(!valid(index_i,index_j,rowsize,colsize))
        return NEGATIVE_MAX;
    else if(sumhistory[index_i][index_j][rowsize][colsize] > NEGATIVE_MAX){
        /**printf("i: %d j: %d row: %d col: %d sum: %d\n",index_i,index_j,rowsize,colsize,sumhistory[index_i][index_j][rowsize][colsize]);*/
        return sumhistory[index_i][index_j][rowsize][colsize];
    }
    else{
        if(rowsize > 1)
        {
            int halfrow = rowsize / 2;
            int restrow = rowsize - halfrow;
            int sum1 = getsum(index_i,index_j,halfrow,colsize);
            sumhistory[index_i][index_j][halfrow][colsize] =  sum1;
            int sum2 = getsum(index_i + halfrow,index_j,restrow,colsize);
            sumhistory[index_i + halfrow][index_j][restrow][colsize] = sum2;
            return sum1 + sum2;
            /*sumhistory[index_i][index_j][rowsize - 1][colsize] = getsum(index_i,index_j,rowsize - 1,colsize);
            sumhistory[index_i + 1][index_j][1][colsize] = getsum(index_i + 1,index_j,1,colsize);
            return sumhistory[index_i][index_j][rowsize - 1][colsize] + sumhistory[index_i + 1][index_j][1][colsize];*/
        }
        else if(colsize > 1)
        {
            int halfcol = colsize / 2;
            int restcol = colsize - halfcol;
            int sum1 = getsum(index_i,index_j,rowsize,halfcol);
            sumhistory[index_i][index_j][colsize][halfcol] =  sum1;
            int sum2 = getsum(index_i,index_j + halfcol,rowsize,restcol);
            sumhistory[index_i][index_j + halfcol][rowsize][restcol] = sum2;
            return sum1 + sum2;
            /*sumhistory[index_i][index_j][rowsize][colsize - 1] = getsum(index_i,index_j,rowsize,colsize - 1);
            sumhistory[index_i][index_j + 1][rowsize][1] = getsum(index_i,index_j + 1,rowsize,1);
            return sumhistory[index_i][index_j][rowsize][colsize - 1] + sumhistory[index_i][index_j + 1][rowsize][1];*/
        }
    }
}
void process(){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            for(int rowsize = 1; rowsize <= n; rowsize++){
                for(int colsize = 1; colsize <= n; colsize++){
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


