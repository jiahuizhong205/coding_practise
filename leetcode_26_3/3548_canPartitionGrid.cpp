#include <vector>
#include <unordered_set>
#include <cmath>
using namespace std;

class Solution {
public:
    int m, n;
    vector<vector<int>> g;

    bool canPartitionGrid(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();
        g = grid;

        long long total = 0;
        for (auto& row : grid) for (int x : row) total += x;

        vector<long long> rowSum(m, 0);
        for (int i = 0; i < m; i++)
            for (int x : grid[i]) rowSum[i] += x;
        vector<long long> preRow(m + 1, 0);
        for (int i = 0; i < m; i++) preRow[i+1] = preRow[i] + rowSum[i];

        vector<long long> colSum(n, 0);
        for (int j = 0; j < n; j++)
            for (int i = 0; i < m; i++) colSum[j] += grid[i][j];
        vector<long long> preCol(n + 1, 0);
        for (int j = 0; j < n; j++) preCol[j+1] = preCol[j] + colSum[j];

        for (int split = 1; split < m; split++) {
            long long s1 = preRow[split];
            long long s2 = total - s1;
            if (check(s1, s2, split, n, true)) return true;
        }

        for (int split = 1; split < n; split++) {
            long long s1 = preCol[split];
            long long s2 = total - s1;
            if (check(s1, s2, m, split, false)) return true;
        }

        return false;
    }

    bool check(long long a, long long b, int h, int w, bool isHorizontal) {
        if (a == b) return true;

        long long diff = abs(a - b);
        if (isHorizontal) {
            return hasValidCell(h, w, diff);
        } else {
            return hasValidCell(h, w, diff);
        }
    }

    bool hasValidCell(int h, int w, long long v) {
        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                if (g[i][j] != v) continue;

                if (h > 1 && w > 1) return true;

                if (h == 1) {
                    if (j == 0 || j == w-1) return true;
                }

                if (w == 1) {
                    if (i == 0 || i == h-1) return true;
                }
            }
        }
        return false;
    }
};