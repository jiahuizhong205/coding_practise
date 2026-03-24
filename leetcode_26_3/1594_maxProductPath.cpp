//
// Created by zhongjiahui on 26-3-23.
//
/*
给你一个大小为 m x n 的矩阵 grid 。最初，你位于左上角 (0, 0) ，每一步，你可以在矩阵中 向右 或 向下 移动。

在从左上角 (0, 0) 开始到右下角 (m - 1, n - 1) 结束的所有路径中，
找出具有 最大非负积 的路径。路径的积是沿路径访问的单元格中所有整数的乘积。
返回 最大非负积 对 109 + 7 取余 的结果。如果最大积为 负数 ，则返回 -1 。

注意，取余是在得到最大积之后执行的。
 */

#include<vector>
using namespace std;
class Solution {
#define MOD 1000000007
public:
    int maxProductPath(vector<vector<int>>& grid) {
        int m = grid.size(),n = grid[0].size();
        vector<vector<pair<long long,long long>>> dp(m,vector<pair<long long ,long long>>(n,{0,0}));
        dp[0][0].first = grid[0][0];
        dp[0][0].second = grid[0][0];
        for(int i=1;i<m;i++) {
            dp[i][0].first = max((grid[i][0] * dp[i-1][0].first),(grid[i][0] * dp[i-1][0].second));
            dp[i][0].second = min((grid[i][0] * dp[i-1][0].first),(grid[i][0] * dp[i-1][0].second));
        }
        for(int j=1;j<n;j++) {
            dp[0][j].first = max((grid[0][j] * dp[0][j-1].first),(grid[0][j] * dp[0][j-1].second));
            dp[0][j].second = min((grid[0][j] * dp[0][j-1].first),(grid[0][j] * dp[0][j-1].second));
        }
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                dp[i][j].first = max((grid[i][j] * dp[i - 1][j].first),
                    max((grid[i][j]*dp[i - 1][j].second),
                        max((grid[i][j]*dp[i][j - 1].second),(grid[i][j]*dp[i][j - 1].first)))
                    );
                dp[i][j].second = min((grid[i][j] * dp[i - 1][j].first),
                    min((grid[i][j]*dp[i - 1][j].second),
                        min((grid[i][j]*dp[i][j - 1].second),(grid[i][j]*dp[i][j - 1].first)))
                    );
            }
        }
        if (dp[m - 1][n - 1].first < 0) return -1;
        return dp[m - 1][n - 1].first%MOD;

    }
};