//
// Created by zhongjiahui on 26-3-19.
//
/*
给你一个二维字符矩阵 grid，其中 grid[i][j] 可能是 'X'、'Y' 或 '.'，返回满足以下条件的子矩阵数量：
包含 grid[0][0]
'X' 和 'Y' 的频数相等。
至少包含一个 'X'。

示例 1：
输入： grid = [["X","Y","."],["Y",".","."]]
输出： 3
 */
#include<vector>
using namespace std;
class Solution {
public:
    int numberOfSubmatrices(vector<vector<char>>& grid) {
        int m = grid.size(),n = grid[0].size();
        vector<vector<pair<int,bool>>> dp(m, vector<pair<int,bool>>(n, make_pair(0, false)));
        if(grid[0][0] == 'X') {
            dp[0][0].first = 1;
            dp[0][0].second = true;
        }else if(grid[0][0] == 'Y') {
            dp[0][0].first = -1;
        }
        for(int i = 1; i < m; i++) {
            dp[i][0] = dp[i-1][0];
            if(grid[i][0] == 'X') {
                dp[i][0].first++;
                dp[i][0].second = true;
            }else if(grid[i][0] == 'Y') {
                dp[i][0].first--;
            }
        }
        for(int j = 1; j < n; j++) {
            dp[0][j] = dp[0][j-1];
            if(grid[0][j] == 'X') {
                dp[0][j].first++;
                dp[0][j].second = true;
            }else if(grid[0][j] == 'Y') {
                dp[0][j].first--;
            }
        }
        for(int i = 1; i < m; i++) {
            for(int j = 1; j < n; j++) {
                dp[i][j].first = dp[i-1][j].first + dp[i][j-1].first - dp[i-1][j-1].first;
                if(grid[i][j] == 'X') {
                    dp[i][j].first++;
                }else if(grid[i][j] == 'Y') {
                    dp[i][j].first--;
                }
                if (dp[i-1][j].second || dp[i][j-1].second||grid[i][j]=='X') {
                    dp[i][j].second = true;
                }
            }
        }
        int res = 0;
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(dp[i][j].second&&dp[i][j].first == 0) res++;
            }
        }
        return res;
    }
};