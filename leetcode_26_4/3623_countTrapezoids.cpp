//
// Created by zhongjiahui on 26-4-23.
//
/*
给你一个二维整数数组 points，其中 points[i] = [xi, yi]
表示第 i 个点在笛卡尔平面上的坐标。

水平梯形 是一种凸四边形，具有 至少一对 水平边（即平行于 x 轴的边）。
两条直线平行当且仅当它们的斜率相同。
返回可以从 points 中任意选择四个不同点组成的 水平梯形 数量。
由于答案可能非常大，请返回结果对 109 + 7 取余数后的值。
示例 1：
输入： points = [[1,0],[2,0],[3,0],[2,2],[3,2]]
输出： 3
 */
#include <unordered_map>
#include<vector>
using namespace std;
class Solution {
#define MOD 1000000007
public:
    int countTrapezoids(vector<vector<int>>& points) {
        unordered_map<int, int> map;
        for(int i=0;i<points.size();i++) {
            map[points[i][1]]++;
        }
        long long ans = 0, s = 0;
        for (auto& [_, c] : map) {
            long long k = 1LL * c * (c - 1) / 2;
            ans += s * k;
            s += k;
        }
        return ans % MOD;
    }
};