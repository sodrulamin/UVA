#include <iostream>
#include <vector>

using namespace std;

int coursesTaken[110];
int courseList[110][110];
int courseDetails[110][2];
int courseTakenCount[110];

int main()
{
    int k,m;
    //vector<bool> resultSet;
    while(cin >> k)
    {
        if(k == 0)
            break;
        cin >> m;
        for(int i=0;i<k;i++)
        {
            cin >> coursesTaken[i];
        }
        //cout << "Taken courses input done. Now taking " << m << " catagory details" << endl;
        bool graduated = true;
        for(int i=0;i<m;i++)
        {
            ///Total course count and minimum course count
            cin >> courseDetails[i][0] >> courseDetails[i][1];
            ///Taken course count for i catagory = 0
            courseTakenCount[i] = 0;
            //cout << "Catagory: " << i << " totalCourse: " << courseDetails[i][0] << " minimumCourse: " << courseDetails[i][1] << " courseList: ";
            for(int j=0;j<courseDetails[i][0];j++)
            {
                ///taking courses list input
                cin >> courseList[i][j];
                //cout << courseList[i][j] << " ";
                for(int l=0;l<k;l++)
                {
                    if(coursesTaken[l] == courseList[i][j])
                    {
                        courseTakenCount[i]++;
                        break;
                    }
                }
            }
            //cout << " courseTakenCount: " << courseTakenCount[i] << endl;
            if(courseTakenCount[i] < courseDetails[i][1])
                graduated = false;
        }
        //resultSet.push_back(graduated);
        if(graduated)
        {
            cout << "yes" << endl;
        }
        else
        {
            cout << "no" << endl;
        }
    }
//    for(int i=0;i<resultSet.size();i++)
//    {
//        if(resultSet[i])
//            cout << "yes" << endl;
//        else
//            cout << "no" << endl;
//    }
    return 0;
}
