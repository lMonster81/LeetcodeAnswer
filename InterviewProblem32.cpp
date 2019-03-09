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
#include <vector>
using namespace std;

class Solution
{
  public:
    int titleToNumber(string s)
    {
        if(s.size() == 0)
            return 0;
        int ans = 0;
        for (int i = 0; i < s.size(); i++)
        {
            ans = (s[i] - 'A' + 1) + ans * 26;
        }
        return ans;
    }
};