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
    int longestConsecutive(vector<int> &nums)
    {
        if(nums.size() == 0)
            return 0;
        set<int> s;
        for(auto i : nums)
            s.insert(i);
        int ans = 1;
        int cnt = 0;
        int last = 0;
        for(auto a : s)
        {
            if(cnt == 0)
            {
                cnt = 1;
            }
            else
            {
                if(a - last == 1)
                {
                    ans = max(ans, ++cnt);
                }
                else
                {
                    cnt = 1;
                } 
            }
            last = a;
        }
        return ans;
    }
};