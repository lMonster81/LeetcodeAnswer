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
    int countPrimes(int n)
    {
        if(n <= 2)
            return 0;
        //除去1
        int ans = n - 2;
        vector<bool> prim(n, false);
        prim[0] = true;
        prim[1] = true;
        for (int i = 2; i < n; i++)
        {
            if(prim[i])
            {
                --ans;
                continue;
            }
            for (int j = i + i; j < n; j += i)
                prim[j] = true;
        }
        return ans;
    }
};