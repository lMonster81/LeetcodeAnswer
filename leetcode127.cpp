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
    int ladderLength(string beginWord, string endWord, vector<string> &wordList)
    {
        int n = beginWord.size();
        multimap<string, string> mm;
        for (int i = 0; i < wordList.size(); i++)
        {
            int cnt = 0;
            for (int k = 0; k < n; k++)
            {
                if(beginWord[k] != wordList[i][k])
                    cnt++;
            }
            if(cnt == 1)
            {
                mm.insert(make_pair(beginWord, wordList[i]));
                mm.insert(make_pair(wordList[i], beginWord));
            }
        }
        for (int i = 0; i < wordList.size(); i++)
        {
            for (int j = i + 1; j < wordList.size(); j++)
            {
                int cnt = 0;
                for (int k = 0; k < n; k++)
                {
                    if (wordList[i][k] != wordList[i][k])
                        cnt++;
                }
                if (cnt == 1)
                {
                    mm.insert(make_pair(wordList[i], wordList[j]));
                    mm.insert(make_pair(wordList[j], wordList[i]));
                }
            }
        }
        queue<string> q;
        map<string, bool> visit;
        visit[beginWord] = true;
        int ans = 0;
        while(!q.empty())
        {
            int size = q.size();
            ans++;
            for (int i = 0; i < size; i++)
            {
                string temp = q.front();
                q.pop();
                multimap<string, string>::iterator beg, end, it;
                beg = mm.lower_bound(temp);
                end = mm.upper_bound(temp);
                for (it = beg; it != end; it++)
                {
                    if((*it).second == endWord)
                    {
                        return ans;
                    }
                    if (!visit[(*it).second])
                    {
                        visit[(*it).second] = true;
                        q.push((*it).second);
                    }
                }
            }
        }
        return 0;
    }
};