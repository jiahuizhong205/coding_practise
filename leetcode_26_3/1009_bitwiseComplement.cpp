//
// Created by zhongjiahui on 26-3-11.
//
/*
每个非负整数 N 都有其二进制表示。例如， 5 可以被表示为二进制 "101"，11 可以用二进制 "1011" 表示，依此类推。注意，除 N = 0 外，任何二进制表示中都不含前导零。

二进制的反码表示是将每个 1 改为 0 且每个 0 变为 1。例如，二进制数 "101" 的二进制反码为 "010"。

给你一个十进制数 N，请你返回其二进制表示的反码所对应的十进制整数。



示例 1：

输入：5
输出：2
解释：5 的二进制表示为 "101"，其二进制反码为 "010"，也就是十进制中的 2 。
示例 2：

输入：7
输出：0
解释：7 的二进制表示为 "111"，其二进制反码为 "000"，也就是十进制中的 0 。
*/

#include<vector>
#include<string>
#include <bits/ranges_algo.h>
#include<algorithm>
#include <cstdint>
using namespace std;
// class Solution {
// public:
//     string TurnToTwo(int n) {
//         if (n == 0)return "0";
//         string ans="";
//         while(n > 0) {
//             if(n & 1) {
//                 ans += "1";
//             }else {
//                 ans += "0";
//             }
//             n >>= 1;
//         }
//         reverse(ans.begin(),ans.end());
//         return ans;
//     }
//     string removeLeadingZeros(string& binStr) {
//         int start = 0;
//         while (start < binStr.size() && binStr[start] == '0') {
//             start++;
//         }
//         if (start == binStr.size()) {
//             return "0";
//         }
//         return binStr.substr(start);
//     }
//     int TurnToTen(string S) {
//         int size=S.size();
//         int res = 0;
//         for (int i = 0; i < size; ++i) {
//             int digit = S[i] - '0';
//             res = res * 2 + digit;
//         }
//         return res;
//     }
//     int bitwiseComplement(int n) {
//         string temp = TurnToTwo(n);
//         for (int i = temp.size() - 1; i >= 0; i--) {
//             if (temp[i] == '0') {
//                 temp[i] = '1';
//             }else {
//                 temp[i] = '0';
//             }
//         }
//         string ans = removeLeadingZeros(temp);
//         return TurnToTen(ans);
//     }
// };


class Solution {
public:
    int bitwiseComplement(int n) {
        if (n == 0) {
            return 1;
        }
        int w = bit_width((uint32_t) n);
        return ((1 << w) - 1) ^ n;
    }
};
/* 异或与n长度相同的全1串即可取反
 * /
