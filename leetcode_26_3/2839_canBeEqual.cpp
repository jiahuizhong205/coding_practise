//
// Created by zhongjiahui on 26-3-29.
//
/*
给你两个字符串 s1 和 s2 ，两个字符串的长度都为 4 ，且只包含 小写 英文字母。

你可以对两个字符串中的 任意一个 执行以下操作 任意 次：

选择两个下标 i 和 j 且满足 j - i = 2 ，然后 交换 这个字符串中两个下标对应的字符。
如果你可以让字符串 s1 和 s2 相等，那么返回 true ，否则返回 false 。

示例 1：
输入：s1 = "abcd", s2 = "cdab"
输出：true
解释： 我们可以对 s1 执行以下操作：
- 选择下标 i = 0 ，j = 2 ，得到字符串 s1 = "cbad" 。
- 选择下标 i = 1 ，j = 3 ，得到字符串 s1 = "cdab" = s2 。
 */
#include<vector>
#include<string>
using namespace std;
class Solution {
public:
    bool canBeEqual(string s1, string s2) {
        for (int i = 0;i < s1.size();i++) {
            if (s1[i] != s2[i]) {
                if (i + 2 < 4&&s1[i + 2] == s2[i]) {
                    char temp = s1[i];
                    s1[i] = s1[i + 2];
                    s1[i + 2] = temp;
                    continue;
                }
                return false;
            }
        }
        return true;
    }
};