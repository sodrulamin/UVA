#include <iostream>
#include <cmath>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

const double PI = atan(1.0) * 4;

int main()
{
    //printf("%.4f",PI);
    int t;
    cin >> t;
    vector<double> resultSet;
    while(t--)
    {
        int n,f,a;
        double volume = 0;
        vector<double> radiusList;
        cin >> n >> f;
        for(int i=0;i<n;i++)
        {
            cin >> a;
//            volume += a * a;
            radiusList.push_back(a * a);
        }
        f++;
        sort(radiusList.begin(), radiusList.end());
        reverse(radiusList.begin(), radiusList.end());
        double cutSize = radiusList[0];
        int cutIndex = 0, totalCutCount = 1, cutCount = 1;

        while(totalCutCount < f)
        {
            cutSize = radiusList[cutIndex] / cutCount;
            totalCutCount = 0;
            for(int i=0;i<radiusList.size();i++)
            {
                double b = (radiusList[i] / cutSize);
                totalCutCount = totalCutCount + b;
                //cout << "Radius: " << radiusList[i] << " size: " << cutSize << " a: " << b << " doubleA: " << (radiusList[i] / cutSize) << " total: " << totalCutCount << endl;
            }

            //cout << "Size: " << cutSize << " index: " << cutIndex << " count: " << cutCount << " total: " << totalCutCount << endl;
            //if(cutIndex < radiusList.size() - 1)


            cutIndex++;
            while(cutIndex < radiusList.size() && radiusList[cutIndex] == radiusList[cutIndex - 1])
                cutIndex++;


//            if(cutIndex == radiusList.size() || ((radiusList[cutIndex] / cutCount) < (radiusList[0] / (cutCount + 1))))
            if(cutIndex == radiusList.size() || cutSize > radiusList[cutIndex])
            {
                cutCount++;
                cutIndex = 0;
            }

        }
        volume = cutSize * PI;
        printf("%.4f\n",volume);
        resultSet.push_back(volume);
    }

    for(int i=0;i<resultSet.size();i++)
    {
        printf("%.4f\n",resultSet[i]);
    }

    return 0;
}
