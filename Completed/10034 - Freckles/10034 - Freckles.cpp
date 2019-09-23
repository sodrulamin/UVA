#include <iostream>
#include <queue>
#include <cstdio>
#include <vector>
#include <cmath>

using namespace std;

struct Pos
{
    double x,y;
    bool operator<(const Pos& other) const {
        if(x > other.x)
            return true;
        else if(x == other.x)
            return y > other.y;
        return false;
    }
    bool operator==(const Pos& other) const {
        return x == other.x && y == other.y;
    }
};
struct Edge
{
    double length;
    Pos a,b;
    int indexa,indexb;
    bool operator<(const Edge& other) const {
//        if (x < other.x) return true;
//        if (x > other.x) return false;
//        return y < other.y;
        return length > other.length;
    }

    bool operator==(const Edge& other) const {
        return a == other.a && b == other.b;
    }
};

double getLength(Pos a, Pos b)
{
    double diffx,diffy;
    diffx = a.x - b.x;
    diffy = a.y - b.y;
    diffx = diffx * diffx;
    diffy = diffy * diffy;
    return sqrt(diffx + diffy);
}

int main()
{
    int caseCount,T;
    cin >> T;
    caseCount = T;
    while(caseCount > 0)
    {
        int n;
        cin >> n;
        vector<Pos> points;
        priority_queue<Edge> q;
        for(int i=0;i<n;i++)
        {
            Pos p;
            cin >> p.x >> p.y;
            points.push_back(p);
            //q.push(p);
        }
//        while(!q.empty())
//        {
//            Pos p = q.top();
//            q.pop();
//            //cout << p.x << " " << p.y << endl;
//            printf("%.2f %.2f\n",p.x,p.y);
//        }
        for(int i=0;i<n-1;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                Edge e;
                e.a = points[i];
                e.b = points[j];
                e.indexa = i;
                e.indexb = j;
                e.length = getLength(e.a,e.b);
                q.push(e);
            }
        }
        double minLength = 0;
        int zone[101] = {0};
        int zoneCount = 0;
        while(!q.empty())
        {
            Edge e = q.top();
            q.pop();
            int i = e.indexa,j = e.indexb;
            if(zone[i] == 0 && zone[j] == 0) ///First time visiting both node
            {
                zoneCount++;
                zone[i] = zoneCount;
                zone[j] = zoneCount;
                minLength += e.length;
            }
            else if(zone[i] == 0) ///First time visiting node i
            {
                zone[i] = zone[j];
                minLength += e.length;
            }
            else if(zone[j] == 0) ///First time visiting node j
            {
                zone[j] = zone[i];
                minLength += e.length;
            }
            else if(zone[i] != zone[j])///both node were visited earlier but they were in different zone
            {
                minLength += e.length;
                int oldZone = zone[j];
                for(int k=0;k<n;k++)
                {
                    if(zone[k] == oldZone)
                        zone[k] = zone[i];
                }
            }
            //printf("(%.2f,%.2f) ~ (%.2f,%.2f) = %.2f\n",e.a.x,e.a.y,e.b.x,e.b.y,e.length);
        }
        if(caseCount != T)
            printf("\n");
        printf("%.2f\n",minLength);
        caseCount--;
    }
    return 0;
}
