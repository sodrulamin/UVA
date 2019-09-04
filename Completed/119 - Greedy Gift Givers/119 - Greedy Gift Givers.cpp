#include <iostream>
#include <string>
#include <map>
#include <vector>

using namespace std;

struct Person{
    string name;
    int balance;

    Person(string const& str,int const& n)
    :name(str), balance(n)
    {}
};

int main(){
    //vector<Person> resultSet;
    int personCount;
    map<string, Person> personMap;
    vector<string> sequence;
    bool firstCase = true;
    while(cin >> personCount){

        //if(personCount == -1){
          //  break;
        //}
        personMap.clear();
        sequence.clear();
        map<string, Person>::iterator it;
        for(int i=0;i<personCount;i++){
            string name;
            cin >> name;
            Person person(name,0);
            personMap.insert(make_pair(name,person));
            sequence.push_back(name);
        }
        for(int i=0;i<personCount;i++){
            string name;
            cin >> name;
            int amount,givenCount;
            cin >> amount >> givenCount;
            it = personMap.find(name);

            int givenAmount = 0;
            if(givenCount > 0){
                it->second.balance -= amount;
                givenAmount = amount / givenCount;
                amount = amount % givenCount;
                it->second.balance += amount;
            }

            for(int j=0;j<givenCount;j++){
                string givenName;
                cin >> givenName;
                it = personMap.find(givenName);
                it->second.balance += givenAmount;
            }
        }



        if(firstCase){
            firstCase = false;
        }else{
            cout << endl;
        }
        for(int i=0;i<personCount;i++){
            it = personMap.find(sequence[i]);
            cout << it->first << " " << it->second.balance << endl;
            //Person person(it->first,it->second.balance);
            //resultSet.push_back(person);
        }
        //Person person(" ",0);
        //resultSet.push_back(person);

    }
    /*for(int i=0;i<resultSet.size();i++){
        if(resultSet[i].name == " "){
            cout << endl;
        }else {
            cout << resultSet[i].name << " " << resultSet[i].balance << endl;
        }
    }*/

    return 0;
}
