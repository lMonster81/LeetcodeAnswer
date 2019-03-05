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
    map<int, vector<string>> save;
    vector<string> ans;

  public:
    vector<string> wordBreak(string s, vector<string> &wordDict)
    {
        if (wordDict.size() <= 0)
        {
            return ans;
        }
        if (s.size() <= 0)
        {
            return ans;
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
            if (Check[temp])
            {
                dp[i] = true;
                save[i].push_back(temp);
            }
            for (int j = 0; j < i; j++)
            {
                if (dp[j] == true)
                {
                    string temp2(s.begin() + j + 1, s.begin() + i + 1);
                    if (Check[temp2])
                    {
                        dp[i] = true;
                        save[i].push_back(temp2);
                    }
                }
            }
        }
        if(!dp[s.size() - 1])
            return ans;
        DFS(s.size(), "");
        return ans;
    }

    void DFS(int len, string s)
    {
        if(len == 0)
        {
            ans.push_back(s);
            return;
        }
        for (int i = 0; i < save[len - 1].size(); i++)
        {
            DFS(len - save[len - 1][i].size(), save[len - 1][i]+ (s == ""? "" : " ") + s);
        }
    }
};

int main()
{
    Solution s;
    vector<string> d = {"cats", "dog", "sand", "and", "cat"};
    getchar();
    return 0;
}