//
// Created by zhongjiahui on 26-2-7.
//
/*
给你两个整数数组 arr1 ， arr2 和一个整数 d ，请你返回两个数组之间的 距离值 。

距离值」 定义为符合此距离要求的元素数目：对于元素 arr1[i] ，不存在任何元素 arr2[j] 满足 |arr1[i]-arr2[j]| <= d 。
*/
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
    bool find_close(vector<int> &nums,int a,int d) {
        int n = nums.size();
        int l = 0,r = n-1;
        while(l<=r) {
            int mid = l + (r-l)/2;
            if(abs(a-nums[mid])<=d) {
                return true;
            }
            else if (a<nums[mid]) {
                r = mid -1;
            }else {
                 l = mid + 1;
            }
        }
        return false;
    }
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
        sort(arr2.begin(), arr2.end());
        int m = arr1.size(), n = arr2.size();
        int res = 0;
        for (int i = 0; i < m; i++) {
            if (!find_close(arr2,arr1[i],d)) {
                res++;
            }
        }
        return res;
    }
};