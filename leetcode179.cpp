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
    string largestNumber(vector<int> &nums)
    {
        sort(nums.begin(), nums.end(), [](int x, int y) -> bool {
            string strx = to_string(x);
            string stry = to_string(y);
            return (strx + stry) > (stry + stry);
        });
        string ans = "";
        bool x = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if(nums[i] != 0 && x == 0)
            {
                x = 1;
            }
            ans += to_string(nums[i]);
        }
        if(x == 0)
        {
            return "0";
        }
        return ans;
    }
};