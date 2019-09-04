#include <iostream>
#include <cstdio>
#define NEGATIVE_MAX -999999999
#define ARRAY_SIZE 10000

using namespace std;


int n;
int numbers[ARRAY_SIZE];
int sumhistory[ARRAY_SIZE][ARRAY_SIZE];
int maxSum;

void constructor ()
{
    maxSum = NEGATIVE_MAX;

    for ( int i = 0; i < n; i++ ) {
        for(int j = 0; j <= n; j++){
           sumhistory[i][j] = NEGATIVE_MAX;
        }
    }
}
/**void printnumbers(){
    printf("\n\nInput numbers:\n");
    for(int i=0;i<n;i++){
        printf(" %d",numbers[i]);
    }
    printf("\n\n");
}*/
void takeInput(){
    for(int i=0;i<n;i++){
        cin >> numbers[i];
        sumhistory[i][1] = numbers[i];
    }
}
int getsum(int index_i, int rowsize){
    //cout << "index: " << index_i << " rowSize: " << rowsize << " sumHistory: " << sumhistory[index_i][rowsize] << endl;
    if(sumhistory[index_i][rowsize] > NEGATIVE_MAX){
        return sumhistory[index_i][rowsize];
    }else if(rowsize == 2){
        sumhistory[index_i][2] = numbers[index_i] + numbers[index_i + 1];
        return sumhistory[index_i][2];
    }else if(rowsize > 2)
    {
        int halfrow = rowsize / 2;
        int restrow = rowsize - halfrow;
        int sum1 = getsum(index_i,halfrow);
        sumhistory[index_i][halfrow] =  sum1;
        int sum2 = getsum(index_i + halfrow,restrow);
        sumhistory[index_i + halfrow][restrow] = sum2;
        return sum1 + sum2;
    }
}
void process(){
    for(int i=0;i<n;i++){
        //for(int j=0;j<n;j++){
            for(int rowsize = 1; rowsize <= n - i; rowsize++){
                //for(int colsize = 1; colsize <= n; colsize++){
                    int sum = getsum(i,rowsize);
                    if(sum > maxSum)
                        maxSum = sum;
                //}
            }
        //}
    }
}

int main(){
    while ( cin >> n ) {
        if(n <= 0)
            break;
        constructor ();
        takeInput();
        /**printnumbers();*/
        process();
        if(maxSum > 0)
            cout << "The maximum winning streak is " << maxSum << ".\n";
        else
            cout << "Losing streak.\n";
    }

    return 0;
}



