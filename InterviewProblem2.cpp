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
    int majorityElement(vector<int> &nums)
    {
        map<int, int> check;
        for (int i = 0; i < nums.size(); i++)
        {
            check[nums[i]]++;
            if (check[nums[i]] > nums.size() / 2)
            {
                return nums[i];
            }
        }
        return 0;
    }
};