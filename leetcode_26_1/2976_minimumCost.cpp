//
// Created by zhongjiahui on 26-1-29.
//
#include <iostream>
#include<string>
#include<vector>
#include<map>
#include <ostream>
using namespace std;
/*全源最短路问题
使用Floyd算法解决
*/
class Solution {
public:
    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
        const int INF = INT_MAX / 2;
        vector<vector<int>> dist(26, vector<int>(26, INF));
        for (int i = 0; i < 26; i++) {
            dist[i][i] = 0;
        }

        int m = original.size();
        for (int i = 0; i < m; i++) {
            int from = original[i] - 'a';
            int to = changed[i] - 'a';
            int c = cost[i];
            dist[from][to] = min(dist[from][to], c);
        }

        for (int k = 0; k < 26; k++) {
            for (int i = 0; i < 26; i++) {
                for (int j = 0; j < 26; j++) {
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        }

        long long ans = 0;
        int n = source.size();
        for (int i = 0; i < n; i++) {
            int s = source[i] - 'a';
            int t = target[i] - 'a';
            if (dist[s][t] == INF) {
                return -1;
            }
            ans += dist[s][t];
        }

        return ans;
    }
};

int main() {
    string source = "ABCD";
    string target = "ACBE";
    vector<char> original = {'a','b','c','c','e','d'};
    vector<char> changed = {'b','c','b','e','b','e'};
    vector<int> cost = {2,5,5,1,2,20};
    Solution s;
    cout << s.minimumCost(source, target, original, changed, cost) << endl;
}
