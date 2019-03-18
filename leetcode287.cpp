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
    int findDuplicate(vector<int> &nums)
    {
        int n = nums.size() - 1;
        int low = 1;
        int high = n;
        while(low < high)
        {
            int mid = low + (high - low) / 2;
            int cnt = 0;
            for (int i : nums)
            {
                if(i <= mid)
                    cnt++;
            }
            if(cnt <= mid)
            {
                low = mid + 1;
            }
            else
            {
                high = mid;
            }
        }
        return low;
    }
};