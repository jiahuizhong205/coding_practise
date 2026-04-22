//
// Created by zhongjiahui on 26-4-22.
//
/*
给你一个仅由小写英文字母组成的字符串 s 。

如果一个字符串仅由单一字符组成，那么它被称为 特殊 字符串。例如，字符串 "abc" 不是特殊字符串，而字符串 "ddd"、"zz" 和 "f" 是特殊字符串。

返回在 s 中出现 至少三次 的 最长特殊子字符串 的长度，如果不存在出现至少三次的特殊子字符串，则返回 -1 。

子字符串 是字符串中的一个连续 非空 字符序列.
示例 1：
输入：s = "aaaa"
输出：2
解释：出现三次的最长特殊子字符串是 "aa" ：子字符串 "aaaa"、"aaaa" 和 "aaaa"。
可以证明最大长度是 2 。
 */
#include <map>
#include<vector>
#include<string>
using namespace std;
class Solution {
public:
    bool check(string& s,int length) {
        vector<pair<char,int>> res;
        char c = s[0];
        int cnt = 1;
        for (int i = 1; i < s.length(); i++) {
            if (s[i] == c) {
                cnt++;
            }else {
                res.push_back(make_pair(c,cnt));
                c = s[i];
                cnt = 1;
            }
        }
        res.emplace_back(c,cnt);
        vector<int>count(26,0);
        for (auto&p : res) {
            char c = p.first;
            int len = p.second;
            if (len >= length) {
                count[c - 'a'] += len - length + 1;
                if (count[c - 'a'] >= 3) return true;
            }
        }
        return false;
    }
    int maximumLength(string s) {
        map<char, int> m;
        for(int i = 0; i < s.length(); i++) {
            m[s[i]]++;
        }
        int flag = 0;
        for(auto it = m.begin(); it != m.end(); it++) {
            if(it->second >= 3) {
                flag = 1;
            }
        }
        if(!flag) {
            return -1;
        }
        int n = s.length();
        int left = 1,right = n - 2;
        while(left < right) {
            int mid = left + (right - left + 1) / 2;
            if (check(s, mid)) {
                left = mid;
            }else {
                right = mid - 1;
            }
        }
        return left;
    }
};