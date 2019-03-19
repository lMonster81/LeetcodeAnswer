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

class MedianFinder
{
  public:
    MedianFinder()
    {
    }

    void addNum(int num)
    {
        if(big_heap.size() == 0)
        {
            big_heap.push(num);
            return;
        }
        if(big_heap.size() > little_heap.size())
        {
            if(num < big_heap.top())
            {
                little_heap.push(big_heap.top());
                big_heap.pop();
                big_heap.push(num);
            }
            else
            {
                little_heap.push(num);
            }
            
        }
        else if(big_heap.size() < little_heap.size())
        {
            if(num > little_heap.top())
            {
                big_heap.push(little_heap.top());
                little_heap.pop();
                little_heap.push(num);
            }
            else
            {
                big_heap.push(num);
            }
            
        }
        else
        {
            if(num > little_heap.top())
            {
                big_heap.push(little_heap.top());
                little_heap.pop();
                little_heap.push(num);
            }
            else
            {
                big_heap.push(num);
            }
        }
        
    }

    double findMedian()
    {
        if(big_heap.size() == 0 && little_heap.size() == 0)
        {
            return 0;
        }
        else if(big_heap.size() == little_heap.size())
        {
            return (big_heap.top() + little_heap.top()) / 2.0;
        }
        else
        {
            return big_heap.top();
        }   
    }
    private:
      priority_queue<int> big_heap;
      priority_queue<int, vector<int>, greater<int>> little_heap;
};