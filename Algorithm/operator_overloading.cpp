#include <iostream>
#include <string>

using namespace std;

class Character{

    public:
    int ascii;
    int frequency;


    bool operator <(const Character& c);
    bool operator >(const Character& c);
    friend bool operator==(const Character& c1, const Character& c2)
    {
        cout << "Comparing " << c1.frequency << " == " << c2.frequency << " = " << (c1.frequency == c2.frequency && c1.ascii == c2.ascii) << endl;
        return c1.frequency == c2.frequency && c1.ascii == c2.ascii;
    }
};
bool Character::operator <(const Character& c)
{
    cout << "Comparing " << frequency << " < " << c.frequency << " = " << (frequency < c.frequency) << endl;
    if(c.frequency == frequency)
        return ascii < c.ascii;
    return frequency < c.frequency;
}
bool Character::operator >(const Character& c)
{
    cout << "Comparing " << frequency << " > " << c.frequency << " = " << (frequency > c.frequency) << endl;
    if(c.frequency == frequency)
        return ascii > c.ascii;
    return frequency > c.frequency;
}

int main()
{
    Character c1,c2;
    c1.ascii = 95;
    c1.frequency = 9;
    c2.ascii = 95;
    c2.frequency = 9;

//    if(c1 < c2)
//        cout << "C1 is less than c2" << endl;
//    else
//        cout << "C1 is greater than c2" << endl;
//
//    cout << (c1 == c2) << endl << (c1 > c2) << endl;
    c1 == c2;
    c1 > c2;
    c1 < c2;
    return 0;
}
