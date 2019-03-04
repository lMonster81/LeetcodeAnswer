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

int main()
{

    //每个物品的重量
    vector<int> weight;
    //每个物品的价值
    vector<int> value;
    //每个物品的数量
    vector<int> nums;
    //背包的总重量
    int all;
    //多少种物品
    int n;
    /*//0-1背包1
    vector<vector<int>> dp(n + 1, vector<int>(all + 1, 0));
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= all; j++)
        {
            if(weight[i] <= j)
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - weight[i]] + value[i]);
            else
                dp[i][j] = dp[i - 1][j];
        }
    }
    cout << dp[n][all] << endl;*/

    /*0-1背包2
    vector<int> dp(all + 1, 0);
    for (int i = 1; i <= n; i++)
    {
        //写法一
        for (int j = all; j >= 1; j--)
        {
            if (weight[i] <= j)
                dp[j] = max(dp[j], dp[j - weight[i]] + value[i]);
        }
        //写法二
        for (int j = all; j >= weight[i]; j--)
        {
            dp[j] = max(dp[j], dp[j - weight[i]] + value[i]);
        }
    }
    cout << dp[all] << endl;*/

    /*完全背包1
    vector<vector<int>> dp(n + 1, vector<int>(all + 1, 0));
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= all; j++)
        {
            for (int k = 0; k * weight[i] <= j; k++)
            {
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - k * weight[i]] + k * value[i]);
            }
        }
    }
    cout << dp[n][all] << endl;
    */

    /*完全背包2
    vector<int> dp(n + 1, 0);
    for (int i = 1; i <= n; i++)
    {
        //写法一
        for (int j = 1; j <= all; j++)
        {
            if(weight[i] <= j)
                dp[j] = max(dp[j], dp[j - weight[i]] + value[i]);
        }
        //写法二
        for (int j = weight[i]; j <= all; j++)
        {
            dp[j] = max(dp[j], dp[j - weight[i]] + value[i]);
        }
    }
    cout << dp[all] << endl;
    */
    /*
    for (int i = 1; i <= n; i++)
    {
        while(nums[i] != 1)
        {
            weight.push_back(weight[i]);
            nums[i]--;
        }
    }
    vector<int> dp(weight.size() + 1, 0);
    for (int i = 1; i < weight.size(); i++)
    {
        for (int j = all; j >= weight[i]; j--)
        {
            dp[j] = max(dp[j], dp[j - weight[i]] + value[i]);
        }
    }
    cout << dp[all + 1] << endl;
    */
    return 0;
}