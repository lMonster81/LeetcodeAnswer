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
    int firstUniqChar(string s)
    {
        map<char, int> save;
        for(char c : s)
        {
            save[c]++;
        }
        for (int i = 0; i < s.size(); i++)
        {
            if(save[s[i]] == 1)
                return i;
        }
        return -1;
    }
};