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

void swap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}

//冒泡
void MaoPaoSort(vector<int> arr)
{
    int len = arr.size();
    /*
    for (int i = 0; i < len; i++)
    {
        for (int j = i + 1; j < len; j++)
        {
            if (arr[i] > arr[j])
            {
                swap(arr[i], arr[j]);
            }
        }
    }*/
    for (int i = 0; i < arr.size() - 1; i++)
    {
        for (int j = 1; j < arr.size() - i; j++)
        {
            if(arr[j - 1] > arr[j])
            {
                swap(arr[j - 1], arr[j]);
            }
        }
    }
    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << (i == arr.size() - 1 ? "\n" : " ");
    }
}

//选择排序
void SelectSort(vector<int> arr)
{
    for (int i = 0; i < arr.size(); i++)
    {
        int minIndex = i;
        for (int j = i + 1; j < arr.size(); j++)
        {
            if(arr[j] < arr[minIndex])
            {
                minIndex = j;
            }
        }
        swap(arr[i], arr[minIndex]);
    }
    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << (i == arr.size() - 1 ? "\n" : " ");
    }
}

//插入排序
void InsertSort(vector<int> arr)
{
    //int k = 1;
    for (int i = 1; i < arr.size(); i++)
    {
        if(arr[i] < arr[i - 1])
        {
            int j = i - 1;
            int temp = arr[i];
            while(j >= 0 && arr[j] > temp)
            {
                arr[j + 1] = arr[j];
                j--;
            }
            arr[j + 1] = temp;
        }
        
    }
    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << (i == arr.size() - 1 ? "\n" : " ");
    }
}

//希尔排序
void ShellSort(vector<int> arr)
{
    int len = arr.size();
    for (int gap = len / 2; gap > 0; gap /= 2)
    {
        for (int i = gap; i < len; i++)
        {
            int j = i;
            while(j - gap >= 0 && arr[j] < arr[j - gap])
            {
                swap(arr[j], arr[j - gap]);
                j -= gap;
            }
        }
    }
    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << (i == arr.size() - 1 ? "\n" : " ");
    }
}

//归并排序

void Merge(vector<int> &arr, int start, int mid,int end)
{
    vector<int> temp(end - start + 1);
    int i = start;
    int j = mid + 1;
    int k = 0;
    while (i <= mid && j <= end)
    {
        if (arr[i] <= arr[j])
            temp[k++] = arr[i++];
        else
            temp[k++] = arr[j++];
    }
    while (i <= mid)
    {
        temp[k++] = arr[i++];
    }
    while (j <= end)
    {
        temp[k++] = arr[j++];
    }
    for (int i = 0; i < k; i++)
    {
        arr[start + i] = temp[i];
    }
}

void MergeSort(vector<int> &arr, int start, int end)
{
    if(start >= end)
    {
        return;
    }
    int mid = start + (end - start) / 2;
    MergeSort(arr, start, mid);
    MergeSort(arr, mid + 1, end);
    Merge(arr, start, mid, end);
    for (int i = start; i <= end; i++)
    {
        cout << arr[i] << (i == end ? "\n" : " ");
    }
}

//堆排序
void AdjustHead(vector<int> &arr, int start, int end)
{
    int temp = arr[start];
    for (int j = 2 * start + 1; j <= end; j = j * 2 + 1)
    {
        if (j < end && arr[j] < arr[j + 1])
            j++;
        if (temp >= arr[j])
            break;
        arr[start] = arr[j];
        start = j;
    }
    arr[start] = temp;
}

void HeadSort(vector<int> arr)
{
    //构建大顶堆
    for (int i = arr.size() / 2; i >= 0; i--)
    {
        AdjustHead(arr, i, arr.size() - 1);
    }
    for (int i = arr.size() - 1; i >= 0; i--)
    {
        swap(arr[0], arr[i]);
        AdjustHead(arr, 0, i - 1);
    }
    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << (i == arr.size() - 1 ? "\n" : " ");
    }
}

//快速排序
int Partition(vector<int> &arr, int low, int high)
{
    int key = arr[low];
    while (low < high)
    {
        //不能将顺序反过来
        while (low < high && arr[high] >= key)
            high--;
        swap(arr[low], arr[high]);
        while (low < high && arr[low] <= key)
            low++;
        swap(arr[low], arr[high]);   
    }
    return high;
}

void QuickSort(vector<int> &arr, int low, int high)
{
    if(low < high)
    {
        int pivot = Partition(arr, low, high);
        QuickSort(arr, low, pivot - 1);
        QuickSort(arr, pivot + 1, high);
    }
}


int main()
{
    vector<int> v = {3, 5, 4, 7, 89, 98, 46, 8, 66, 22, 998, 223, 1};
    //MaoPaoSort(v);
    //SelectSort(v);
    //InsertSort(v);
    //ShellSort(v);
    //MergeSort(v, 0, v.size() - 1);
    //HeadSort(v);
    QuickSort(v, 0, v.size() - 1);
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << (i == v.size() - 1 ? "\n" : " ");
    }
    getchar();
    return 0;
}



