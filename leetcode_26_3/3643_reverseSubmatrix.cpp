//
// Created by zhongjiahui on 26-3-21.
//
/*
给你一个 m x n 的整数矩阵 grid，以及三个整数 x、y 和 k。
整数 x 和 y 表示一个 正方形子矩阵 的左上角下标，整数 k 表示该正方形子矩阵的边长。
你的任务是垂直翻转子矩阵的行顺序。
返回更新后的矩阵。
 */
#include<vector>
using namespace std;
class Solution {
public:
    vector<vector<int>> reverseSubmatrix(vector<vector<int>>& grid, int x, int y, int k) {
        int temp = 0;
        for (int i = 0;i < k/2; i++) {
            for (int j = 0; j < k; j++) {
                temp = grid[x + i][y + j];
                grid[x + i][y + j] = grid[x + k - i - 1][y + j];
                grid[x + k - i - 1][y + j] = temp;
            }
        }
        return grid;
    }
};