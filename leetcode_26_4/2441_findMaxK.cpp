//
// Created by zhongjiahui on 26-4-23.
//
/*
给你一个 不包含 任何零的整数数组 nums ，
找出自身与对应的负数都在数组中存在的最大正整数 k 。
返回正整数 k ，如果不存在这样的整数，返回 -1 。

示例 1：
输入：nums = [-1,2,-3,3]
输出：3
解释：3 是数组中唯一一个满足题目要求的 k 。
*/
#include <algorithm>
#include <map>
#include <set>
#include<vector>
using namespace std;
class Solution {
public:
    int findMaxK(vector<int>& nums) {
        set<int> s;
        int res = -1;
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size();i++) {
            s.insert(nums[i]);
            if (nums[i] > 0) {
                auto it = s.find(-1*nums[i]);
                if (it != s.end()) {
                    res = max(res,nums[i]);
                }
            }
        }
        return res;
    }
};