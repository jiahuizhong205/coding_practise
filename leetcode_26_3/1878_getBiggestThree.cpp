//
// Created by zhongjiahui on 26-3-16.
//
/*
给你一个 m x n 的整数矩阵 grid 。

菱形和 指的是 grid 中一个正菱形 边界 上的元素之和。本题中的菱形必须为正方形旋转45度，且四个角都在一个格子当中。下图是四个可行的菱形，每个菱形和应该包含的格子都用了相应颜色标注在图中。

注意，菱形可以是一个面积为 0 的区域，如上图中右下角的紫色菱形所示。

请你按照 降序 返回 grid 中三个最大的 互不相同的菱形和 。如果不同的和少于三个，则将它们全部返回。



示例 1：

输入：grid = [[3,4,5,1,3],[3,3,4,2,3],[20,30,200,40,10],[1,5,5,4,1],[4,3,2,2,5]]
输出：[228,216,211]
解释：最大的三个菱形和如上图所示。
- 蓝色：20 + 3 + 200 + 5 = 228
- 红色：200 + 2 + 10 + 4 = 216
- 绿色：5 + 200 + 4 + 2 = 211
 */

#include <algorithm>
#include <ranges>
#include <unordered_set>
#include<vector>
using namespace std;
class Solution {
public:
    int getCur(vector<vector<int>>& grid,int i,int j,int m,int n,int l) {
        if (i + 2 * l >= m || j - l < 0 || j + l >= n) {
            return 0;
        }
        int res = 0;
        res = grid[i][j] + grid[i + l][j - l] + grid[i + l][j + l] + grid[i + 2 * l][j];

        for (int t = 1; t < l; t++) {
            res += grid[i + t][j - t];        // 左上
            res += grid[i + t][j + t];        // 右上
            res += grid[i + 2*l - t][j - t];  // 左下
            res += grid[i + 2*l - t][j + t];// 右下
        }
        return res;
    }
    vector<int> getBiggestThree(vector<vector<int>>& grid) {
        unordered_set<int> s;  // 自动去重
        int m = grid.size(), n = grid[0].size();

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                s.insert(grid[i][j]);

                int maxL = min(n,m);
                maxL = (maxL + 1)/2;
                for (int l = 1; l <= maxL; l++) {
                    int cur = getCur(grid, i, j, l, m, n);
                    if (cur > 0) {
                        s.insert(cur);
                    }
                }
            }
        }

        vector<int> res(s.begin(), s.end());
        sort(res.rbegin(), res.rend());

        if (res.size() > 3) {
            res.resize(3);
        }
        return res;

    }
};