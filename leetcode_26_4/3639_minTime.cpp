//
// Created by zhongjiahui on 26-4-20.
//
/*
给你一个长度为 n 的字符串 s 和一个整数数组 order，其中 order 是范围 [0, n - 1] 内数字的一个 排列。
从时间 t = 0 开始，在每个时间点，将字符串 s 中下标为 order[t] 的字符替换为 '*'。
如果 子字符串 包含 至少 一个 '*' ，则认为该子字符串有效。
如果字符串中 有效子字符串 的总数大于或等于 k，则称该字符串为 活跃 字符串。
返回字符串 s 变为 活跃 状态的最小时间 t。如果无法变为活跃状态，返回 -1。
示例 1:
输入: s = "abc", order = [1,0,2], k = 2
输出: 0
 */

#include<vector>
#include<string>
using namespace std;
// class Solution {
// public:
//     bool isValid(string& s,int k) {
//         int n = s.size();
//         long long cnt = 0;
//         int left = 0;
//
//         while (left < n) {
//             int right = left;
//             while (right < n && s[right] != '*') {
//                 right++;
//             }
//             if (right == n) {
//                 break;
//             }
//             cnt += n - right;
//             left++;
//         }
//
//         return cnt >= k;
//     }
//     int minTime(string s, vector<int>& order, int k) {
//         int n = order.size();
//         int total = (long long)n * (n + 1) / 2;
//         if (total < k) {
//             return -1;
//         }
//         int left = 0, right = n - 1;
//         while (left < right) {
//             int mid = left + (right - left) / 2;
//             string t = s;
//             for (int i = 0; i <= mid; i++) {
//                 t[order[i]] = '*';
//             }
//             if (isValid(t,k)) {
//                 right = mid;
//             }else {
//                 left = mid + 1;
//             }
//         }
//         return right;
//     }
// };


// class Solution {
// public:
//     int minTime(string s, vector<int>& order, int k) {
//         int n = s.size();
//         long long total = (long long)n * (n + 1) / 2;
//         if (total < k) return -1;
//
//         vector<bool> is_star(n, false);
//         long long cnt = 0;
//
//         for (int t = 0; t < n; ++t) {
//             int pos = order[t];
//             if (is_star[pos]) continue;
//             is_star[pos] = true;
//
//             int L = 0;
//             for (int i = pos - 1; i >= 0 && !is_star[i]; --i) L++;
//             int R = 0;
//             for (int i = pos + 1; i < n && !is_star[i]; ++i) R++;
//
//             cnt += (long long)(L + 1) * (R + 1);
//
//             if (cnt >= k) {
//                 return t;
//             }
//         }
//
//         return -1;
//
//     }
// };

class Solution {
public:
 long long countValid(int n, vector<bool>& isStar) {
  long long res = 0;
  int len = 0;
  for (int i = 0; i < n; ++i) {
   if (isStar[i]) {
    len = 0;
   } else {
    len++;      
    res += len;
   }
  }

  long long total = (long long)n * (n + 1) / 2;
  return total - res;
 }

 int minTime(string s, vector<int>& order, int k) {
  int n = s.size();
  long long totalSub = (long long)n * (n + 1) / 2;
  if (totalSub < k) return -1;


  int l = 0, r = n - 1;
  int ans = n;
  vector<bool> isStar(n);

  while (l <= r) {
   int mid = l + (r - l) / 2;
   fill(isStar.begin(), isStar.end(), false);

   for (int i = 0; i <= mid; ++i) {
    isStar[order[i]] = true;
   }

   long long cnt = countValid(n, isStar);

   if (cnt >= k) {
    ans = mid;
    r = mid - 1;
   } else {
    l = mid + 1;
   }
  }
  return ans;

 }
};
