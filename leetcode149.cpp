#include <algorithm>
#include <bitset>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <deque>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <cstdlib>
#include<cstdio>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

  struct Point {
      int x;
      int y;
      Point() : x(0), y(0) {}
      Point(int a, int b) : x(a), y(b) {}
  };
 
class Solution
{
  public:
    int maxPoints(vector<Point> &points)
    {
        if(points.size() <= 1)
            return points.size();
        map<double, int> m1;
        map<double, int> m2;
        int n = points.size();
        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                bool flag = true;
                double k = GetK(points[i], points[j], flag);
                if(flag)
                {
                    m1[k]++;
                }
                else
                {
                    m2[k]++;
                }
                
            }
        }
        int y = 0;
        for(auto a : m1)
        {
            y = max(y, a.second);
        }
        for (auto a : m2)
        {
            y = max(y, a.second);
        }
        double delta = 1 + 8 * y;
        double x1 = (-1 + sqrt(delta)) / 2;
        double x2 = (-1 - sqrt(delta)) / 2;
        return x1 > 0? x1 + 1 : x2 + 1;
    }

    double GetK(Point p1, Point p2, bool &flag)
    {
        double x = p1.x - p2.x;
        double y = p1.y - p2.y;
        if(x == 0)
            flag = false;
        return x == 0 ? p1.x : y / x;
    }
};

int main()
{
    Solution s;
    vector<Point> p = {
        {0,0},
        {0,0},
    };
    cout << s.maxPoints(p) << endl;
    getchar();
    return 0;
}