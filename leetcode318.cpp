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

class Solution
{
  public:
    int maxProduct(vector<string> &words)
    {
        sort(words.begin(), words.end(),
             [](const string &a, const string &b) ->bool { return a.size() > b.size(); });
        vector<int> bits(words.size(), 0);
        for (int i = 0; i < words.size(); i++)
        {
            int bit = 0;
            for (int j = 0; j < words[i].size(); j++)
            {
                int x = words[i][j] - 'a';
                bit = ((1 << x) | bit);
            }
            bits[i] = bit;
        }
        int MAX = 0;
        for (int i = 0; i < words.size(); i++)
        {
            for (int j = i + 1; j < words.size(); j++)
            {
                if ((bits[i] & bits[j]) == 0 && words[i].size() * words[j].size() > MAX)
                {
                    MAX = words[i].size() * words[j].size();
                }
            }
        }
        return MAX;
    }
};

int main()
{
    Solution s;
    vector<string> v = {"abcw", "baz", "foo", "bar", "xtfn", "abcdef"};
    cout << s.maxProduct(v) << endl;
    getchar();
    return 0;
}