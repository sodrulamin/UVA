#include <iostream>
#include <vector>

#define N 25

using namespace std;

bool board[N][N],visited[N][N];

void visit(int i,int j,int n)
{
    //cout << i << " " << j << " " << n << endl;


    visited[i][j] = true;


    if(i > 0 && j > 0 && board[i - 1][j - 1] && !visited[i - 1][j - 1])
    {
        visit(i - 1, j - 1, n);
    }
    if(i > 0 && board[i - 1][j] && !visited[i - 1][j])
    {
        visit(i - 1, j, n);
    }
    if(i > 0 && j < n - 1 && board[i - 1][j + 1] && !visited[i - 1][j + 1])
    {
        visit(i - 1, j + 1, n);
    }
    if(j > 0 && board[i][j - 1] && !visited[i][j - 1])
    {
        visit(i, j - 1, n);
    }
    if(j < n - 1 && board[i][j + 1] && !visited[i][j + 1])
    {
        visit(i, j + 1, n);
    }
    if(i < n - 1 && j > 0 && board[i + 1][j - 1] && !visited[i + 1][j - 1])
    {
        visit(i + 1, j - 1, n);
    }
    if(i < n - 1 && board[i + 1][j] && !visited[i + 1][j])
    {
        visit(i + 1, j, n);
    }
    if(i < n - 1 && j < n - 1 && board[i + 1][j + 1] && !visited[i + 1][j + 1])
    {
        visit(i + 1, j + 1, n);
    }
}

int main()
{
    //vector<int> resultSet;
    int n,imageCount = 1;
    while(cin >> n)
    {
//        if(n == 0)
//            break;
        char ch;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                cin >> ch;
                board[i][j] = (ch == '1');
                visited[i][j] = false;
            }
        }
        int count = 0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++){
                //cout << "Now Checking " << i << " boardValue: " << board[0][1] << endl;
                if(board[i][j] && !visited[i][j])
                {
                    count++;
                    visit(i,j,n);
                }
            }
        }
        cout << "Image number " << imageCount++ << " contains " << count << " war eagles." << endl;
        //resultSet.push_back(count);
    }
//    for(int i=0;i<resultSet.size();i++)
//    {
//        cout << "Image number " << (i + 1) << " contains " << resultSet[i] << " war eagles." << endl;
//    }

    return 0;
}

