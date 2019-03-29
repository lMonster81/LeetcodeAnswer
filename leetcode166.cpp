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
#include <stdlib.h>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution
{
  public:
    string fractionToDecimal(long long numerator, long long denominator)
    {
        vector<long long> save;
        //true + false -
        bool flag = true;
        if(numerator < 0 && denominator > 0 || numerator > 0 && denominator < 0)
            flag = false;
        numerator = numerator < 0 ? -numerator : numerator;
        denominator = denominator < 0 ? -denominator : denominator;
        long long left = numerator / denominator;
        long long temp = numerator % denominator;
        string ans1 = "";
        ans1 += to_string(left);
        string ans2 = "";
        while(temp)
        {
            temp *= 10;
            int i = save.size() - 1;
            for (; i >= 0; i--)
            {
                if(save[i] == temp)
                    break;
            }
            if(i >= 0)
            {
                ans2.insert(i, "(");
                ans2 += ")";
                break;
            }
            save.push_back(temp);
            ans2 += to_string(temp / denominator);
            temp %= denominator;
        }
        return (flag == true ? "" : "-") + ans1 + (ans2 == "" ? "" : ("." + ans2));
    }
};

int main()
{
    Solution s;
    cout << s.fractionToDecimal(-1, -3) << endl;
    getchar();
}