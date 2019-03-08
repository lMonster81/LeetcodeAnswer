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
/*
class Solution
{
  public:
    vector<int> productExceptSelf(vector<int> &nums)
    {
        int len = nums.size();
        vector<int> pre(len);
        vector<int> post(len);
        vector<int> ans(len);
        int cnt = nums[0];
        for (int i = 1; i < nums.size(); i++)
        {
            pre[i] = cnt;
            cnt *= nums[i];
        }
        cnt = nums[len - 1];
        for (int i = len - 2; i >= 0; i--)
        {
            post[i] = cnt;
            cnt *= nums[i];
        }
        for (int i = 0; i < len; i++)
        {
            if(i == 0)
            {
                ans[i] = post[i];
            }
            else if(i == len - 1)
            {
                ans[i] = pre[i];
            }
            else
            {
                ans[i] = pre[i] * post[i];
            }
            
        }
        return ans;
    }
};*/

class Solution
{
  public:
    vector<int> productExceptSelf(vector<int> &nums)
    {
        int left = 1;
        int right = 1;
        vector<int> ans(nums.size());
        for (int i = 0; i < nums.size(); i++)
        {
            ans[i] = left;
            left *= nums[i];
        }
        for (int i = nums.size() - 1; i >= 0; i--)
        {
            ans[i] *= right;
            right *= nums[i];
        }
        return ans;
    }
};