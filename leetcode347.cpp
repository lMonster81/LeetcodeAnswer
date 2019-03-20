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

typedef pair<int, int> PAIR;

class Solution
{
  public:
    vector<int> topKFrequent(vector<int> &nums, int k)
    {
        unordered_map<int, int> save;
        for (int i = 0; i < nums.size(); i++)
        {
            save[nums[i]]++;
        }
        vector<PAIR> ans(save.begin(), save.end());
        sort(ans.begin(), ans.end(), [](const PAIR &lhs, const PAIR &rhs) -> bool {
            return lhs.second > rhs.second;
        });
        vector<int> res(k);
        for (int i = 0; i < k; i++)
            res[i] = ans[i].first;
        return res;
    }
};