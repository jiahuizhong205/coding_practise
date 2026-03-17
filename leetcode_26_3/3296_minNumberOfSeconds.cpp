//
// Created by zhongjiahui on 26-3-17.
//
/*
给你一个整数 mountainHeight 表示山的高度。

同时给你一个整数数组 workerTimes，表示工人们的工作时间（单位：秒）。

工人们需要 同时 进行工作以 降低 山的高度。对于工人 i :

山的高度降低 x，需要花费 workerTimes[i] + workerTimes[i] * 2 + ... + workerTimes[i] * x 秒。例如：
山的高度降低 1，需要 workerTimes[i] 秒。
山的高度降低 2，需要 workerTimes[i] + workerTimes[i] * 2 秒，依此类推。
返回一个整数，表示工人们使山的高度降低到 0 所需的 最少 秒数。

示例 1：

输入： mountainHeight = 4, workerTimes = [2,1,1]
输出： 3
解释：
将山的高度降低到 0 的一种方式是：
工人 0 将高度降低 1，花费 workerTimes[0] = 2 秒。
工人 1 将高度降低 2，花费 workerTimes[1] + workerTimes[1] * 2 = 3 秒。
工人 2 将高度降低 1，花费 workerTimes[2] = 1 秒。
因为工人同时工作，所需的最少时间为 max(2, 3, 1) = 3 秒。
 */

#include <cmath>
#include <ctime>
#include <queue>
#include<vector>
#include <bits/locale_classes.h>
#include <bits/ranges_algo.h>
using namespace std;
// class Solution {
// public:
//     long long minNumberOfSeconds(int mountainHeight, vector<int>& workerTimes) {
//         priority_queue<vector<long long>,vector<vector<long long>>,greater<vector<long long>>> pq;
//         long long res = 0;
//         for(int i=0;i<workerTimes.size();i++) {
//             pq.push({workerTimes[i],0,workerTimes[i]});
//         }
//         int count = mountainHeight;
//         while (count--) {
//             auto cur = pq.top();
//             pq.pop();
//             long long next_total = cur[0];
//             long long k = cur[1];
//             long long w = cur[2];
//             k++;
//             res= max(res,next_total);
//             long long total = w *(k+1) *(k+2)/2;
//             pq.push({total,k,w});
//         }
//         return res;
//     }
// };
//最小堆加贪心


class Solution {
public:
 long long minNumberOfSeconds(int mountainHeight, vector<int>& workerTimes) {
  auto check = [&](long long m) {
   int left_h = mountainHeight;
   for (int t : workerTimes) {
    left_h -= ((int) sqrt(m / t * 8 + 1) - 1) / 2;
    if (left_h <= 0) {
     return true;
    }
   }
   return false;
  };

  int max_t = ranges::max(workerTimes);
  int h = (mountainHeight - 1) / workerTimes.size() + 1;
  long long left = 0, right = (long long) max_t * h * (h + 1) / 2;
  while (left + 1 < right) {
   long long mid = (left + right) / 2;
   (check(mid) ? right : left) = mid;
  }
  return right;
 }
};
//二分答案，由于花的时间越多，能够降低的高度也越多，所以有单调性，可以二分答案。
// 作者：灵茶山艾府
// 链接：https://leetcode.cn/problems/minimum-number-of-seconds-to-make-mountain-height-zero/solutions/2925848/er-fen-da-an-pythonjavacgo-by-endlessche-myg4/
// 来源：力扣（LeetCode）
// 著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。