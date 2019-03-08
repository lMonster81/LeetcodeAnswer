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
    bool increasingTriplet(vector<int> &nums)
    {
        int min1 = __INT_MAX__;
        int min2 = __INT_MAX__;
        for (int i = 0; i < nums.size(); i++)
        {
            if(nums[i] <= min1)
            {
                min1 = nums[i];
            }
            else if(nums[i] <= min2)
            {
                min2 = nums[i];
            }
            else
            {
                return true;
            }
            
        }
        return false;
    }
};

int main()
{
    Solution s;
    vector<int> nums = {1, 2, 3, 4, 5};
    cout << s.increasingTriplet(nums) << endl;
    getchar();
    return 0;
}