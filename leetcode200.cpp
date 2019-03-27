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

int dr[] = {0, 0, 1, -1};
int dc[] = {1, -1, 0, 0};

class Solution
{
  public:
    int numIslands(vector<vector<char>> &grid)
    {
        int row = grid.size();
        if(row <= 0)
            return 0;
        int col = grid[0].size();
        vector<bool> visit(row * col, false);
        int ans = 0;
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                if(grid[i][j] == '1' && !visit[i * col + j])
                {
                    ++ans;
                    visit[i * col + j] = true;
                    DFS(grid, visit, i, j, row, col);
                }
            }
        }
        return ans;
    }

    void DFS(vector<vector<char>> &grid, vector<bool> &visit, int posr, int posc,int row, int col)
    {
        for (int i = 0; i < 4; i++)
        {
            int nr = posr + dr[i];
            int nc = posc + dc[i];
            if(nr < 0 || nr >= row || nc < 0 || nc >= col)
                continue;
            if(grid[nr][nc] != '1' || visit[nr * col + nc])
                continue;
            visit[nr * col + nc] = true;
            DFS(grid, visit, nr, nc, row, col);
        }
        return;
    }
};