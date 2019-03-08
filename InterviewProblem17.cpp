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
    bool containsDuplicate(vector<int> &nums)
    {
        if(nums.size() <= 1)
            return false;
        sort(nums.begin(), nums.end());
        for (int i = 1; i < nums.size(); i++)
        {
            if(nums[i] == nums[i - 1])
                return true;
        }
        return false;
    }
};