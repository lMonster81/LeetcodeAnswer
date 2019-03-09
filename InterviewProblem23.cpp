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
#include <vector>
using namespace std;

class MinStack
{
    stack<int> normal;
    stack<int> minstack;

  public:
    MinStack()
    {
    }

    void push(int x)
    {
        normal.push(x);
        if(minstack.empty())
        {
            minstack.push(x);
        }
        else
        {
            if(x <= minstack.top())
            {
                minstack.push(x);
            }
        }
        
    }

    void pop()
    {
        int temp = normal.top();
        normal.pop();
        if(temp == minstack.top())
        {
            minstack.pop();
        }
    }

    int top()
    {
        return normal.top();
    }

    int getMin()
    {
        return minstack.top();
    }
};