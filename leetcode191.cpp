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

typedef unsigned int uint32_t;

class Solution
{
  public:
    int hammingWeight(uint32_t n)
    {
        int ans = 0;
        while(n)
        {
            if(n & 1)
            {
                ans++;
            }
            n >>= 1;
        }
        return ans;
    }
};