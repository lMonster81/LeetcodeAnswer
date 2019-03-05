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
    int singleNumber(vector<int> &nums)
    {
        if(nums.size() == 1)
            return nums[0];
        int temp = nums[0];
        for (int i = 1; i < nums.size(); i++)
        {
            temp = temp ^ nums[i];
        }
        return temp;
    }
};