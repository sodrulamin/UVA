#include <iostream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

vector<string> roomDesign;
bool visited[30][80];

bool allDash(string str)
{
    bool result = true;
    for(int i=0;i<str.length();i++)
    {
        if(str[i] != '_')
        {
            result = false;
            break;
        }
    }
    return result;
}

void paintRecursive(int i, int j)
{
    roomDesign[i][j] = '#';

    ///row - 1 left, middle and right column
    if(i > 0)
    {
        if(j > 0 && !visited[i - 1][j - 1] && roomDesign[i - 1][j - 1] == ' ')
        {
            visited[i - 1][j - 1] = true;
            paintRecursive(i - 1, j - 1);
        }
        if(!visited[i - 1][j] && roomDesign[i - 1][j] == ' ')
        {
            visited[i - 1][j] = true;
            paintRecursive(i - 1, j);
        }
        if(j < roomDesign[i].length() - 1 && !visited[i - 1][j + 1] && roomDesign[i - 1][j + 1] == ' ')
        {
            visited[i - 1][j + 1] = true;
            paintRecursive(i - 1, j + 1);
        }
    }

    ///same row left and right column
    if(j > 0 && !visited[i][j - 1] && roomDesign[i][j - 1] == ' ')
    {
        visited[i][j - 1] = true;
        paintRecursive(i, j - 1);
    }
    if(j < roomDesign[i].length() - 1 && !visited[i][j + 1] && roomDesign[i][j + 1] == ' ')
    {
        visited[i][j + 1] = true;
        paintRecursive(i, j + 1);
    }

    ///row + 1 left, middle and right column
    if(i < roomDesign.size() - 1)
    {
        if(j > 0 && !visited[i + 1][j - 1] && roomDesign[i + 1][j - 1] == ' ')
        {
            visited[i + 1][j - 1] = true;
            paintRecursive(i + 1, j - 1);
        }
        if(!visited[i + 1][j] && roomDesign[i + 1][j] == ' ')
        {
            visited[i + 1][j] = true;
            paintRecursive(i + 1, j);
        }
        if(j < roomDesign[i].length() - 1 && !visited[i + 1][j + 1] && roomDesign[i + 1][j + 1] == ' ')
        {
            visited[i + 1][j + 1] = true;
            paintRecursive(i + 1, j + 1);
        }
    }
}
void printMaze()
{
    for(int i=0;i<roomDesign.size();i++)
    {
        cout << roomDesign[i] << endl;
    }
}
void initVisited()
{
    for(int i=0;i<30;i++)
        for(int j=0;j<80;j++)
            visited[i][j] = false;
}

int main()
{
    //vector<string> resultSet;
    string line;
    int t;
    stringstream ss;
    getline(cin, line);
    ss << line;
    ss >> t;
    while(t > 0)
    {
        initVisited();
        roomDesign.clear();
        int starti = -1,startj = -1;
        line = "0000";
        while(!allDash(line))
        {
            getline(cin, line);
            for(int i=0;starti == -1 && i<line.length();i++)
            {
                if(line[i] == '*')
                {
                    starti = roomDesign.size();
                    startj = i;
                    break;
                }
            }
            roomDesign.push_back(line);
        }
        visited[starti][startj] = true;
        paintRecursive(starti, startj);
        printMaze();

//        for(int i=0;i<roomDesign.size();i++)
//            resultSet.push_back(roomDesign[i]);

        t--;
    }

//    cout << endl << "Printing All:\n";
//    for(int i=0;i<resultSet.size();i++)
//    {
//        cout << resultSet[i] << endl;
//    }
    return 0;
}
