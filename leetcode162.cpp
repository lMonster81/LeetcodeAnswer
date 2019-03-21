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
    int findPeakElement(vector<int> &nums)
    {
        if(nums.size() == 1)
        {
            return 0;
        }
        if(nums.size() == 2)
        {
            return nums[0] > nums[1] ? 0 : 1;
        }
        int low = 0;
        int high = nums.size() - 1;
        while(low < high)
        {
            int mid = low + (high - low) / 2;
            if(mid == 0)
            {
                if(nums[mid] > nums[mid + 1])
                {
                    return mid;
                }
                low = mid + 1;
            }
            else if(mid == nums.size() - 1)
            {
                if(nums[mid] > nums[nums.size() - 2])
                {
                    return mid;
                }
                high = mid - 1;
            }
            else
            {
                if(nums[mid] > nums[mid - 1] && nums[mid] > nums[mid + 1])
                {
                    return mid;
                }
                if(nums[mid - 1] > nums[mid + 1])
                {
                    high = mid - 1;
                }
                else
                {
                    low = mid + 1;
                }
            }
        }
        return low;
    }
};

int main()
{
    Solution s;
    vector<int> v = {3, 4, 3, 5, 1};
    cout << s.findPeakElement(v) << endl;
    getchar();
    return 0;
}