//
// Created by zhongjiahui on 26-4-27.
//
/*
给你一个整数数组 nums。该数组包含 n 个元素，其中 恰好 有 n - 2 个元素是 特殊数字 。
剩下的 两个 元素中，一个是所有 特殊数字 的 和 ，另一个是 异常值 。
异常值 的定义是：既不是原始特殊数字之一，也不是表示元素和的那个数。
注意，特殊数字、和 以及 异常值 的下标必须 不同 ，但可以共享 相同 的值。
返回 nums 中可能的 最大异常值。

示例 1：
输入： nums = [2,3,5,10]
输出： 10
解释：
特殊数字可以是 2 和 3，因此和为 5，异常值为 10。
 */
#include <algorithm>
#include <iostream>
#include <ostream>
#include <unordered_map>
#include<vector>
using namespace std;
class Solution {
public:
    int getLargestOutlier(vector<int>& nums) {
        int res = INT_MIN;
        unordered_map<int, int> mp;
        int total = 0;
        for (int x : nums) {
            mp[x]++;
            total += x;
        }
        for (int x:nums) {
            mp[x]--;
            if ((total - x)%2 == 0&&mp[(total-x)/2] > 0) {
                res = max(res,x);
            }
            mp[x]++;
        }
        return res;
    }
};
// int main() {
//     Solution s;
//     vector<int> nums = {-2,-1,-3,-6,4};
//     cout << s.getLargestOutlier(nums) << endl;
//     return 0;
// }