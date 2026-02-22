#include <iosfwd>
//
// Created by zhongjiahui on 26-2-22.
//
/*
给定一个正整数 n，找到并返回 n 的二进制表示中两个 相邻 1 之间的 最长距离 。如果不存在两个相邻的 1，返回 0 。

如果只有 0 将两个 1 分隔开（可能不存在 0 ），则认为这两个 1 彼此 相邻 。两个 1 之间的距离是它们的二进制表示中位置的绝对差。例如，"1001" 中的两个 1 的距离为 3 。

示例 1：
输入：n = 22
输出：2
解释：22 的二进制是 "10110" 。
在 22 的二进制表示中，有三个 1，组成两对相邻的 1 。
第一对相邻的 1 中，两个 1 之间的距离为 2 。
第二对相邻的 1 中，两个 1 之间的距离为 1 。
答案取两个距离之中最大的，也就是 2 。

 */
#include<bits/stdc++.h>
using namespace std;
//
// class Solution {
// public:
//     int binaryGap(int n) {
//     string s = "";
//         int flag = 0;
//         while (n) {
//             if (n%2 == 1) {
//                 s += "1";
//                 n/=2;
//                 flag++;
//             }else {
//                 s += "0";
//                 n/=2;
//             }
//         }
//         if (flag <= 1) return 0;
//         reverse(s.begin(), s.end());
//         int res = 0;
//         int temp = -1;
//         for (int i = 0; i < s.size(); ++i) {
//             if (s[i] == '1') {
//                 if (temp == -1) {
//                     temp = i;
//                 }else {
//                     res = max(res, i - temp);
//                 }
//                 temp = i;
//             }
//         }
//         return res;
//     }
// };

//位运算
class Solution {
    public:
    int binaryGap(int n) {
        int res = 0;
        int temp = -1;
        int now = 0;
        while (n > 0) {
            if (n&1) {
                if (temp != -1) {
                    res = max(res, now - temp);
                }
                temp = now;
            }
            n >>=1;
            now++;
        }
        return res;
    }
};