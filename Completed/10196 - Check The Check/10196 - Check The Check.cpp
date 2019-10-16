#include <iostream>
#include <vector>

using namespace std;

char board[8][8];

bool isValid(int i,int j)
{
    if(i >= 0 && j >= 0 && i < 8 && j < 8)
        return true;
    return false;
}
bool isCheckedByPawn(int i,int j,bool isWhite);
bool isCheckedByBishopOrQueen(int i,int j,bool isWhite);
bool isCheckedByRockOrQueen(int i,int j,bool isWhite);
bool isCheckedByKnight(int i,int j,bool isWhite);
bool isKingInCheck(int i,int j,bool isWhite);

int main()
{
    int gameCount = 1;
    //vector<char> resultSet;
    while(true)
    {
        bool validBoard = false;
        int bki = -1,bkj = -1,wki = -1,wkj = -1;
        for(int i=0;i<8;i++)
        {
            for(int j=0;j<8;j++)
            {
                cin >> board[i][j];
                if(board[i][j] != '.')
                {
                    validBoard = true;
                    if(board[i][j] == 'k')
                    {
                        bki = i;
                        bkj = j;
                    }
                    else if(board[i][j] == 'K')
                    {
                        wki = i;
                        wkj = j;
                    }
                }

            }
        }

        if(!validBoard)
            break;
        char checked = '.';
        if(isKingInCheck(bki,bkj,false))
            checked = 'b';
        else if(isKingInCheck(wki,wkj,true))
            checked = 'B';

        //resultSet.push_back(checked);
        cout << "Game #" << gameCount++;
        switch(checked)
        {
            case '.':
                cout << ": no king is in check." << endl;
                break;
            case 'b':
                cout << ": black king is in check." << endl;
                break;
            case 'B':
                cout << ": white king is in check." << endl;
                break;
        }
    }
//    for(int i=0;i<resultSet.size();i++)
//    {
//        cout << "Game #" << (i + 1);
//        switch(resultSet[i])
//        {
//            case '.':
//                cout << ": no king is in check." << endl;
//                break;
//            case 'b':
//                cout << ": black king is in check." << endl;
//                break;
//            case 'B':
//                cout << ": white king is in check." << endl;
//                break;
//        }
//    }
    return 0;
}

bool isKingInCheck(int i,int j,bool isWhite)
{
    if(isCheckedByPawn(i,j,isWhite))
        return true;
    else if(isCheckedByBishopOrQueen(i,j,isWhite))
        return true;
    else if(isCheckedByRockOrQueen(i,j,isWhite))
        return true;
    else if(isCheckedByKnight(i,j,isWhite))
        return true;
    return false;

}
bool isCheckedByPawn(int i,int j,bool isWhite)
{
    if(isWhite)
    {
        if(isValid(i-1,j-1) && board[i-1][j-1] == 'p')
            return true;
        else if(isValid(i-1,j+1) && board[i-1][j+1] == 'p')
            return true;
    }
    else
    {
        if(isValid(i+1,j-1) && board[i+1][j-1] == 'P')
            return true;
        else if(isValid(i+1,j+1) && board[i+1][j+1] == 'P')
            return true;
    }
    return false;
}

bool isCheckedByBishopOrQueen(int i,int j,bool isWhite)
{

    int a = i - 1,b = j - 1;
    while(a >= 0 && b >= 0)
    {
        if(board[a][b] != '.')
        {
            if(isWhite && (board[a][b] == 'b' || board[a][b] == 'q'))
                return true;
            else if(!isWhite && (board[a][b] == 'B' || board[a][b] == 'Q'))
                return true;
            break;
        }
        a--;
        b--;
    }
    a = i - 1,b = j + 1;
    while(a >= 0 && b < 8)
    {
        if(board[a][b] != '.')
        {
            if(isWhite && (board[a][b] == 'b' || board[a][b] == 'q'))
                return true;
            else if(!isWhite && (board[a][b] == 'B' || board[a][b] == 'Q'))
                return true;
            break;
        }
        a--;
        b++;
    }
    a = i + 1,b = j - 1;
    while(a < 8 && b >= 0)
    {
        if(board[a][b] != '.')
        {
            if(isWhite && (board[a][b] == 'b' || board[a][b] == 'q'))
                return true;
            else if(!isWhite && (board[a][b] == 'B' || board[a][b] == 'Q'))
                return true;
            break;
        }
        a++;
        b--;
    }
    a = i + 1,b = j + 1;
    while(a < 8 && b < 8)
    {
        //cout << "isWhite: " << isWhite << " a: " << a << " b: " << b << " borad: " << board[a][b] << endl;
        if(board[a][b] != '.')
        {
            if(isWhite && (board[a][b] == 'b' || board[a][b] == 'q'))
                return true;
            else if(!isWhite && (board[a][b] == 'B' || board[a][b] == 'Q'))
                return true;
            break;
        }
        a++;
        b++;
    }
    return false;
}
bool isCheckedByRockOrQueen(int i,int j,bool isWhite)
{

    int a = i,b = j - 1;
    while(b >= 0)
    {
        if(board[a][b] != '.')
        {
            if(isWhite && (board[a][b] == 'r' || board[a][b] == 'q'))
                return true;
            else if(!isWhite && (board[a][b] == 'R' || board[a][b] == 'Q'))
                return true;
            break;
        }
        b--;
    }
    a = i,b = j + 1;
    while(b < 8)
    {
        if(board[a][b] != '.')
        {
            if(isWhite && (board[a][b] == 'r' || board[a][b] == 'q'))
                return true;
            else if(!isWhite && (board[a][b] == 'R' || board[a][b] == 'Q'))
                return true;
            break;
        }
        b++;
    }
    a = i + 1,b = j;
    while(a < 8)
    {
        if(board[a][b] != '.')
        {
            if(isWhite && (board[a][b] == 'r' || board[a][b] == 'q'))
                return true;
            else if(!isWhite && (board[a][b] == 'R' || board[a][b] == 'Q'))
                return true;
            break;
        }
        a++;
    }
    a = i - 1,b = j;
    while(a >= 0)
    {
        if(board[a][b] != '.')
        {
            if(isWhite && (board[a][b] == 'r' || board[a][b] == 'q'))
                return true;
            else if(!isWhite && (board[a][b] == 'R' || board[a][b] == 'Q'))
                return true;
            break;
        }
        a--;
    }
    return false;
}
bool isCheckedByKnight(int i,int j,bool isWhite)
{
    int a = i - 2, b = j -1;
    if(isValid(a,b))
    {
        if(isWhite && board[a][b] == 'n')
            return true;
        else if(!isWhite && board[a][b] == 'N')
            return true;
    }
    a = i - 2;
    b = j + 1;
    if(isValid(a,b))
    {
        if(isWhite && board[a][b] == 'n')
            return true;
        else if(!isWhite && board[a][b] == 'N')
            return true;
    }
    a = i - 1;
    b = j + 2;
    if(isValid(a,b))
    {
        if(isWhite && board[a][b] == 'n')
            return true;
        else if(!isWhite && board[a][b] == 'N')
            return true;
    }
    a = i + 1;
    b = j + 2;
    if(isValid(a,b))
    {
        if(isWhite && board[a][b] == 'n')
            return true;
        else if(!isWhite && board[a][b] == 'N')
            return true;
    }
    a = i + 2;
    b = j + 1;
    if(isValid(a,b))
    {
        if(isWhite && board[a][b] == 'n')
            return true;
        else if(!isWhite && board[a][b] == 'N')
            return true;
    }
    a = i + 2;
    b = j - 1;
    if(isValid(a,b))
    {
        if(isWhite && board[a][b] == 'n')
            return true;
        else if(!isWhite && board[a][b] == 'N')
            return true;
    }
    a = i + 1;
    b = j - 2;
    if(isValid(a,b))
    {
        if(isWhite && board[a][b] == 'n')
            return true;
        else if(!isWhite && board[a][b] == 'N')
            return true;
    }
    a = i - 1;
    b = j - 2;
    if(isValid(a,b))
    {
        if(isWhite && board[a][b] == 'n')
            return true;
        else if(!isWhite && board[a][b] == 'N')
            return true;
    }

    return false;
}

