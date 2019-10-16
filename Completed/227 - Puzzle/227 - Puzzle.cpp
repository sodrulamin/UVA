#include <iostream>
#include <string>
#include <vector>

using namespace std;

char board[5][5];
int spacei = -1,spacej = -1;
//vector<char> resultSet;

void printBoard()
{
    for(int i=0;i<5;i++)
    {
        for(int j=0;j<5;j++)
        {
            if(j > 0)
                cout << " ";
            cout << board[i][j];
            //resultSet.push_back(board[i][j]);
        }
        cout << endl;
    }
}
bool moveSquare(char ch)
{
    switch(ch)
    {
        case 'A':
            if(spacei <= 0)
                return false;
            board[spacei][spacej] = board[spacei - 1][spacej];
            spacei--;
            board[spacei][spacej] = ' ';
            break;
        case 'B':
            if(spacei >= 4)
                return false;
            board[spacei][spacej] = board[spacei + 1][spacej];
            spacei++;
            board[spacei][spacej] = ' ';
            break;
        case 'R':
            if(spacej >= 4)
                return false;
            board[spacei][spacej] = board[spacei][spacej + 1];
            spacej++;
            board[spacei][spacej] = ' ';
            break;
        case 'L':
            if(spacej <= 0)
                return false;
            board[spacei][spacej] = board[spacei][spacej - 1];
            spacej--;
            board[spacei][spacej] = ' ';
            break;
        default:
            return false;
    }
    return true;
}

int main()
{
    string str;
    int index = 0;

    bool boardValid = true;
    int puzzleCount = 1;
    while(getline(cin,str))
    {
        if(str == "Z")
            break;
        for(int i=0;i<5;i++){
            board[0][i] = str[i];
            if(str[i] == ' ')
            {
                spacei = 0;
                spacej = i;
            }
        }
        for(int i=1;i<5;i++)
        {
            getline(cin, str);
            for(int j=0;j<5;j++){
                board[i][j] = str[j];
                if(str[j] == ' ')
                {
                    spacei = i;
                    spacej = j;
                }
            }
        }
        bool endMove = false;
        while(!endMove){
            getline(cin,str);
            int i=0;
            while(i<str.length())
            {
                if(str[i] =='0')
                {
                    //if(index > 24)
                    {
                        if(puzzleCount > 1)
                            cout << endl;
                        cout << "Puzzle #" << puzzleCount++ << ":" << endl;
                        if(boardValid)
                            printBoard();
                        else
                        {
                            //resultSet.push_back('0');
                            cout << "This puzzle has no final configuration." << endl;
                        }
                    }
                    boardValid = true;
                    index = 0;
                    spacei = -1;
                    spacej = -1;
                    endMove = true;
                    break;
                }
    //            else if(index < 25)
    //            {
    //                board[index / 5][index % 5] = str[i];
    //                if(str[i] == ' ')
    //                {
    //                    spacei = index / 5;
    //                    spacej = index % 5;
    //                }
    //                index++;
    //            }
                else if(boardValid && isalpha(str[i]))
                {
                    boardValid = moveSquare(str[i]);
                }
                i++;
            }
        }
    }
//    int i=0;
//    puzzleCount = 1;
//    while(i < resultSet.size())
//    {
//        if(puzzleCount > 1)
//            cout << endl;
//        cout << "Puzzle #" << puzzleCount++ << ":" << endl;
//        if(resultSet[i] == '0')
//        {
//            i++;
//            cout << "This puzzle has no final configuration." << endl;
//        }
//        else
//        {
//            for(int j=0;j<25;j++)
//            {
//                if(j > 0 && j % 5 == 0)
//                    cout << endl;
//                cout << resultSet[i++] << " ";
//            }
//            cout << endl;
//        }
//    }
    return 0;
}
