//
// Created by zhongjiahui on 26-3-22.
//
/*
给你两个大小为 n x n 的二进制矩阵 mat 和 target 。现 以 90 度顺时针轮转 矩阵 mat 中的元素 若干次 ，
如果能够使 mat 与 target 一致，返回 true ；否则，返回 false 。
 */
#include<vector>
using namespace std;
class Solution {
public:
    bool check(vector<vector<int>>& mat, vector<vector<int>>& target) {
        int  n = mat[0].size();
        for(int i=0;i<n;i++) {
            for(int j=0;j<n;j++) {
                if(mat[i][j] != target[i][j]) {
                    return false;
                }
            }
        }
        return true;
    }
    bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target) {
        int  n = mat[0].size();
        vector<vector<int>> temp = mat;
        if (check(mat, target)) {
            return true;
        }
        int times = 3;
        while (times--) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    mat[i][j] = temp[n - 1 - j][i];
                }
            }
            if (check(mat, target)) {
                return true;
            }
            temp = mat;
        }
        return false;
    }
};