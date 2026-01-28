//
// Created by zhongjiahui on 26-1-28.
//
#include <iostream>
#include <ostream>
#include<vector>
using namespace std;
class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        vector<int> dp(cost.size(), 0);
        int n = cost.size();
        dp[n-1] = cost[n-1];
        dp[n-2] = cost[n-2];
        for (int i = n-3; i >= 0; i--) {
            dp[i] = min(dp[i+1] + cost[i], dp[i+2] + cost[i]);
        }
        return min(dp[0], dp[1]);
    }
};
int main() {
    vector<int> cost = {1,100,1,1,1,100,1,1,100,1};
    Solution s;
    s.minCostClimbingStairs(cost);
    cout <<s.minCostClimbingStairs(cost)<< endl;
    return 0;
}