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
/*
class Solution
{
    bool find = false;
    TreeNode* ans = NULL;

  public:
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
    {
        Search(root, p->val, q->val);
        return ans;
    }

    vector<bool> Search(TreeNode* root, int p1, int p2)
    {
        if(root == NULL)
            return {0, 0};
        
        vector<bool> v1 = Search(root->left, p1, p2);
        vector<bool> v2 = Search(root->right, p1, p2);
        if(v1[0] == 1 && v1[1] == 1 || v2[0] == 1 && v2[1] == 1)
        {
            return {1, 1};
       00000000 }
        if (v1[0] == 1 && v1[1] == 0 && v2[0] == 0 && v2[1] == 1 ||
            v1[0] == 0 && v1[1] == 1 && v2[0] == 1 && v2[1] == 0)
        {
            ans = root;
            return {1, 1};
        }
        if(v1[0] == 1 || v1[1] == 1)
        {
            if(root ->val == p2)
            {
                ans = root;
                return {1, 1};
            }
        }
        if(v2[0] == 1 || v2[1] == 1)
        {
            if (root->val == p1)
            {
                ans = root;
                return {1, 1};
            }
        }
        if(root ->val == p1)
        {
            return {1, 0};
        }
        if(root ->val == p2)
        {
            return {0, 1};
        }
        return {0, 0};
    }
};
*/

class Solution
{
  public:
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
    {
        if(root == NULL)
            return root;
        if(root == p || root == q)
            return root;
        TreeNode *left = lowestCommonAncestor(root->left, p, q);
        TreeNode *right = lowestCommonAncestor(root->right, p, q);
        if(left != NULL && right != NULL)
            return root;
        if(left != NULL)
            return left;
        if(right != NULL)
            return right;
        return NULL;
    }
};