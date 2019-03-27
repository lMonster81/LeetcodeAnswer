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
    bool canFinish(int numCourses, vector<pair<int, int>> &prerequisites)
    {
        vector<int> in(numCourses, 0);
        vector<vector<bool>> G(numCourses, vector<bool>(numCourses, 0));
        for (int i = 0; i < prerequisites.size(); i++)
        {
            in[prerequisites[i].first]++;
            G[prerequisites[i].second][prerequisites[i].first] = 1;
        }
        queue<int> q;
        for (int i = 0; i < numCourses; i++)
        {
            if(in[i] == 0)
                q.push(i);
        }
        int ans = 0;
        while(!q.empty())
        {
            int front = q.front();
            q.pop();
            ans++;
            for (int i = 0; i < numCourses; i++)
            {
                if(G[front][i] == 1)
                {
                    if (--in[i] == 0)
                        q.push(i);
                }
            }
        }
        return ans == numCourses ? 1 : 0;
    }
};