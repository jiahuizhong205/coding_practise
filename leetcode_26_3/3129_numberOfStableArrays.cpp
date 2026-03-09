//
// Created by zhongjiahui on 26-3-9.
//
/*
给你 3 个正整数 zero ，one 和 limit 。

一个 二进制数组 arr 如果满足以下条件，那么我们称它是 稳定的 ：

0 在 arr 中出现次数 恰好 为 zero 。
1 在 arr 中出现次数 恰好 为 one 。
arr 中每个长度超过 limit 的 子数组 都 同时 包含 0 和 1 。
请你返回 稳定 二进制数组的 总 数目。

由于答案可能很大，将它对 109 + 7 取余 后返回。

示例 1：
输入：zero = 1, one = 1, limit = 2
输出：2
解释：
两个稳定的二进制数组为 [1,0] 和 [0,1] ，两个数组都有一个 0 和一个 1 ，且没有子数组长度大于 2 。
 */
#include<vector>
using namespace std;
// class Solution {
// public:
// #define MOD 1000000007
//     long long mul_mod(long long a, long long b,long long mod) {
//         long long res = 0;
//         a = a%mod;
//         while (b > 0) {
//             if (b & 1) {
//                 res = (res + a) % mod;
//             }
//             a = (a * 2) % mod;
//             b >>= 1;
//         }
//         return res % mod;
//     }
//     int numberOfStableArrays(int zero, int one, int limit) {
//         if (zero > limit|| one > limit) return 0;
//         long long res = 1;
//         int total = zero + one;
//         int k = (zero < one )?zero:one;
//         for (int i = 1;i <= k;++i) {
//             res = mul_mod(res,(total - k +i)%MOD,MOD);
//             long long inv = 1;
//             long long base = i % MOD;
//             int exp = MOD -2;
//             while (exp > 0) {
//                 if (exp %2 == 1) {
//                     inv = mul_mod(inv,base,MOD);
//                 }
//                 base = mul_mod(base,base,MOD);
//                 exp = exp/2;
//             }
//             res = mul_mod(res,inv,MOD);
//         }
//         return res;
//     }
// };
// 子数组是连续的，不能直接当作组合数来做，上述解法错误，通过一半的测试点



class Solution {
public:
#define MOD 1000000007
    vector<vector<vector<int>>> memo;

    int dfs(int i, int j, int limit, int k) {
        if (i == 0) {
            return (k == 1 && j <= limit) ? 1 : 0;
        }
        if (j == 0) {
            return (k == 0 && i <= limit) ? 1 : 0;
        }

        //记忆化检查，已计算过直接返回
        if (memo[i][j][k] != -1) {
            return memo[i][j][k];
        }

        long long res = 0; //用long long避免溢出
        if (k == 0) {
            res = (dfs(i-1, j, limit, 0) % MOD + dfs(i-1, j, limit, 1) % MOD) % MOD;

            if (i > limit) {
                res = (res - dfs(i - limit - 1, j, limit, 1) % MOD + MOD) % MOD;
            }
        } else if (k == 1) {
            res = (dfs(i, j - 1, limit, 0) % MOD + dfs(i, j - 1, limit, 1) % MOD) % MOD;
            if (j > limit) {
                res = (res - dfs(i, j - limit - 1, limit, 0) % MOD + MOD) % MOD;
            }
        }

        memo[i][j][k] = res % MOD;
        return memo[i][j][k];
    }
        int numberOfStableArrays(int zero, int one, int limit) {
        //初始化记忆化数组，大小为(zero+1)x(one+1)x2，初始值-1
        memo = vector<vector<vector<int>>>(zero + 1,
                    vector<vector<int>>(one + 1, vector<int>(2, -1)));
        //结果相加后取模，且用long long避免溢出
        long long total = (dfs(zero, one, limit, 0) + dfs(zero, one, limit, 1)) % MOD;
        return total;
    }
};
/*
*考虑稳定数组的最后一个位置填 0 还是 1：

填 0，问题变成剩下 2 个 0 和 3 个 1 怎么填。
填 1，问题变成剩下 3 个 0 和 2 个 1 怎么填。
这两个都是和原问题相似的子问题。
看上去，定义 dfs(i,j) 表示用 i 个 0 和 j 个 1 构造稳定数组的方案数？但这样定义不方便计算 limit 带来的影响。

改成定义 dfs(i,j,k) 表示用 i 个 0 和 j 个 1 构造稳定数组的方案数，其中第 i+j 个位置要填 k，其中 k 为 0 或 1。

考虑 dfs(i,j,0) 怎么算。现在，第 i+j 个位置填的是 0，考虑第 i+j−1 个位置要填什么：

填 0，方案数就是 dfs(i−1,j,0)。
填 1，方案数就是 dfs(i−1,j,1)。
看上去，把这两种情况加起来，我们就得到了 dfs(i,j,0)。但是，这个过程中会产生不合法的情况。

假设 limit=3，dfs(i−1,j,0) 是一些以 0 结尾的稳定数组（合法数组），考虑末尾 0 的个数：

末尾有 1 个 0：那么末尾必定是 10。
末尾有 2 个 0：那么末尾必定是 100。
末尾有 3 个 0：那么末尾必定是 1000。注意，由于末尾不能超过 3 个 0，所以这样的稳定数组的倒数第 4 个数一定是 1，也就是在 dfs(i−1,j,0) 中有 dfs(i−4,j,1) 个末尾是 1000 的稳定数组。
若要通过 dfs(i−1,j,0) 计算 dfs(i,j,0)，相当于往这 dfs(i−1,j,0) 个稳定数组的末尾再加一个 0：

末尾有 2 个 0，即 100，这是合法的。
末尾有 3 个 0，即 1000，这是合法的。
末尾有 4 个 0，即 10000，这是不合法的，要全部去掉！根据上面的分析，要减去 dfs(i−4,j,1)。
一般地，因为 dfs 的定义是稳定数组的方案数，只包含合法方案，所以在最后连续 limit 个位置填 0 的情况下，倒数第 limit+1 个位置一定要填 1，这有 dfs(i−limit−1,j,1) 种方案。对于 dfs(i,j,0) 来说，这 dfs(i−limit−1,j,1) 个方案就是不合法方案了，要减掉，得

dfs(i,j,0)=dfs(i−1,j,0)+dfs(i−1,j,1)−dfs(i−limit−1,j,1)
同理得

dfs(i,j,1)=dfs(i,j−1,0)+dfs(i,j−1,1)−dfs(i,j−limit−1,0)
递归边界 1：如果 i<0 或者 j<0，返回 0。也可以在递归 dfs(i−limit−1,j,1) 前判断 i>limit，在递归 dfs(i,j−limit−1,0) 前判断 j>limit。下面代码在递归前判断。

递归边界 2：如果 i=0，那么当 k=1 且 j≤limit 的情况下返回 1，否则返回 0；如果 j=0，那么当 k=0 且 i≤limit 的情况下返回 1，否则返回 0。

递归入口：dfs(zero,one,0)+dfs(zero,one,1)，即答案。

作者：灵茶山艾府
链接：https://leetcode.cn/problems/find-all-possible-stable-binary-arrays-ii/solutions/2758868/dong-tai-gui-hua-cong-ji-yi-hua-sou-suo-37jdi/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
*/