//
// Created by zhongjiahui on 26-2-7.
//
/*
给你一个字符串 s ，它仅包含字符 'a' 和 'b'。

你可以删除 s 中任意数目的字符，使得 s 平衡 。当不存在下标对 (i,j) 满足 i < j ，且 s[i] = 'b' 的同时 s[j]= 'a' ，此时认为 s 是 平衡 的。

请你返回使 s 平衡 的 最少 删除次数。



示例 1：

输入：s = "aababbab"
输出：2
解释：你可以选择以下任意一种方案：
下标从 0 开始，删除第 2 和第 6 个字符（"aababbab" -> "aaabbb"），
下标从 0 开始，删除第 3 和第 6 个字符（"aababbab" -> "aabbbb"）。
*/
#include<vector>
#include<string>
using namespace std;
class Solution {
public:
    // 方法一前后缀
    // int minimumDeletions(string s) {
    //     int a_num = 0;
    //     for(int i=0;i<s.size();i++) {
    //         if(s[i]=='a')a_num++;
    //     }
    //     int res = a_num;
    //     int b_num = 0;
    //     for (int i = 0;i<s.size();i++) {
    //         if(s[i]=='a') {
    //             a_num--;
    //         }else {
    //             b_num++;
    //         }
    //         res = min(res,a_num + b_num);
    //     }
    //     return res;
    // }

    //方法二dp
//     考虑 s 的最后一个字母：
//
// 如果它是 ‘b’，则无需删除，问题规模缩小，变成「使 s 的前 n−1 个字母平衡的最少删除次数」。
// 如果它是 ‘a’：
// 删除它，则答案为「使 s 的前 n−1 个字母平衡的最少删除次数」加上 1。
// 保留它，那么前面的所有 ‘b’ 都要删除；
// 设 cntB 为前 i 个字母中 ‘b’ 的个数。定义 f[i] 表示使 s 的前 i 个字母平衡的最少删除次数：
//
// 如果第 i 个字母是 ‘b’，则 f[i]=f[i−1]；
// 如果第 i 个字母是 ‘a’，则 f[i]=min(f[i−1]+1,cntB)。
//
//
// 作者：灵茶山艾府
// 链接：https://leetcode.cn/problems/minimum-deletions-to-make-string-balanced/solutions/2149746/qian-hou-zhui-fen-jie-yi-zhang-tu-miao-d-dor2/
    int minimumDeletions(string s) {
        int bCount = 0;
        int f = 0;
        for (char c : s) {
            if (c == 'b') {
                ++bCount;
            }
            else {
                f = min(f + 1, bCount);
            }
        }
        return f;
    }
};