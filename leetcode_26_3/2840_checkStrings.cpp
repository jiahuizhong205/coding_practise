//
// Created by zhongjiahui on 26-3-30.
//
/*
给你两个字符串 s1 和 s2 ，两个字符串长度都为 n ，且只包含 小写 英文字母。

你可以对两个字符串中的 任意一个 执行以下操作 任意 次：

选择两个下标 i 和 j ，满足 i < j 且 j - i 是 偶数，然后 交换 这个字符串中两个下标对应的字符。

如果你可以让字符串 s1 和 s2 相等，那么返回 true ，否则返回 false 。

示例 1：
输入：s1 = "abcdba", s2 = "cabdab"
输出：true
解释：我们可以对 s1 执行以下操作：
- 选择下标 i = 0 ，j = 2 ，得到字符串 s1 = "cbadba" 。
- 选择下标 i = 2 ，j = 4 ，得到字符串 s1 = "cbbdaa" 。
- 选择下标 i = 1 ，j = 5 ，得到字符串 s1 = "cabdab" = s2 。
 */

#include<vector>
#include<string>
#include<map>
using namespace std;
class Solution {
public:
    bool checkStrings(string s1, string s2) {
        map<char,int> m_0,m_1;
        int n = s1.length();
        for(int i=0;i<n;i+=2) {
            m_0[s1[i]]++;
        }
        for(int i=1;i<n;i+=2) {
            m_1[s1[i]]++;
        }
        for(int i=0;i<n;i++) {
            if (i % 2 == 0) {
                m_0[s2[i]]--;
                if (m_0[s2[i]]<0) {
                    return false;
                }
            }else {
                m_1[s2[i]]--;
                if (m_1[s2[i]]<0) {
                    return false;
                }
            }
        }
        return true;
    }
};