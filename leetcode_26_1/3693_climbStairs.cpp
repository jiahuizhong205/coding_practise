//
// Created by zhongjiahui on 26-1-28.
//
#include<vector>
using namespace std;
class Solution {
public:
    int climbStairs(int n, vector<int>& costs) {
        vector<int> dp(n + 1,0);
        if (n == 1)return costs[0] + 1;
        if (n == 2) return min(4 + costs[1],1 + costs[0] + 1 + costs[1]);
        dp[n - 1] = 1 + costs[n - 1];
        dp[n - 2] = min(4 + costs[n - 1],1 + dp[n - 1] + costs[n - 2]);
        dp[n - 3] = min(min(9 + costs[n - 1],4 + costs[n - 2] + dp[n - 1]),1 + costs[n - 3] + dp[n - 2]);
        for(int i = n - 4; i >= 0; i--) {
            dp[i] = min(dp[i + 1] + 1 + costs[i ],
                min(dp[i + 2] + 4 + costs[i + 1],dp[i + 3] + 9 + costs[i + 2]));
        }
        return dp[0];
    }
};