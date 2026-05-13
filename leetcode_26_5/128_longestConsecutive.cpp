//
// Created by zhongjiahui on 26-5-8.
//
/*
给定一个未排序的整数数组 nums ，找出数字连续的最长序列（不要求序列元素在原数组中连续）的长度。
请你设计并实现时间复杂度为 O(n) 的算法解决此问题。
示例 1：
输入：nums = [100,4,200,1,3,2]
输出：4
解释：最长数字连续序列是 [1, 2, 3, 4]。它的长度为 4。
 */

#include <algorithm>
#include<vector>
using namespace std;
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        if(n <= 1) return n;
        int right = 1;
        int res = 1;
        int cur = 1;
        while (right < n) {
            if (nums[right] == nums[right - 1] + 1) {
                cur ++;
                res = (cur > res) ? cur : res;
                right ++;
            }else if (nums[right] == nums[right - 1]) {
                right ++;
            }else {
                right++;
                cur = 1;
            }
        }
        return res;
    }
};