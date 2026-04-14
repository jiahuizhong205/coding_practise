//
// Created by zhongjiahui on 26-4-13.
//
/*
给你一个二维整数数组 items ，其中 items[i] = [pricei, beautyi] 分别表示每一个物品的 价格 和 美丽值 。
同时给你一个下标从 0 开始的整数数组 queries 。对于每个查询 queries[j] ，你想求出价格小于等于 queries[j] 的物品中，
最大的美丽值 是多少。如果不存在符合条件的物品，那么查询的结果为 0 。
请你返回一个长度与 queries 相同的数组 answer，其中 answer[j]是第 j 个查询的答案。

示例 1：
输入：items = [[1,2],[3,2],[2,4],[5,6],[3,5]], queries = [1,2,3,4,5,6]
输出：[2,4,5,5,6,6]
解释：
- queries[0]=1 ，[1,2] 是唯一价格 <= 1 的物品。所以这个查询的答案为 2 。
- queries[1]=2 ，符合条件的物品有 [1,2] 和 [2,4] 。
  它们中的最大美丽值为 4 。
- queries[2]=3 和 queries[3]=4 ，符合条件的物品都为 [1,2] ，[3,2] ，[2,4] 和 [3,5] 。
  它们中的最大美丽值为 5 。
- queries[4]=5 和 queries[5]=6 ，所有物品都符合条件。
  所以，答案为所有物品中的最大美丽值，为 6 。
 */
#include <algorithm>
#include<vector>
using namespace std;
class Solution {
public:
    vector<int> maximumBeauty(vector<vector<int>>& items, vector<int>& queries) {
        int n = items.size();
        int m = queries.size();
        vector<int> ans(m,0);
        sort(items.begin(), items.end());
        vector<int> maxBeauty(n);
        maxBeauty[0] = items[0][1];
        for(int i = 1; i < n; i++) {
            maxBeauty[i] = max(maxBeauty[i-1], items[i][1]);
        }
        for (int i = 0; i < m; i++) {
            int q = queries[i];
            int flag = -1;
            int left = 0, right = n-1;
            while (left <= right) {
                int mid = left + (right - left) / 2;
                if (items[mid][0] <= q) {
                    flag = mid;
                    left = mid + 1;
                }
                else  {
                    right = mid - 1;
                }
            }
            ans[i] = flag == -1 ? 0 : maxBeauty[flag];
        }
        return ans;
    }
};