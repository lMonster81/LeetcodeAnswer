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

/*class Solution
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
};*/
/*
class Solution
{
  public:
    int majorityElement(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        return nums[nums.size() / 2];
    }
};*/

class Solution
{
  public:
    int majorityElement(vector<int> &nums)
    {
        int temp = -1;
        int count = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if(count == 0)
            {
                temp = nums[i];
                count = 1;
            }
            else
            {
                if(temp == nums[i])
                {
                    count++;
                }
                else
                {
                    count--;
                }
                
            }
            
            
        }
        return temp;
    }
};