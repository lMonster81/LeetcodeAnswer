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

class NumMatrix
{
    vector<vector<int>> matrix;

  public:
    NumMatrix(vector<vector<int>> matrix)
    {
        int row = matrix.size();
        if(row == 0)
            return;
        int col = matrix[0].size();
        /*
        this->matrix.resize(row);
        for (int i = 0; i < row; i++)
        {
            matrix[i].resize(col);
        }*/
        this->matrix = vector<vector<int>>(row, vector<int>(col, 0));
        int cnt = 0;
        for (int i = 0; i < row; i++)
        {
            cnt += matrix[i][0];
            this->matrix[i][0] = cnt;
        }
        cnt = 0;
        for (int j = 0; j < col; j++)
        {
            cnt += matrix[0][j];
            this->matrix[0][j] = cnt;
        }
        for (int i = 1; i < row; i++)
        {
            for (int j = 1; j < col; j++)
            {
                int cntRow = 0;
                int cntCol = 0;
                for (int k = 0; k < j; k++)
                {
                    cntRow += matrix[i][k];
                }
                for (int k = 0; k < i; k++)
                {
                    cntCol += matrix[k][j];
                }
                this->matrix[i][j] = this->matrix[i - 1][j - 1] + cntCol + cntRow + matrix[i][j];
            }
        }
    }

    int sumRegion(int row1, int col1, int row2, int col2)
    {
        if(matrix.size() == 0)
        {
            return 0;
        }
        else if(row1 > 0 && col1 > 0)
        {
            return matrix[row2][col2] - matrix[row2][col1 - 1] - matrix[row1 - 1][col2] + matrix[row1 - 1][col1 - 1];
        }
        else if(row1 == 0 && col1 > 0)
        {
            return matrix[row2][col2] - matrix[row2][col1 - 1];
        }
        else if(row1 > 0 && col1 == 0)
        {
            return matrix[row2][col2] - matrix[row1 - 1][col2];
        }
        else
        {
            return matrix[row2][col2];
        }
        
    }
};

int main()
{
    vector<vector<int>> v = {
        { 3, 0, 1, 4, 2 },
        { 5, 6, 3, 2, 1 },
        { 1, 2, 0, 1, 5 },
        { 4, 1, 0, 1, 7 },
        { 1, 0, 3, 0, 5 }};
    NumMatrix n(v);
    cout << n.sumRegion(0, 0, 1, 1) << endl;
    cout << n.sumRegion(1, 0, 2, 2) << endl;
    cout << n.sumRegion(0, 1, 2, 2) << endl;
    getchar();
    return 0;
}