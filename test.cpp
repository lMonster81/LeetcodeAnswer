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
#include<stdlib.h>
#include<unordered_map>
using namespace std;
typedef long long ll;
const double PI = acos(-1.0f);
//float double 精度
const double eps = 1e-6;
const int INF = 1000000000;


//求最大公因数
int gcd(int x, int y)
{
    int MAX = max(x, y);
    int MIN = min(x, y);
    return MAX % MIN == 0 ? MIN : gcd(MIN, MAX % MIN);
}
//求最小公倍数
int lcm(int x, int y)
{
    return x * y / gcd(x, y);
}


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
        if (hashmap[val] == true)
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

    void information()
    {
        cout <<"size   "<< hashmap.size() << endl;
        cout << "count   "<<hashmap.count(0) << endl;
    }
};

int main()
{
    priority_queue<int> pq;
    priority_queue<int, vector<int>, greater<int>> pq2;
    getchar();
    return 0;
}