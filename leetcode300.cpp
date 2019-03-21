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
    int lengthOfLIS(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> dp(n, 1);
        int ans = 1;
        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                if(nums[j] > nums[i] && dp[i] >= dp[j])
                {
                    dp[j] = dp[i] + 1;
                }
            }
        }
        for(int i : dp)
        {
            ans = i > ans ? i : ans;
        }
        return nums.size() == 0? 0 : ans;
    }
};