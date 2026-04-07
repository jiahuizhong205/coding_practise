//
// Created by zhongjiahui on 26-3-31.
//
/*
给你两个字符串，str1 和 str2，其长度分别为 n 和 m 。

如果一个长度为 n + m - 1 的字符串 word 的每个下标 0 <= i <= n - 1 都满足以下条件，则称其由 str1 和 str2 生成：

如果 str1[i] == 'T'，则长度为 m 的 子字符串（从下标 i 开始）与 str2 相等，即 word[i..(i + m - 1)] == str2。
如果 str1[i] == 'F'，则长度为 m 的 子字符串（从下标 i 开始）与 str2 不相等，即 word[i..(i + m - 1)] != str2。
返回可以由 str1 和 str2 生成 的 字典序最小 的字符串。如果不存在满足条件的字符串，返回空字符串 ""。

如果字符串 a 在第一个不同字符的位置上比字符串 b 的对应字符在字母表中更靠前，则称字符串 a 的 字典序 小于 字符串 b。
如果前 min(a.length, b.length) 个字符都相同，则较短的字符串字典序更小。

子字符串 是字符串中的一个连续、非空 的字符序列。

示例 1：
输入: str1 = "TFTF", str2 = "ab"
输出: "ababa"
 */

#include<vector>
#include<string>
using namespace std;
class Solution {
public:
    string generateString(string str1, string str2) {
        int n = str1.size(),m = str2.size();
        string res(n+m-1,'?');
        for(int i=0;i<n;i++) {
            if (str1[i] != 'T') {
                continue;
            }
            for (int j=0;j<m;j++) {
                char v = res[i + j];
                if (v != '?'&&v != str2[j]) {
                    return "";
                }
                res[i + j] = str2[j];
            }
        }
        string old_res = res;
        for (char& c:res) {
            if (c == '?') {
                c = 'a';
            }
        }
        for (int i = 0;i < n;i++) {
            if (str1[i] != 'F')continue;
            if (string(res.begin()+i,res.begin() + i + m) != str2)continue;
            bool temp = false;
            for (int j = i + m - 1;j >= i;j--) {
                if (old_res[j] == '?') {
                    res[j] = 'b';
                    temp = true;
                    break;
                }
            }
            if (!temp) {
                return "";
            }
        }
        return res;

    }
};