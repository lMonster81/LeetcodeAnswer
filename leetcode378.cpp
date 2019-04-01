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

// class Solution
// {
//   public:
//     int kthSmallest(vector<vector<int>> &matrix, int k)
//     {
//         priority_queue<int> pq;
//         for (int i = 0; i < matrix.size(); i++)
//         {
//             for (int j = 0; j < matrix[i].size(); j++)
//             {
//                 if(pq.size() < k)
//                 {
//                     pq.push(matrix[i][j]);
//                 }
//                 else
//                 {
//                     int temp = pq.top();
//                     if(temp > matrix[i][j])
//                     {
//                         pq.pop();
//                         pq.push(matrix[i][j]);
//                     }
//                 }
//             }
//         }
//         return pq.top();
//     }
// };

class Solution
{
  public:
    int kthSmallest(vector<vector<int>> &matrix, int k)
    {
        int n = matrix.size();
        int low = matrix[0][0];
        int high = matrix[n - 1][n - 1];
    }
};