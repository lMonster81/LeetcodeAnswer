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
    vector<vector<string>> ans;

  public:
    vector<vector<string>> partition(string s)
    {
        vector<string> arr;
        GetAns(s, 0, arr);
        return ans;
    }

    void GetAns(string s, int pos, vector<string> &arr)
    {
        if(pos >= s.size())
        {
            ans.push_back(arr);
            return;
        }
        for (int i = pos; i < s.size(); i++)
        {
            string temp(s.begin() + pos, s.begin() + i + 1);
            if(Check(temp))
            {
                arr.push_back(temp);
                GetAns(s, i + 1, arr);
                arr.pop_back();
            }
        }
    }

    bool Check(string s)
    {
        if(s.size() <= 1)
            return true;
        for (int i = 0, j = s.size() - 1; i < j; i++, j--)
        {
            if(s[i] != s[j])
                return false;
        }
        return true;
    }
};

int main()
{
    Solution s;
    vector<vector<string>> ans = s.partition("aab");
    for(auto a : ans)
    {
        for(auto b : a)
        {
            cout << b << "  ";
        }
        cout << endl;
    }
    getchar();
    return 0;
}