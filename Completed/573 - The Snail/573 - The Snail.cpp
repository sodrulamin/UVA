#include <iostream>
#include <math.h>

using namespace std;


int main(){
    int h,u,d,f;
    while(cin >> h >> u >> d >> f){
        if(h == 0){
            break;
        }
        bool success = false;
        int dayCount = 0;
        float distanceCovered = u,fatigue = (f * u)/100.0, totalDistance = 0.0;
        //cout << "Day\tI.H\tD.C\tH.A.C\tH.A.S\n";
        while(distanceCovered >= 0){


            if(totalDistance < 0){
                break;
            }
            dayCount++;
            //cout <<  dayCount << "\t" << totalDistance  << "\t" << distanceCovered << "\t" << (totalDistance + distanceCovered) << "\t" << (totalDistance + distanceCovered - d) << endl;
            totalDistance = totalDistance + distanceCovered;
            distanceCovered = distanceCovered - fatigue;
            if(totalDistance > h){
                success = true;
                break;
            }
            totalDistance = totalDistance  - d;
        }
        if(success){
            cout << "success on day " << dayCount << endl;
        }
        else {
            //dayCount = dayCount + ceil(totalDistance) + 1;
            while(totalDistance >= 0){
                totalDistance = totalDistance - d;
                dayCount++;
            }
            //cout << "Celing: " << ceil(totalDistance) << endl;
            cout << "failure on day " << dayCount << endl;
        }
    }
}
