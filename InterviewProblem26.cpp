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
#include <vector>
using namespace std;

class Solution
{
  public:
    int kthSmallest(vector<vector<int>> &matrix, int k)
    {
        int row = matrix.size();
        map<int, bool> visit;
        int cnt = 0;
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < row; j++)
            {
                if(!visit[matrix[i][j]])
                {
                    visit[matrix[i][j]] = true;
                    cnt++;
                }
                if(cnt == k)
                    return matrix[i][j];
            }
        }
        return 0;
    }
};