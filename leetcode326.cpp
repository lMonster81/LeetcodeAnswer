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
    bool isPowerOfThree(int n)
    {
        if(!n)
            return false;
        while(n && n != 1)
        {
            if(n % 3 != 0)
                return false;
            n /= 3;
        }
        return true;
    }
};