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

// class Solution
// {
//   public:
//     vector<int> intersect(vector<int> &nums1, vector<int> &nums2)
//     {
//         map<int, int> n1;
//         map<int, int> n2;
//         vector<int> ans;
//         for(int i : nums1)
//         {
//             n1[i]++;
//         }
//         for(int i : nums2)
//         {
//             n2[i]++;
//         }
//         for(int i : nums1)
//         {
//             while(n1[i] > 0 && n2[i] > 0)
//             {
//                 ans.push_back(i);
//                 n1[i]--;
//                 n2[i]--;
//             }
//         }
//         return ans;
//     }
// };

class Solution
{
  public:
    vector<int> intersect(vector<int> &nums1, vector<int> &nums2)
    {
        //排序好的情况
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        int i = 0, j = 0;
        vector<int> ans;
        while(i < nums1.size() && j < nums2.size())
        {
            if(nums1[i] == nums2[j])
            {
                ans.push_back(nums1[i]);
                i++;
                j++;
            }
            else if(nums1[i] > nums2[j])
            {
                j++;
            }
            else
            {
                i++;
            } 
        }
        return ans;
    }
};