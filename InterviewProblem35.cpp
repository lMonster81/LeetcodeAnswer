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

struct TreeNode 
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };


class Solution
{
  public:
    int ans = 0;
    int kthSmallest(TreeNode *root, int k)
    {
        Search(root, k);
        return ans;
    }

    void Search(TreeNode *root, int &k)
    {
        if(root == NULL)
            return;
        Search(root->left, k);
        if(k == 0)
            return;
        if (k == 1)
        {
            k--;
            ans = root->val;
            return;
        }
        k--;
        Search(root->right, k);
    }
};