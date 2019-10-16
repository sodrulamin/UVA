#include <iostream>
#include <string>
#include <vector>

using namespace std;


int main()
{
    int rCount,pCount,rfpCount = 1;
    //vector<string> resultSet;
    while(cin >> rCount >> pCount)
    {
        if(rCount == 0 && pCount == 0)
            break;
        string str;
        getline(cin,str);
        //cout << "rCount: " << rCount << " pCount: " << pCount << endl;
        for(int i=0;i<rCount;i++){
            getline(cin, str);
            //cout << "i: " << i << " str: " << str << endl;
        }

        //cout << "Requirements reading done\n";

        string proposalName;
        double minPrice = -1,price;
        int rMetCount = 0,maxRmetCount = -1;
        for(int i=0;i<pCount;i++)
        {
            getline(cin,str);
            cin >> price >> rMetCount;

            //cout << "Proposal: " << str << " price: " << price << " rMet: " << rMetCount << endl;
            if(rMetCount > maxRmetCount)
            {
                proposalName = str;
                maxRmetCount = rMetCount;
                minPrice = price;
            }
            else if(rMetCount == maxRmetCount)
            {
                if(price < minPrice)
                {
                    proposalName = str;
                    minPrice = price;
                }
            }
            for(int j=0;j<=rMetCount;j++)
            {
                getline(cin,str);
            }
        }
        if(rfpCount > 1)
            cout << endl;
        cout << "RFP #" << rfpCount << endl << proposalName << "\n";
        //resultSet.push_back(proposalName);

        rfpCount++;
    }
//    for(int i=0;i<resultSet.size();i++)
//    {
//        cout << "RFP #" << (i + 1) << endl << resultSet[i] << "\n";
//    }

    return 0;
}
