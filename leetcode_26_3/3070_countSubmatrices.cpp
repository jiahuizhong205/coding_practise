//
// Created by zhongjiahui on 26-3-18.
//
/*
给你一个下标从 0 开始的整数矩阵 grid 和一个整数 k。

返回包含 grid 左上角元素、元素和小于或等于 k 的 子矩阵的数目。

示例 1：

输入：grid = [[7,6,3],[6,6,1]], k = 18
输出：4
解释：如上图所示，只有 4 个子矩阵满足：包含 grid 的左上角元素，并且元素和小于或等于 18 。
 */
#include<vector>
using namespace std;
class Solution {
public:
    int countSubmatrices(vector<vector<int>>& grid, int k) {
        int m = grid.size(), n = grid[0].size();
        if (grid[0][0] > k)return 0;
        int res = 0;
        vector<vector<long long>> dp(m, vector<long long>(n, 0));
        dp[0][0] = grid[0][0];
        for (int i = 1; i < m; i++) {
            dp[i][0] = grid[i][0] + dp[i - 1][0];
        }
        for (int j = 1; j < n; j++) {
            dp[0][j] = grid[0][j] + dp[0][j - 1];
        }
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                dp[i][j] = dp[i][j - 1] + grid[i][j] + dp[i - 1][j] - dp[i - 1][j - 1];
            }
        }
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (dp[i][j] <= k) res++;
                else break;
            }
        }
        return res;
    }
};