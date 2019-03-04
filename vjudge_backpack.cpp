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

/*超时
int main()
{
    int cases;
    cin >> cases;
    while(cases--)
    {
        int all1, all2, all;
        cin >> all1 >> all2;
        all = all2 - all1;
        int INF = all2 * 1000;
        int n;
        cin >> n;
        vector<int> value(n + 1, 0);
        vector<int> weight(n + 1, 0);
        for (int i = 1; i <= n; i++)
        {
            cin >> value[i] >> weight[i];
        }
        vector<vector<int>> dp(n + 1, vector<int>(all + 1, INF));
        for (int i = 0; i <= n; i++)
        {
            dp[i][0] = 0;
        }
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= all; j++)
            {
                for (int k = 1; k * weight[i] <= j; k++)
                {
                    dp[i][j] = min(dp[i - 1][j], dp[i - 1][j - k * weight[i]] + k * value[i]);
                }
            }
        }
        int MIN = INF;
        for (int i = 1; i <= n; i++)
        {
            MIN = min(dp[i][all], MIN);
        }
        if(MIN >= INF)
            cout << "This is impossible." << endl;
        else
        {
            cout << "The minimum amount of money in the piggy-bank is " << MIN << "." << endl;
        }
        
    }
    return 0;
}
*/

int main()
{
    int cases;
    cin >> cases;
    while (cases--)
    {
        int all1, all2, all;
        cin >> all1 >> all2;
        all = all2 - all1;
        int INF = all2 * 1000;
        int n;
        cin >> n;
        vector<int> value(n + 1, 0);
        vector<int> weight(n + 1, 0);
        for (int i = 1; i <= n; i++)
        {
            cin >> value[i] >> weight[i];
        }
        vector<int> dp(all + 1, INF);
        dp[0] = 0;
        for (int i = 1; i <= n; i++)
        {
            for (int j = weight[i]; j <= all; j++)
            {
                dp[j] = min(dp[j], dp[j - weight[i]] + value[i]);
            }
        }
        int MIN = min(INF, dp[all]);
        if (MIN >= INF)
            cout << "This is impossible." << endl;
        else
        {
            cout << "The minimum amount of money in the piggy-bank is " << MIN << "." << endl;
        }
    }
    return 0;
}
