#pragma region head
/*
    88888888    111
    8      8     1 
    8      8     1
    88888888     1
    8      8     1
    8      8     1
    88888888   11111

*/
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
typedef long long ll;
const double PI = acos(-1.0f);
//float double 精度
const double eps = 1e-6;
const int INF = 1000000000;

//链表节点结构体
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

//二叉树节点结构体
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

//求最小公因数
int gcd(int x, int y)
{
    int MAX = max(x, y);
    int MIN = min(x, y);
    return MAX % MIN == 0 ? MIN : gcd(MIN, MAX % MIN);
}
//求最大公倍数
int lcm(int x, int y)
{
    return x * y / gcd(x, y);
}

//处理节点，值与位置
struct Node
{
    int val;
    int pos;
    Node(int x, int y) : val(x), pos(y)
    {
    }
};

//处理一维线段的结构体
struct Interval
{
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};

//用于处理二维平面的结构体
struct Point
{
    int x;
    int y;
    Point(int v1, int v2) : x(v1), y(v2)
    {
    }

    bool operator==(const Point p1)
    {
        return p1.x == x && p1.y == y;
    }

    Point operator-(const Point p1)
    {
        return Point(x - p1.x, y - p1.y);
    }

    Point operator+(const Point p1)
    {
        return Point(x + p1.x, y + p1.y);
    }
};

#pragma region CMP系列
bool cmp2(int x, int y)
{
    return x > y;
}

bool cmp3(int x, int y)
{
    string str1 = to_string(x);
    string str2 = to_string(y);

    return (str1 + str2) > (str2 + str1);
}

bool cmp1(int x, int y)
{
    return x < y;
}
#pragma endregion

const double esp = 1e-7;
//const int INF = INT_MAX;

//simple atoi
int to_int(string s)
{
    int val = 0;
    for (int i = 0; i < s.size(); i++)
    {
        val = val * 10 + s[i] - '0';
    }
    return val;
}
#pragma endregion

/*class Solution
{
  public:
    vector<vector<int>> G;
    int N;
    vector<bool> visit;
    vector<int> findMinHeightTrees(int n, vector<pair<int, int>> &edges)
    {
        vector<int> anss;
        if(n == 0)
            return anss;
        G = vector<vector<int>>(n, vector<int>(n, 0));
        N = n;
        visit = vector<bool>(n, 0);
        vector<int> results = vector<int>(n);
        for (int i = 0; i < edges.size(); i++)
        {
            G[edges[i].first][edges[i].second] = 1;
            G[edges[i].second][edges[i].first] = 1;
        }
        int MIN = 1e8;
        for (int i = 0; i < N; i++)
        {
            visit[i] = true;
            results[i] = DFS(i, visit);
            MIN = min(results[i], MIN);
            visit[i] = false;
        }
        for (int i = 0; i < N; i++)
        {
            if(results[i] == MIN)
            {
                anss.push_back(i);
            }
        }
        return anss;
    }

    int DFS(int root, vector<bool> &visit)
    {
        int ans = 1;
        int MAX = 0;
        for (int i = 0; i < N; i++)
        {
            if(G[root][i] == 1 && visit[i] == false)
            {
                visit[i] = true;
                MAX = max(MAX, DFS(i, visit));
                visit[i] = false;
            }
        }
        return ans + MAX;
    }
};
*/

class Solution
{
    vector<vector<bool>> G;
    vector<bool> visit;
    vector<int> ans;
    vector<int> edge;

  public:
    vector<int> findMinHeightTrees(int n, vector<pair<int, int>> &edges)
    {
        if(n == 0)
            return ans;
        G = vector<vector<bool>>(n, vector<bool>(n, 0));
        edge.resize(n, 0);
        visit.resize(n, 0);
        for (int i = 0; i < edges.size(); i++)
        {
            G[edges[i].first][edges[i].second] = 1;
            G[edges[i].second][edges[i].first] = 1;
            edge[edges[i].first]++;
            edge[edges[i].second]++;
        }
        queue<int> q;
        while(n > 2)
        {
            for (int i = 0; i < edge.size(); i++)
            {
                if (edge[i] == 1)
                {
                    q.push(i);
                }
            }
            while(!q.empty())
            {
                int front = q.front();
                q.pop();
                visit[front] = true;
                n--;
                edge[front]--;
                for (int i = 0; i < G.size(); i++)
                {
                    if(G[front][i])
                    {
                        edge[i]--;
                        G[front][i] = 0;
                        G[i][front] = 0;
                    }
                }
            }
        }
        for (int i = 0; i < visit.size(); i++)
        {
            if(!visit[i])
            {
                ans.push_back(i);
            }
        }
        return ans;
    }
};

int main()
{
    vector<pair<int, int>> edges = 
    {
        {0,1},
        {0,2},
        {0,3},
        {3,4},
        {4,5},
    };
    Solution s;
    for(auto a : s.findMinHeightTrees(6, edges))
    {
        cout << a << endl;
    }
    getchar();
    return 0;
}