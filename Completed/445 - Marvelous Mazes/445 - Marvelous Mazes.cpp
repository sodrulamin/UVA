#include <iostream>
#include <queue>
#include <string>

using namespace std;

int main()
{
    string str;
    queue<char> outputQueue;
    //queue<char> resultSet;
    int count=0;
    bool firstMage = true;
    while(getline(cin,str))
    {
        //cout << "Received: " << str << " size: " << str.length() << endl;
        if(str.length() == 0)
        {


                cout << endl;
                //resultSet.push('\n');

            /*while(!outputQueue.empty())
            {
                cout << outputQueue.front();
                //resultSet.push(outputQueue.front());
                outputQueue.pop();
            }*/
            continue;
        }
        else if(str == "-1")
            break;
        for(int i=0;i<str.length();i++)
        {
            if(str[i] == '!')
                //outputQueue.push('\n');
                cout << endl;
            else if(str[i] == 'b')
            {
                while(count > 0)
                {
                    //outputQueue.push(' ');
                    cout << " ";
                    count--;
                }
            }
            else if(str[i] >= '0' && str[i] <= '9')
            {
                count += (str[i] - '0');
            }
            else
            {
                while(count > 0)
                {
                    //outputQueue.push(str[i]);
                    cout << str[i];
                    count--;
                }
            }
        }
        //outputQueue.push('\n');
        cout << endl;
    }

    /*while(!resultSet.empty())
    {
        cout << resultSet.front();
        resultSet.pop();
    }*/
    //cout << endl;
    return 0;
}
