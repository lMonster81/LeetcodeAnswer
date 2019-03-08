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
    void rotate(vector<int> &nums, int k)
    {
        int len = nums.size();
        k = k - (k / len) * len;
        Inversion(nums, 0, len - k - 1);
        Inversion(nums, len - k, len - 1);
        Inversion(nums, 0, len - 1);
    }

    void Inversion(vector<int> &arr, int s, int e)
    {
        for (; s < e; s++, e--)
        {
            swap(arr[s], arr[e]);
        }
    }
};