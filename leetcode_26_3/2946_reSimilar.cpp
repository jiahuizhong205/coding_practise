//
// Created by zhongjiahui on 26-3-27.
//
/*
给你一个下标从 0 开始且大小为 m x n 的整数矩阵 mat 和一个整数 k 。矩阵行的下标是从 0 开始的。

进行下面操作 k 次：
偶数行（0, 2, 4, ...）循环向左移动。
奇数行（1, 3, 5, ...）循环向右移动。

如果经过 k 步后的最终修改矩阵与原始矩阵相同，则返回 true，否则返回 false。
 */
#include<vector>
using namespace std;
//
// Created by zhongjiahui on 26-3-27.
//
/*
给你一个下标从 0 开始且大小为 m x n 的整数矩阵 mat 和一个整数 k 。矩阵行的下标是从 0 开始的。

进行下面操作 k 次：
偶数行（0, 2, 4, ...）循环向左移动。
奇数行（1, 3, 5, ...）循环向右移动。

如果经过 k 步后的最终修改矩阵与原始矩阵相同，则返回 true，否则返回 false。
 */
#include<vector>
using namespace std;
class Solution {
public:
    bool areSimilar(vector<vector<int>>& mat, int k) {
        int m = mat.size();
        int n = mat[0].size();
        int shift = k % n;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (i % 2 == 0) {
                    if (mat[i][j] != mat[i][(j + shift) % n]) {
                        return false;
                    }
                } else {
                    if (mat[i][j] != mat[i][(j - shift + n) % n]) {
                        return false;
                    }
                }
            }
        }
        return true;
    }
};