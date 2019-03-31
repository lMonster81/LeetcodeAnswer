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
    int missingNumber(vector<int> &nums)
    {
        if(nums.size() <= 0)
            return 0;
        sort(nums.begin(), nums.end());
        int n = nums.size();
        if(nums[0] != 0)
            return 0;
        if(nums[nums.size() - 1] != n)
            return n;
        for (int i = 1; i < nums.size(); i++)
        {
            if(nums[i] - nums[i - 1] > 1)
                return (nums[i] + nums[i - 1]) / 2;
        }
        return 0;
    }
};
//other ways
//基于桶排序
