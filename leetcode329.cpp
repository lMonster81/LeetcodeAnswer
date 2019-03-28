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

//more big, more little
typedef pair<int, int> P;
int dr[] = {1, -1, 0, 0};
int dc[] = {0, 0, 1, -1};

class Solution
{
  public:
    int longestIncreasingPath(vector<vector<int>> &matrix)
    {
        int row = matrix.size();
        if (row == 0)
            return 0;
        int col = matrix[0].size();
        vector<vector<P>> dp(row, vector<P>(col, {0, 0}));
        int ans = 0;
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                for (int k = 0; k < 4; k++)
                {
                    int nr = i + dr[k];
                    int nc = j + dc[k];
                    if (nr < 0 || nr >= row || nc < 0 || nc >= col)
                        continue;
                    if (matrix[i][j] > matrix[nr][nc])
                    {
                        dp[i][j].second = max(dp[i][j].second, dp[nr][nc].second + 1);
                    }
                    else if (matrix[i][j] < matrix[nr][nc])
                    {
                        dp[i][j].first = max(dp[i][j].first, dp[nr][nc].first + 1);
                    }
                    ans = max(ans, dp[i][j].first + dp[i][j].second);
                }
            }
        }
        return ans + 1;
    }
};

int main()
{
    vector<vector<int>> matrix = {
        {7,6,1,1},
        {2,7,6,0},
        {1,3,5,1},
        {6,6,3,2}
    };
    Solution s;
    cout << s.longestIncreasingPath(matrix) << endl;
    getchar();
    return 0;
}