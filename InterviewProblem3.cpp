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
    bool searchMatrix(vector<vector<int>> &matrix, int target)
    {
        int row = matrix.size();
        if(row <= 0)
        {
            return false;
        }
        int col = matrix[0].size();
        int i = 0, j = col - 1;
        while(i >= 0 && i < row && j >= 0 && j < col)
        {
            if(matrix[i][j] > target)
            {
                j--;
            }
            else if(matrix[i][j] < target)
            {
                i++;
            }
            else
            {
                return true;
            }
            
        }
        return false;
    }
};