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
    int minimumDeletions(string s) {
        int res = INT_MAX;
        for(int i=0;i<s.size();i++) {
            int temp =0;
            int l =0,r = s.size()-1;
            for(int j = i;j<=r;j++) {
                if (s[j]=='a')temp++;
            }
            for(int j=0;j<i;j++) {
                if(s[j]=='b')temp++;
            }
            res = min(res,temp);
        }
        int b_num = 0;
        for(int i=0;i<s.size();i++) {
            if(s[i]=='b')b_num++;
        }
        return min(res,b_num);
    }
};