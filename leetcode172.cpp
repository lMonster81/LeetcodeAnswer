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
    int trailingZeroes(int n)
    {
        int res = 0;
        while(n)
        {
            n /= 5;
            res +=  n;
        }
        return res;
    }
};

int main()
{
    Solution s;
    cout << s.trailingZeroes(25) << endl;
    getchar();
}