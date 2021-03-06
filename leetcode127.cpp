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
#include<unordered_map>
#include<unordered_set.h>
#include <vector>
using namespace std;

// class Solution
// {
//   public:
//     int ladderLength(string beginWord, string endWord, vector<string> &wordList)
//     {
//         int n = beginWord.size();
//         multimap<string, string> mm;
//         for (int i = 0; i < wordList.size(); i++)
//         {
//             int cnt = 0;
//             for (int k = 0; k < n; k++)
//             {
//                 if(beginWord[k] != wordList[i][k])
//                     cnt++;
//             }
//             if(cnt == 1)
//             {
//                 mm.insert(make_pair(beginWord, wordList[i]));
//                 mm.insert(make_pair(wordList[i], beginWord));
//             }
//         }
//         for (int i = 0; i < wordList.size(); i++)
//         {
//             for (int j = i + 1; j < wordList.size(); j++)
//             {
//                 int cnt = 0;
//                 for (int k = 0; k < n; k++)
//                 {
//                     if (wordList[i][k] != wordList[j][k])
//                         cnt++;
//                 }
//                 if (cnt == 1)
//                 {
//                     mm.insert(make_pair(wordList[i], wordList[j]));
//                     mm.insert(make_pair(wordList[j], wordList[i]));
//                 }
//             }
//         }
//         queue<string> q;
//         q.push(endWord);
//         map<string, bool> visit;
//         visit[endWord] = true;
//         int ans = 0;
//         while(!q.empty())
//         {
//             int size = q.size();
//             ans++;
//             for (int i = 0; i < size; i++)
//             {
//                 string temp = q.front();
//                 q.pop();
//                 multimap<string, string>::iterator beg, end, it;
//                 beg = mm.lower_bound(temp);
//                 end = mm.upper_bound(temp);
//                 for (it = beg; it != end; it++)
//                 {
//                     if((*it).second == beginWord)
//                     {
//                         return ans + 1;
//                     }
//                     if (!visit[(*it).second])
//                     {
//                         visit[(*it).second] = true;
//                         q.push((*it).second);
//                     }
//                 }
//             }
//         }
//         return 0;
//     }
// };

class Solution
{
  public:
    int ladderLength(string beginWord, string endWord, vector<string> &wordList)
    {
        //查是否已经遍历过
        unordered_map<string, bool> visit;
        //增加查询速度
        unordered_set<string> words(wordList.begin(), wordList.end());
        if(words.find(endWord) == words.end())
            return 0;
        int ans = 0;
        queue<string> q;
        visit[endWord] = true;
        q.push(endWord);
        while(!q.empty())
        {
            int size = q.size();
            ++ans;
            while(size--)
            {
                string front = q.front();
                q.pop();
                for (int i = 0; i < front.size(); i++)
                {
                    string temp = front;
                    for (char j = 'a'; j <= 'z'; j++)
                    {
                        if(front[i] == j)
                            continue;
                        front[i] = j;
                        if(front == beginWord)
                            return ans + 1;
                        if(words.find(front) != words.end() && !visit[front])
                        {
                            visit[front] = true;
                            q.push(front);
                        }
                    }
                    front = temp;
                }
            }
        }
        return 0;
    }
};

int main()
{
    Solution s;
    vector<string> v = {"hot", "dot", "dog", "lot", "log"};
    cout << s.ladderLength("hit","cog",v) << endl;
    getchar();
    return 0;
}