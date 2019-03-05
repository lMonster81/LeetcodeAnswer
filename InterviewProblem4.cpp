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
    void merge(vector<int> &nums1, int m, vector<int> &nums2, int n)
    {
        int size = nums1.size();
        int i, j;
        for (i = size - 1, j = m - 1; j >= 0; i--, j--)
        {
            nums1[i] = nums1[j];
        }
        i++, j++;
        int k = 0;
        while(i < size && j < n)
        {
            if(nums1[i] < nums2[j])
            {
                nums1[k++] = nums1[i++];
            }
            else
            {
                nums1[k++] = nums2[j++];
            }
        }
        while(i < size)
        {
            nums1[k++] = nums1[i++];
        }
        while(j < n)
        {
            nums1[k++] = nums2[j++];
        }
    }
};