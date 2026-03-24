//
// Created by zhongjiahui on 26-3-24.
//
/*
给你一个下标从 0 开始、大小为 n * m 的二维整数矩阵 grid ，
定义一个下标从 0 开始、大小为 n * m 的的二维矩阵 p。如果满足以下条件，则称 p 为 grid 的 乘积矩阵 ：

对于每个元素 p[i][j] ，它的值等于除了 grid[i][j] 外所有元素的乘积。乘积对 12345 取余数。
返回 grid 的乘积矩阵。
 */

#include<vector>
using namespace std;
class Solution {
#define MOD 12345
public:
    vector<vector<int>> constructProductMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int total = n * m;
        vector<int> pre(total, 1);
        vector<int> suf(total, 1);
        for (int i = 1; i < total; ++i) {
            int x = (i-1)/m, y = (i-1)%m;
            pre[i] = (long long)pre[i-1] * grid[x][y] % MOD;
        }

        for (int i = total-2; i >= 0; --i) {
            int x = (i+1)/m, y = (i+1)%m;
            suf[i] = (long long)suf[i+1] * grid[x][y] % MOD;
        }

        vector<vector<int>> res(n, vector<int>(m));
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                int idx = i * m + j;
                res[i][j] = (long long)pre[idx] * suf[idx] % MOD;
            }
        }
        return res;
    }
};