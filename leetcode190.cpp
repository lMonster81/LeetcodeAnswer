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
    uint32_t reverseBits(uint32_t n)
    {
        uint32_t ans = 0;
        for (int i = 0; i < 32; i++)
        {
            if(n & 1 == 1)
            {
                ans = (ans | 1);
            }
            if(i == 31)
                break;
            n >>= 1;
            ans <<= 1;
        }
        return ans;
    }
};