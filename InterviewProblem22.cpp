#include <algorithm>
#include <bitset>
#include <cmath>
#include <cstdio>
#include<stdlib.h>
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
    vector<int> source;

  public:
    Solution(vector<int> nums)
    {
        source = nums;
    }

    vector<int> reset()
    {
        return source;
    }

    vector<int> shuffle()
    {
        vector<int> shuffleArr = source;
        for (int i = 0; i < shuffleArr.size(); i++)
        {
            int x = rand() % shuffleArr.size();
            swap(shuffleArr[i], shuffleArr[x]);
        }
        return shuffleArr;
    }
};