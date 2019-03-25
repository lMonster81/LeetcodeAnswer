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
    int rob(vector<int> &nums)
    {
        int n = nums.size();
        if(n < 2)
        {
            return n == 0 ? 0 : nums[0];
        }
        int first = nums[0];
        int second = max(nums[0], nums[1]);
        for (int i = 2; i < n; i++)
        {
            int Max = max(first + nums[i], second);
            first = second;
            second = Max;
        }
        return max(first, second);
    }
};