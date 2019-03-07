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
    void reverseString(vector<char> &s)
    {
        int i = 0, j = s.size() - 1;
        for (; i < j; i++, j--)
        {
            swap(s[i], s[j]);
        }
    }
};