//
// Created by zhongjiahui on 26-3-28.
//
/*
对任一由 n 个小写英文字母组成的字符串 word ，我们可以定义一个 n x n 的矩阵，并满足：

lcp[i][j] 等于子字符串 word[i,...,n-1] 和 word[j,...,n-1] 之间的最长公共前缀的长度。
给你一个 n x n 的矩阵 lcp 。返回与 lcp 对应的、按字典序最小的字符串 word 。如果不存在这样的字符串，则返回空字符串。

对于长度相同的两个字符串 a 和 b ，如果在 a 和 b 不同的第一个位置，字符串 a 的字母在字母表中出现的顺序先于 b 中的对应字母，则认为字符串 a 按字典序比字符串 b 小。例如，"aabd" 在字典上小于 "aaca" ，因为二者不同的第一位置是第三个字母，而 'b' 先于 'c' 出现。

示例 1：
输入：lcp = [[4,0,2,0],[0,3,0,1],[2,0,2,0],[0,1,0,1]]
输出："abab"
解释：lcp 对应由两个交替字母组成的任意 4 字母字符串，字典序最小的是 "abab" 。
 */

#include<vector>
#include<string>
using namespace std;
class Solution {
public:
    string findTheString(vector<vector<int>>& lcp) {
        int n = lcp.size();
        string s(n,0);
        int i = 0;
        for (char c = 'a'; c <= 'z'; c++) {
            for (int j = 0; j < n; j++) {
                if (lcp[i][j])s[j] = c;
            }
            while (i < n&&s[i])i++;
            if (i == n)break;
        }
        if (i < n) return "";

        vector<vector<int>> check(n,vector<int>(n,0));
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < n; k++) {
                int temp = 0;
                int temp_j = j,temp_k = k;
                while (temp_j < n && temp_k < n) {
                    if (s[temp_j] == s[temp_k]) {
                        temp++;
                    }else {
                        break;
                    }
                    temp_j++;
                    temp_k++;
                }
                if (temp != lcp[j][k])return "";
            }
        }
        return s;


    }
};
//思路是先根据lcp矩阵构建出可能的字典序最小的s，但是因为s可能不会遍历lcp所有数据就已经停止
//所以需要反过来求其lcp矩阵来看和原矩阵是否相同