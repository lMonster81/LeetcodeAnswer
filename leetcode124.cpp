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

  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  };
 

class Solution
{
  public:
    int ans = -__INT_MAX__;
    int maxPathSum(TreeNode *root)
    {
        GetAns(root);
        return ans;
    }

    int GetAns(TreeNode *root)
    {
        if (root == NULL)
            return 0;
        int left = GetAns(root->left);
        int right = GetAns(root->right);
        int suml = left + root -> val;
        int sumr = right + root->val;
        ans = max(ans, left + right + root->val);
        ans = max(ans, suml);
        ans = max(ans, sumr);
        int Max = max(suml, sumr);
        return Max > 0 ? Max : 0;
    }
};