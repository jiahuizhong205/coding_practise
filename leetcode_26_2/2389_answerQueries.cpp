//
// Created by zhongjiahui on 26-2-11.
//
/*
给你一个长度为 n 的整数数组 nums ，和一个长度为 m 的整数数组 queries 。

返回一个长度为 m 的数组 answer ，其中 answer[i] 是 nums 中 元素之和小于等于 queries[i] 的子序列的最大长度  。

子序列 是由一个数组删除某些元素（也可以不删除）但不改变剩余元素顺序得到的一个数组。

示例 1：

输入：nums = [4,5,2,1], queries = [3,10,21]
输出：[2,3,4]
解释：queries 对应的 answer 如下：
- 子序列 [2,1] 的和小于或等于 3 。可以证明满足题目要求的子序列的最大长度是 2 ，所以 answer[0] = 2 。
- 子序列 [4,5,1] 的和小于或等于 10 。可以证明满足题目要求的子序列的最大长度是 3 ，所以 answer[1] = 3 。
- 子序列 [4,5,2,1] 的和小于或等于 21 。可以证明满足题目要求的子序列的最大长度是 4 ，所以 answer[2] = 4 。
 */
#include <algorithm>
#include<vector>
#include <bits/ranges_algo.h>
using namespace std;
class Solution {
public:
    vector<int> answerQueries(vector<int>& nums, vector<int>& queries) {
        int n = nums.size();
        int m = queries.size();
        vector<long long> nums_new(n,0);
        for(int i=0;i<n;i++) {
            nums_new[i] = nums[i];
        }
        vector<int> res(m,0);
        sort(nums_new.begin(),nums_new.end());
        for(int i=1;i<n;i++) {
            nums_new[i] += nums_new[i-1];
        }
        for(int i=0;i<m;i++) {
            int l = 0,r = n - 1;
            int temp = 0;
            while(l<=r) {
                int mid = l + (r-l)/2;
                if(nums_new[mid]<=queries[i]) {
                    temp = mid + 1;
                    l = mid + 1;
                }else{
                    r = mid - 1;
                }
            }
            res[i] = temp;
        }
        return res;
    }
};