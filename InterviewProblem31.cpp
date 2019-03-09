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

class Solution
{
  public:
    int evalRPN(vector<string> &tokens)
    {
        stack<int> integers;
        int temp;
        for (int i = 0; i < tokens.size(); i++)
        {
            if((tokens[i][0] >= '0' && tokens[i][0] <= '9') || (tokens[i][0] == '-' && tokens[i].size() > 1))
            {
                temp = atoi(tokens[i].c_str());
                integers.push(temp);
            }
            else
            {
                int second = integers.top();
                integers.pop();
                int first = integers.top();
                integers.pop();
                switch (tokens[i][0])
                {
                    case '+':
                        temp = first + second;
                        break;
                    case '-':
                        temp = first - second;
                        break;
                    case '*':
                        temp = first * second;
                        break;
                    default:
                        temp = first / second;
                        break;
                }
                integers.push(temp);
            }
        }
        return integers.top();
    }
};