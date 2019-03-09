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

class RandomizedSet
{
    int size = 0;
    map<int, bool> hash;

  public:
    RandomizedSet()
    {
    }

    bool insert(int val)
    {
        if(hash[val])
            return false;
        hash[val] = true;
        size++;
        return true;
    }

    bool remove(int val)
    {
        if(!hash[val])
            return false;
        hash.erase(val);
        size--;
        return true;
    }

    int getRandom()
    {
        int x = rand() % size;
        return hash.at(x);
    }
};