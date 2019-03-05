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

class Solution
{
  public:
    bool isPalindrome(string s)
    {
        int len = s.size();
        if(len <= 1)
        {
            return true;
        }
        int low = 0, high = len - 1;
        while(low < high)
        {
            if(s[low] >= 'a' && s[low] <= 'z' || s[low] >= 'A' && s[low] <= 'Z' || s[low] >= '0' && s[low] <= '9')
            {
                if (s[high] >= 'a' && s[high] <= 'z' || s[high] >= 'A' && s[high] <= 'Z' || s[high] >= '0' && s[high] <= '9')
                {
                    if((s[low] >= '0' && s[low] <= '9' && (s[high] < '0' || s[high] > '9')) || (s[high] >= '0' && s[high] <= '9' && (s[low] < '0' || s[low] > '9')))
                    {
                        return false;
                    }
                    else if (s[low] != s[high] && s[low] + 'a' - 'A' != s[high] && s[low] - 'a' + 'A' != s[high])
                    {
                        return false;
                    }
                    else
                    {
                        low++;
                        high--;
                    }
                }
                else
                {
                    high--;
                }
                
            }
            else
            {
                low++;
            }
        }
        return true;
    }
};

void Test()
{
    cout << (char)('0' + 'a' - 'A') << endl;
    cout << (int)(' ') << endl;
}

int main()
{
    Solution s;
    cout << s.isPalindrome("0P") << endl;
    getchar();
    return 0;
}