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
    void moveZeroes(vector<int> &nums)
    {
        for (int i = 0; i < nums.size() - 1; i++)
        {
            bool flag = false;
            for (int j = 1; j < nums.size() - i; j++)
            {
                if(nums[j - 1] == 0)
                {
                    swap(nums[j], nums[j - 1]);
                    flag = true;
                }
            }
            if(!flag)
                return;
        }
    }
};