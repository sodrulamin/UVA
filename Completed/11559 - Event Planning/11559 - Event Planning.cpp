#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>

using namespace std;

vector<int> resultSet;

struct Hotel{
    bool eligible;
    int price;
    vector<int> freeBeds;
};

struct ComparePrice {
    bool operator()(Hotel const& h1, Hotel const& h2)
    {
        // return "true" if "p1" is ordered
        // before "p2", for example:
        return h1.price > h2.price;
    }
};

void printResultSet(){
    for(int i=0;i<resultSet.size();i++){
        if(resultSet[i] == -1){
            cout << "stay home\n";
            //resultSet.push_back(-1);
        }else {
            cout << resultSet[i] << endl;
            //resultSet.push_back(hotelList.top().price * n);
        }

    }
}
int main(){
    int n,b,h,w;
    while(cin >> n >> b >> h >> w){
        //Hotel hotelList[h];

        priority_queue<Hotel, vector<Hotel>, ComparePrice> hotelList;
        for(int i=0;i<h;i++){
            Hotel hotel;
            hotel.eligible = false;
            cin >> hotel.price;
            for(int j=0;j<w;j++){
                int bedCount;
                cin >> bedCount;
                if(bedCount >= n)
                    hotel.eligible = true;
                hotel.freeBeds.push_back(bedCount);
            }
            if(hotel.price * n > b)
                hotel.eligible = false;
            if(hotel.eligible){
                hotelList.push(hotel);
            }
        }
        /*while (!hotelList.empty()) {
            Hotel hotel = hotelList.top();
            hotelList.pop();
            cout << hotel.price << " ";
            for(int i = 0;i<hotel.freeBeds.size();i++){
                cout << hotel.freeBeds[i] << " ";
            }
            cout << endl;
        }*/
        if(hotelList.empty()){
            cout << "stay home\n";
            //resultSet.push_back(-1);
        }else {
            cout << hotelList.top().price * n << endl;
            //resultSet.push_back(hotelList.top().price * n);
        }
    }

}
