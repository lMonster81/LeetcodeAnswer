#include <algorithm>
#include <bitset>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <deque>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>
using namespace std;

class Solution
{
  public:
    int maxProduct(vector<int> &nums)
    {
        if(nums.size() == 0)
            return 0;
        int _max = nums[0];
        int _min = nums[0];
        int ans = _max;
        for (int i = 1; i < nums.size(); i++)
        {
            int temp = _min;
            _min = min(min(_min * nums[i], nums[i]), _max * nums[i]);
            _max = max(max(_max * nums[i], nums[i]), temp * nums[i]);
            ans = max(_max, ans);
        }
        return ans;
    }
};