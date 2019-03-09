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
#include <vector>
using namespace std;

#define _INT_MIN (-__INT_MAX__ - 1)

class Solution
{
  public:
    vector<int> maxSlidingWindow(vector<int> &nums, int k)
    {
        int _max = _INT_MIN;
        for (int i = 0; i < k; i++)
        {
            _max = max(nums[i], _max);
        }
        for (int i = k; i < nums.size(); i++)
        {
            
        }
    }
};