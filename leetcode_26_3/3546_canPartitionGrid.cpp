//
// Created by zhongjiahui on 26-3-26.
//
/*
给你一个由正整数组成的 m x n 矩阵 grid。你的任务是判断是否可以通过 一条水平或一条垂直分割线 将矩阵分割成两部分，使得：

分割后形成的每个部分都是 非空 的。
两个部分中所有元素的和 相等 。
如果存在这样的分割，返回 true；否则，返回 false。
 */

#include<vector>
using namespace std;
class Solution {
public:
    bool canPartitionGrid(vector<vector<int>>& grid) {
        int m = grid.size(),n = grid[0].size();
        vector<long long> row(m, 0);
        vector<long long> col(n, 0);
        for (int i = 0; i < m; i++) {
            long long temp = 0;
            for (int j = 0; j < n; j++) {
                temp += grid[i][j];
            }
            row[i] = temp;
        }
        for (int j = 0; j < n; j++) {
            long long temp = 0;
            for (int i = 0; i < m; i++) {
                temp += grid[i][j];
            }
            col[j] = temp;
        }
        long long sum = 0;
        for (int i = 0; i < m; i++) {
            sum += row[i];
        }
        long long temp = 0;
        for (int i = 0; i < m; i++) {
            temp+=row[i];
            if (temp == sum / 2) {
                return true;
            }
            else if (temp > sum / 2) {
                break;
            }
        }
        temp = 0;
        for (int i = 0; i < n; i++) {
            temp += col[i];
            if (temp == sum / 2) {
                return true;
            }
            else if (temp > sum / 2) {
                return false;
            }
        }
        return false;
    }
};