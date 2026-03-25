//
// Created by zhongjiahui on 26-3-25.
//
/*
给你一个 m x n 的整数矩阵 grid 和一个整数 k。

对于矩阵 grid 中的每个连续的 k x k 子矩阵，计算其中任意两个 不同值 之间的 最小绝对差 。

返回一个大小为 (m - k + 1) x (n - k + 1) 的二维数组 ans，其中 ans[i][j] 表示以 grid 中坐标 (i, j) 为左上角的子矩阵的最小绝对差。

注意：如果子矩阵中的所有元素都相同，则答案为 0。

子矩阵 (x1, y1, x2, y2) 是一个由选择矩阵中所有满足 x1 <= x <= x2 且 y1 <= y <= y2 的单元格 matrix[x][y] 组成的矩阵。

 */
#include <cmath>
#include <map>
#include<vector>
using namespace std;
class Solution {
public:
    vector<vector<int>> minAbsDiff(vector<vector<int>>& grid, int k) {
        int m = grid.size(),n = grid[0].size();
        vector<vector<int>> res(m - k + 1,vector<int>(n - k + 1 ,0));
        if (k == 1) {
            return res;
        }
        for (int i = 0; i < m - k + 1; i++) {
            for (int j = 0; j < n - k + 1; j++) {

                map<int,int> cnt;
                for (int x = i; x < i + k; x++) {
                    for (int y = j; y < j + k; y++) {
                        cnt[grid[x][y]]++;
                    }
                }
                if (cnt.size() == 1) {
                    res[i][j] = 0;
                    continue;
                }
                int min_diff = INT_MAX;
                auto it = cnt.begin();
                int pre = it->first;
                ++it;
                for (; it != cnt.end(); ++it) {
                    int cur = it->first;
                    min_diff = min(min_diff, cur - pre);
                    pre = cur;
                }
                res[i][j] = min_diff;
            }
        }
        return res;
    }
};