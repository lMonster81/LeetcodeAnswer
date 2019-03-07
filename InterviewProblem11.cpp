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
    bool isAnagram(string s, string t)
    {
        map<char, int> str1;
        map<char, int> str2;
        if(s.size() != t.size())
            return false;
        for(char c : s)
        {
            str1[c]++;
        }
        for(char c : t)
        {
            str2[c]++;
        }
        for(char c : s)
        {
            if(str1[c] != str2[c])
                return false;
        }
        return true;
    }
};