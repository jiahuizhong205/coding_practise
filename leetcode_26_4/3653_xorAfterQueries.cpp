//
// Created by zhongjiahui on 26-4-8.
//
/*
给你一个长度为 n 的整数数组 nums 和一个大小为 q 的二维整数数组 queries，其中 queries[i] = [li, ri, ki, vi]。
对于每个查询，按以下步骤执行操作：
设定 idx = li。
当 idx <= ri 时：
更新：nums[idx] = (nums[idx] * vi) % (109 + 7)
将 idx += ki。
在处理完所有查询后，返回数组 nums 中所有元素的 按位异或 结果。


示例 1：
输入： nums = [1,1,1], queries = [[0,2,1,4]]
输出： 4
解释：
唯一的查询 [0, 2, 1, 4] 将下标 0 到下标 2 的每个元素乘以 4。
数组从 [1, 1, 1] 变为 [4, 4, 4]。
所有元素的异或为 4 ^ 4 ^ 4 = 4。
 */

#include<vector>
using namespace std;
class Solution {
#define MOD 1000000007
public:
    int xorAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        for (int i = 0; i < queries.size(); i++) {
            int idx = queries[i][0],r = queries[i][1],k = queries[i][2],v = queries[i][3];
            while (idx <= r) {
                nums[i] = 1ll * nums[i] * v % MOD;
                idx += k;
            }
        }
        int res = 0;
        for (int i = 0; i < nums.size(); i++) {
            res ^= nums[i];
        }
        return res;
    }
};