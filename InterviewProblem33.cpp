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
    int fourSumCount(vector<int> &A, vector<int> &B, vector<int> &C, vector<int> &D)
    {
        int len = A.size();
        map<int, int> save1;
        int ans = 0;
        for (int i = 0; i < len; i++)
        {
            for (int j = 0; j < len; j++)
            {
                save1[A[i] + B[j]]++;
            }
        }
        for (int i = 0; i < len; i++)
        {
            for (int j = 0; j < len; j++)
            {
                ans += save1[-C[i] - D[j]];
            }
        }
        return ans;
    }
};

int main()
{
    vector<int> v1 = {-1,1,1, 1, -1};
    vector<int> v2 = {-1, 1, 0,0,-1};
    vector<int> v3 = {-1,-1,-1,-1,1};
    vector<int> v4 = {0,0,1,-1,-1};
    Solution s;
    cout << s.fourSumCount(v1, v2, v3, v4) << endl;
    getchar();
    return 0;
}