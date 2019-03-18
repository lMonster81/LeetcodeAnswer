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
#include<unordered_map>
using namespace std;

class RandomizedSet
{
  public:
    unordered_map<int, bool> hashmap;
    RandomizedSet()
    {
    }

    bool insert(int val)
    {
        if (hashmap[val])
            return false;
        hashmap[val] = true;
        return true;
    }

    bool remove(int val)
    {
        if (hashmap.count(val))
        {
            hashmap.erase(val);
            return true;
        }
        return false;
    }

    int getRandom()
    {
        if (hashmap.size() == 0)
            return -1;
        int x = rand() % hashmap.size();
        int cnt = 0;
        for (auto i : hashmap)
        {
            if (cnt == x)
                return i.first;
            cnt++;
        }
        return -1;
    }
};