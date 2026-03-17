//
// Created by zhongjiahui on 26-3-17.
//
/*
给你一个二进制矩阵 matrix ，它的大小为 m x n ，你可以将 matrix 中的 列 按任意顺序重新排列。
请你返回最优方案下将 matrix 重新排列后，全是 1 的最大子矩阵面积。

示例 1：

输入：matrix = [[0,0,1],[1,1,1],[1,0,1]]
输出：4
 */

#include <algorithm>
#include<vector>
using namespace std;
class Solution {
public:
    int largestSubmatrix(vector<vector<int>>& matrix) {
        int m = matrix.size(),n = matrix[0].size();
        int res = 0;
        vector<int>heights(n,0);
        for (auto row:matrix) {
            for (int i = 0; i < n; i++) {
                if (row[i] == 0) {
                    heights[i] = 0;
                }else {
                    heights[i] ++;
                }
            }
            vector<int> temp(heights);
            sort(temp.begin(),temp.end());

            for (int i = 0; i < n; i++) {
                res = max(res,temp[i] * (n - i));
            }
        }
        return res;

    }
};