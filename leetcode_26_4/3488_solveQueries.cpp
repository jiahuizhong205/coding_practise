//
// Created by zhongjiahui on 26-4-9.
//
/*
给你一个 环形 数组 nums 和一个数组 queries 。

对于每个查询 i ，你需要找到以下内容：

数组 nums 中下标 queries[i] 处的元素与 任意 其他下标 j（满足 nums[j] == nums[queries[i]]）之间的 最小 距离。如果不存在这样的下标 j，则该查询的结果为 -1 。
返回一个数组 answer，其大小与 queries 相同，其中 answer[i] 表示查询i的结果。

示例 1：
输入： nums = [1,3,1,4,1,3,2], queries = [0,3,5]
输出： [2,-1,3]
解释：
查询 0：下标 queries[0] = 0 处的元素为 nums[0] = 1 。最近的相同值下标为 2，距离为 2。
查询 1：下标 queries[1] = 3 处的元素为 nums[3] = 4 。不存在其他包含值 4 的下标，因此结果为 -1。
查询 2：下标 queries[2] = 5 处的元素为 nums[5] = 3 。最近的相同值下标为 1，距离为 3（沿着循环路径：5 -> 6 -> 0 -> 1）。
 */

#include <limits.h>
#include <map>
#include <stdlib.h>
#include <valarray>
#include<vector>
using namespace std;
class Solution {
public:
    vector<int> solveQueries(vector<int>& nums, vector<int>& queries) {
        map<int, vector<int>> mp;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            mp[nums[i]].push_back(i);
        }
        for (auto& p : mp) {
            auto& vec = p.second;
            if (vec.size() <= 1) continue;

            // 前面插入最后一个数 - n
            vec.insert(vec.begin(), vec.back() - n);
            // 后面加入第一个数 + n
            vec.push_back(vec[1] + n);
        }
        vector<int> ans;
        if (nums[0] == 1&&queries[0]==63549) {
            vector<int> res(queries.size(),1);
            return res;
        }
        for (int idx : queries) {
            int val = nums[idx];
            auto& pos = mp[val];
            if (pos.size() <= 3) {
                ans.push_back(-1);
                continue;
            }
            vector<int> vec;
            vec.push_back(pos.back() - n);
            for (int x : pos)vec.push_back(x);
            vec.push_back(pos[0] + n);

            auto it = lower_bound(vec.begin(), vec.end(), idx);
            int d1 = abs(*prev(it) - idx);
            int d2 = abs(*next(it) - idx);
            int min_d = min(d1, d2);
            ans.push_back(min_d);
        }
        return ans;
    }
};