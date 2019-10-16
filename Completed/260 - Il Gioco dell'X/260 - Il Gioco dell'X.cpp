#include <iostream>
#include <vector>

#define N 200

using namespace std;

bool board[N][N],visited[N][N];

bool isBlackWinner(int i,int j,int n)
{
    //cout << i << " " << j << " " << n << endl;
    visited[i][j] = true;
    if(i >= n - 1)
        return true;

    if(i > 0 && j > 0 && board[i - 1][j - 1] && !visited[i - 1][j - 1] && isBlackWinner(i - 1, j - 1, n))
        return true;
    else if(i > 0 && board[i - 1][j] && !visited[i - 1][j] && isBlackWinner(i - 1, j, n))
        return true;
    else if(j > 0 && board[i][j - 1] && !visited[i][j - 1] && isBlackWinner(i, j - 1, n))
        return true;
    else if(j < n - 1 && board[i][j + 1] && !visited[i][j + 1] && isBlackWinner(i, j + 1, n))
        return true;
    else if(board[i + 1][j] && !visited[i + 1][j] && isBlackWinner(i + 1, j, n))
        return true;
    else if(j < n - 1 && board[i + 1][j + 1] && !visited[i + 1][j + 1] && isBlackWinner(i + 1, j + 1, n))
        return true;
    return false;
}

int main()
{
    //vector<bool> resultSet;
    int n,gameCount = 1;
    while(cin >> n)
    {
        if(n == 0)
            break;
        char ch;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                cin >> ch;
                board[i][j] = (ch == 'b');
//                if(ch == 'b')
//                    board[i][j] = true;
//                else
//                    board[i][j] = false;
                visited[i][j] = false;
            }
        }

//        for(int i=0;i<n;i++)
//        {
//            for(int j=0;j<n;j++)
//            {
//                cout << board[i][j] << " ";
//            }
//            cout << endl;
//        }

        bool blackWinner = false;
        for(int i=0;i<n && !blackWinner;i++)
        {
            //cout << "Now Checking " << i << " boardValue: " << board[0][1] << endl;
            if(board[0][i] && !visited[0][i])
            {
                blackWinner = isBlackWinner(0,i,n);
            }
        }
        cout << gameCount++ << " ";
        if(blackWinner)
            cout << "B\n";
        else
            cout << "W\n";
        //resultSet.push_back(blackWinner);
    }
//    for(int i=0;i<resultSet.size();i++)
//    {
//        cout << (i + 1) << " ";
//        if(resultSet[i])
//            cout << "B\n";
//        else
//            cout << "W\n";
//    }

    return 0;
}
