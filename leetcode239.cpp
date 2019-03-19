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
    vector<int> maxSlidingWindow(vector<int> &nums, int k)
    {
        deque<int> window;
        vector<int> ans;
        for (int i = 0; i < nums.size(); i++)
        {
            if(i >= k && i - k + 1 > window.front())
                window.pop_front();
            while(!window.empty() && nums[window.back()] < nums[i])
            {
                window.pop_back();
            }
            window.push_back(i);
            if(i >= k - 1)
            {
                ans.push_back(nums[window.front()]);
            }
        }
        return ans;
    }
};