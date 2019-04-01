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


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Codec
{
  public:
    // Encodes a tree to a single string.
    string serialize(TreeNode *root)
    {
        queue<TreeNode *> q;
        q.push(root);
        string ans = "[";
        while(!q.empty())
        {
            int size = q.size();
            vector<TreeNode *> v(size);
            int last = -1;
            bool flag = false;
            for (int i = 0; i < size; i++)
            {
                TreeNode *node = q.front();
                q.pop();
                v[i] = node;
                if(node)
                {
                    last = i;
                    if (node->left || node->right)
                    {
                        flag = true;
                    }
                }
            }
            if(flag)
            {
                for (int i = 0; i < size; i++)
                {
                    if(v[i] == NULL)
                    {
                        ans = ans + "null";
                        q.push(NULL);
                        q.push(NULL);
                    }
                    else
                    {
                        ans = ans + to_string(v[i]->val);
                        q.push(v[i]->left);
                        q.push(v[i]->right);
                    }
                    ans += ",";
                    
                }
            }
            else
            {
                for (int i = 0; i <= last; i++)
                {
                    if (v[i] == NULL)
                    {
                        ans = ans + "null";
                    }
                    else
                    {
                        ans = ans + to_string(v[i]->val);
                    }
                    ans += ",";
                }
            }
            
        }
        if (ans[ans.size() - 1] = '[')
            ans += ']';
        else
            ans[ans.size() - 1] = ']';
        return ans;
    }

    // Decodes your encoded data to tree.
    TreeNode *deserialize(string data)
    {
        if(data.empty())
            return NULL;
        data[data.size() - 1] = ',';
        vector<TreeNode*> v;
        string temp = "";
        for (int i = 1; i < data.size(); i++)
        {
            if(data[i] == ',')
            {
                if(temp != "")
                {
                    if(temp == "null")
                        v.push_back(NULL);
                    else
                    {
                        v.push_back(new TreeNode(stoi(temp)));
                    }
                    temp = "";
                }
            }
            else
            {
                temp += data[i];
            }
        }
        for (int i = 0; i < v.size(); i++)
        {
            if(!v[i])
                continue;
            if(2 * i + 1 < v.size())
            {
                v[i]->left = v[2 * i + 1];
            }
            if(2 * i + 2 < v.size())
            {
                v[i]->right = v[2 * i + 2];
            }
        }
        return v.size() > 0? v[0] : NULL;
    }
};

int main()
{
    Codec c;
    cout << c.deserialize("[]") << endl;
    getchar();
    return 0;
}