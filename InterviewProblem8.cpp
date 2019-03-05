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
    bool wordBreak(string s, vector<string> &wordDict)
    {
        if(wordDict.size() <= 0)
        {
            return false;
        }
        if(s.size() <= 0)
        {
            return true;
        }
        map<string, bool> Check;
        for (int i = 0; i < wordDict.size(); i++)
        {
            Check[wordDict[i]] = true;
        }
        vector<bool> dp(s.size(), false);
        for (int i = 0; i < s.size(); i++)
        {
            string temp(s.begin(), s.begin() + i + 1);
            if(Check[temp])
            {
                dp[i] = true;
                continue;
            }
            for (int j = 0; j < i; j++)
            {
                if(dp[j] == true)
                {
                    string temp2(s.begin() + j + 1, s.begin() + i + 1);
                    if(Check[temp2])
                    {
                        dp[i] = true;
                        break;
                    }
                }
            }
        }
        return dp[s.size() - 1];
    }
};

int main()
{
    Solution s;
    vector<string> d = {"cats", "dog", "sand", "and", "cat" };
    cout << s.wordBreak("catsandog", d) << endl;
    getchar();
    return 0;
}