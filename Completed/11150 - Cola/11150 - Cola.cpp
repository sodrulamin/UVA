#include <iostream>
#include <vector>

using namespace std;

int result[] = {
    1,
    3,
    4,
    6,
    7,
    9,
    10,
    12,
    13,
    15,
    16,
    18,
    19,
    21,
    22,
    24,
    25,
    27,
    28,
    30,
    31,
    33,
    34,
    36,
    37,
    39,
    40,
    42,
    43,
    45,
    46,
    48,
    49,
    51,
    52,
    54,
    55,
    57,
    58,
    60,
    61,
    63,
    64,
    66,
    67,
    69,
    70,
    72,
    73,
    75,
    76,
    78,
    79,
    81,
    82,
    84,
    85,
    87,
    88,
    90,
    91,
    93,
    94,
    96,
    97,
    99,
    100,
    102,
    103,
    105,
    106,
    108,
    109,
    111,
    112,
    114,
    115,
    117,
    118,
    120,
    121,
    123,
    124,
    126,
    127,
    129,
    130,
    132,
    133,
    135,
    136,
    138,
    139,
    141,
    142,
    144,
    145,
    147,
    148,
    150,
    151,
    153,
    154,
    156,
    157,
    159,
    160,
    162,
    163,
    165,
    166,
    168,
    169,
    171,
    172,
    174,
    175,
    177,
    178,
    180,
    181,
    183,
    184,
    186,
    187,
    189,
    190,
    192,
    193,
    195,
    196,
    198,
    199,
    201,
    202,
    204,
    205,
    207,
    208,
    210,
    211,
    213,
    214,
    216,
    217,
    219,
    220,
    222,
    223,
    225,
    226,
    228,
    229,
    231,
    232,
    234,
    235,
    237,
    238,
    240,
    241,
    243,
    244,
    246,
    247,
    249,
    250,
    252,
    253,
    255,
    256,
    258,
    259,
    261,
    262,
    264,
    265,
    267,
    268,
    270,
    271,
    273,
    274,
    276,
    277,
    279,
    280,
    282,
    283,
    285,
    286,
    288,
    289,
    291,
    292,
    294,
    295,
    297,
    298,
    300
}

int main()
{
    int n = 1;
    //while(n <= 200)
    while(cin >> n)
    {
        if(n == -1)
            break;
        int curN = n;
        int maxSum = 0,sum = n,divident,residue;
        while(curN >= 3)
        {
            //sum += curN;
            divident = curN / 3;
            residue = curN % 3;
            sum = sum + divident;
            //cout << "cur: " << curN << " div: " << divident << " res: " << residue << " sum: " << sum << endl;
            curN = divident + residue;
        }
        maxSum = sum;
        curN = n + 1;
        sum = n;
        while(curN >= 3)
        {
            //sum += curN;
            divident = curN / 3;
            residue = curN % 3;
            sum = sum + divident;
            //cout << "cur: " << curN << " div: " << divident << " res: " << residue << " sum: " << sum << endl;
            curN = divident + residue;

        }
        residue += divident;
        if(residue >= 1 && maxSum < sum)
            maxSum = sum;

        curN = n + 2;
        sum = n;
        while(curN >= 3)
        {
            //sum += curN;
            divident = curN / 3;
            residue = curN % 3;
            sum = sum + divident;
            //cout << "cur: " << curN << " div: " << divident << " res: " << residue << " sum: " << sum << endl;
            curN = divident + residue;
        }
        residue += divident;
        if(residue >= 2 && maxSum < sum)
            maxSum = sum;
        cout << maxSum << endl;
        n++;
    }
    return 0;
}
