#include <iostream>
#include <sstream>
#include <vector>

using namespace std;
int maxSequence;

vector<int> extractIntegerWords(string str)
{
    stringstream ss;

    /* Storing the whole string into string stream */
    ss << str;

    /* Running loop till the end of the stream */
    string temp;
    int found;
    vector<int> result;
    while (!ss.eof()) {

        /* extracting word by word from stream */
        ss >> temp;

        /* Checking the given word is integer or not */
        if (stringstream(temp) >> found)
            result.push_back(found);

        /* To save from space at the end of string */
        temp = "";
    }
    return result;
}
void searchRecursive(int index,int n,vector<int> taken,vector<int> actual, vector<int> input)
{
    if(index >= n)
    {
        int actualIndex = 0;
        for(int i=0;i<taken.size();i++)
        {
            bool found = false;
            while(actualIndex < actual.size())
            {

                if(actual[actualIndex] == input[taken[i]])
                {
                    actualIndex++;
                    found = true;
                    break;
                }
                actualIndex++;
            }
            if(!found)
                return;
        }
        if(maxSequence < taken.size())
            maxSequence = taken.size();
        return;
    }

    searchRecursive(index + 1,n,taken,actual,input);

    taken.push_back(index);
    searchRecursive(index + 1,n,taken,actual,input);
}

// Driver code
int main()
{
    string str;
    int n;
    vector<int> actualSequence;
    while(getline(cin,str))
    {
        maxSequence = 0;
        vector<int> inputSequence = extractIntegerWords(str);
        if(inputSequence.size() == 1)
        {
            /*if(inputSequence[0] == 0)
                break;*/
            n = inputSequence[0];
            getline(cin,str);
            actualSequence = extractIntegerWords(str);

        }
        else
        {
            ///now do your coding
            vector<int> takenIndex;
            searchRecursive(0,n,takenIndex,actualSequence,inputSequence);
            /*cout << "Actual: ";
            for(int i=0;i<actualSequence.size();i++)
                cout << actualSequence[i] << " ";
            cout << "\nInput: ";
            for(int i=0;i<inputSequence.size();i++)
                cout << inputSequence[i] << " ";*/
            cout << maxSequence << endl;
        }
    }

    return 0;
}
