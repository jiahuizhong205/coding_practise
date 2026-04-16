//
// Created by zhongjiahui on 26-4-16.
//
/*
给你一个整数数组 nums 和一个正整数 threshold  ，你需要选择一个正整数作为除数，然后将数组里每个数都除以它，并对除法结果求和。
请你找出能够使上述结果小于等于阈值 threshold 的除数中 最小 的那个。
每个数除以除数后都向上取整，比方说 7/3 = 3 ， 10/2 = 5 。
题目保证一定有解。
示例 1：
输入：nums = [1,2,5,9], threshold = 6
输出：5
解释：如果除数为 1 ，我们可以得到和为 17 （1+2+5+9）。
如果除数为 4 ，我们可以得到和为 7 (1+1+2+3) 。如果除数为 5 ，和为 5 (1+1+1+2)。
 */
#include<vector>
using namespace std;
class Solution {
public:
    long long check(vector<int> &nums, int k) {
        int n = nums.size();
        long long res = 0;
        for (int num : nums) {
            res += (num + k - 1) / k;
        }
        return res;
    }
    int smallestDivisor(vector<int>& nums, int threshold) {
        int res = 0;
        int Max = -1;
        for(int i=0;i<nums.size();i++) {
            if(nums[i]>Max) {
                Max = nums[i];
            }
        }
        int left = 1, right = Max + 1;
        while(left < right) {
            int mid = left + (right - left) / 2;
            if (check(nums, mid) <= threshold) {
                right = mid;
            }else {
                left = mid + 1;
            }
        }
        return left;
    }
};