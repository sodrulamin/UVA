#include <iostream>
#include <vector>

using namespace std;


int main()
{
    int n,r;
    //vector<int> valueN;
    //vector<int> valueR;
    //vector<int> result;
    while(cin >> n >> r)
    {
        if(n == 0 && r == 0)
        {
            break;
        }
        vector<int> upper;
        vector<int> lower;
        int nMinusR = n - r;
        int maxDivider = nMinusR;
        int minDivider = r;
        if(maxDivider < r){
            maxDivider = r;
            minDivider = nMinusR;
        }
        //cout << n  << " max: " << maxDivider << " min: " << minDivider << endl;
        for(int i=n;i>maxDivider;i--)
        {
            upper.push_back(i);
        }
        for(int i=minDivider;i > 1;i--)
        {
            lower.push_back(i);
        }
        /*cout << "upper: ";
        for(int i=0;i<upper.size();i++)
        {
            cout << upper[i] << " ";
        }
        cout << endl << "lower: ";
        for(int i=0;i<lower.size();i++)
        {
            cout << lower[i] << " ";
        }
        cout << endl;*/
        //upper.erase(std::remove(upper.begin(), upper.end(), 0), upper.end());

        int currentDevider = 100;
        while(currentDevider > 1)
        {
            bool devided = true;
            int upperIndex = -1;
            int lowerIndex = -1;
            for(int i=0;i<upper.size();i++)
            {
                if(upper[i] % currentDevider == 0)
                {
                    upperIndex = i;
                    break;
                }
            }
            for(int i=0;i<lower.size();i++)
            {
                if(lower[i] % currentDevider == 0)
                {
                    lowerIndex = i;
                    break;
                }
            }
            if(lowerIndex >= 0 && upperIndex >= 0)
            {
                upper[upperIndex] /= currentDevider;
                lower[lowerIndex] /= currentDevider;
                if(upper[upperIndex] == 1)
                    upper.erase(upper.begin() + upperIndex);
                if(lower[lowerIndex] == 1)
                    lower.erase(lower.begin() + lowerIndex);
            }
            else
                currentDevider--;
        }

        long upperValue = 1;
        long lowerValue = 1;
        for(int i=0;i<upper.size();i++)
        {
            upperValue = upperValue * upper[i];
        }
        /*for(int i=0;i<lower.size();i++)
        {
            lowerValue = lowerValue * lower[i];
        }*/
        //cout << "upperValue: " << upperValue << " lowerValue: " << lowerValue << endl;
        //upperValue = upperValue / lowerValue;
        cout << n << " things taken " << r << " at a time is "<< upperValue << " exactly." << endl;
        //valueN.push_back(n);
        //valueR.push_back(r);
        //result.push_back(upperValue);

    }
    /*for(int i=0;i<valueN.size();i++)
    {
        cout << valueN[i] << " things taken " << valueR[i] << " at a time is "<< result[i] << " exactly." << endl;
    }*/
    return 0;
}
