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
/*
class NumArray
{
struct  SegNode
{
    int val;
    int addmark; //延迟更新
};
vector<SegNode> v;
int n;

public:
    NumArray(vector<int> nums)
    {
        //
        if(nums.size() <= 0)
            return;
        n = nums.size() - 1;
        v = vector<SegNode>(nums.size() * 4 + 1);
        buildTree(0, 0, n, nums);
    }
    ~NumArray()
    {
    }

    void buildTree(int root, int start, int end, vector<int> &nums)
    {
        if(start == end)
        {
            v[root].val = nums[start];
        }
        else
        {
            //*int mid = (start + end) / 2;
            int mid = start + (end - start) / 2;
            buildTree((root << 1) + 1, start, mid, nums);
            buildTree((root << 1) + 2, mid + 1, end, nums);
            v[root].val = v[(root << 1) + 1].val + v[(root << 1) + 2].val;
        }
    }

    void updateTree(int root, int start, int end, int index, int newVal)
    {
        if(start >= end)
        {
            if(index == start)
            {
                v[root].val = newVal;
            }
            return;
        }
        int mid = start + (end - start) / 2;
        if(index <= mid)
            updateTree((root << 1) + 1, start, mid, index, newVal);
        else
            updateTree((root << 1) + 2, mid + 1, end, index, newVal);
        v[root].val = v[(root << 1) + 1].val + v[(root << 1) + 2].val;
    }

    int queryTree(int root, int start, int end, int qstart, int qend)
    {
        if(start > qend || end < qstart)
        {
            return 0;
        }
        if(start >= qstart && end <= qend)
        {
            return v[root].val;
        }
        int mid = start + (end - start) / 2;
        if(qstart >= mid + 1)
        {
            return queryTree((root << 1) + 2, mid + 1, end, qstart, qend);
        }
        else if(qend <= mid)
        {
            return queryTree((root << 1) + 1, start, mid, qstart, qend);
        }
        else
        {
            int ans1 = queryTree((root << 1) + 1, start, mid, qstart, qend);
            int ans2 = queryTree((root << 1) + 2, mid + 1, end, qstart, qend);
            return ans1 + ans2;
        }
    }

    void update(int i, int val)
    {
        updateTree(0, 0, n, i, val);
    }

    int sumRange(int i, int j)
    {
        return queryTree(0, 0, n, i, j);
    }
};*/

class NumArray
{
  public:
    vector<int> nums;
    vector<int> sums;
    NumArray(vector<int> nums)
    {
        this->nums = nums;
        sums.resize(nums.size() + 1);
        sums[0] = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            change(i + 1, nums[i]);
        }
        /*for(auto a : sums)
        {
            cout << a << endl;
        }*/
    }

    int lowbit(int x)
    {
        return x & (-x);
    }

    int sum(int n)
    {
        int val = 0;
        while(n > 0)
        {
            val += sums[n];
            n -= lowbit(n);
        }
        return val;
    }

    void change(int i, int val)
    {
        while(i < sums.size())
        {
            sums[i] += val;
            i += lowbit(i);
        }
    }

    void update(int i, int val)
    {
        int offset = val - nums[i];
        nums[i] = val;
        change(i + 1, offset);
    }

    int sumRange(int i, int j)
    {
        return sum(j + 1) - sum(i);
    }
};

int main()
{
getchar();
return 0;
}