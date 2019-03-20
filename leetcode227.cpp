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

class Solution
{
  public:
    int calculate(string s)
    {
        s += " ";
        string temp = "";
        vector<string> v;
        for (int i = 0; i < s.size(); i++)
        {
            if(s[i] == ' ')
            {
                if(temp == "")
                {
                    continue;
                }
                v.push_back(temp);
                temp = "";
                continue;
            }
            if(s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/')
            {
                if(temp != "")
                {
                    v.push_back(temp);
                    temp = "";
                }
                temp += s[i];
                v.push_back(temp);
                temp = "";
            }
            else
            {
                temp += s[i];
            } 
        }
        vector<string> post;
        stack<string> cal;
        for (int i = 0; i < v.size(); i++)
        {
            if(v[i] == "*" || v[i] == "/")
            {
                while (!cal.empty())
                {
                    string top = cal.top();
                    if (top == "+" || top == "-")
                    {
                        break;
                    }
                    post.push_back(top);
                    cal.pop();
                }
                cal.push(v[i]);
            }
            else if(v[i] == "+" || v[i] == "-")
            {
                while(!cal.empty())
                {
                    post.push_back(cal.top());
                    cal.pop();
                }
                cal.push(v[i]);
            }
            else
            {
                post.push_back(v[i]);
            }
        }
        while (!cal.empty())
        {
            post.push_back(cal.top());
            cal.pop();
        }
        stack<int> nums;
        for (int i = 0; i < post.size(); i++)
        {
            if(post[i] == "+")
            {
                int second = nums.top();
                nums.pop();
                int first = nums.top();
                nums.pop();
                nums.emplace(first + second);
            }
            else if(post[i] == "-")
            {
                int second = nums.top();
                nums.pop();
                int first = nums.top();
                nums.pop();
                nums.emplace(first - second);
            }
            else if(post[i] == "*")
            {
                int second = nums.top();
                nums.pop();
                int first = nums.top();
                nums.pop();
                nums.emplace(first * second);
            }
            else if(post[i] == "/")
            {
                int second = nums.top();
                nums.pop();
                int first = nums.top();
                nums.pop();
                nums.emplace(first / second);
            }
            else
            {
                nums.emplace(atoi(post[i].c_str()));
            }
        }
        return nums.top();
    }
};

int main()
{
    Solution s;
    cout << s.calculate("3 + 5 * 2 + 5 * 3 ") << endl;
    getchar();
    return 0;
}