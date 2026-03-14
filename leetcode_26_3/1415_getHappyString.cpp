//
// Created by zhongjiahui on 26-3-14.
//
/*
一个 「开心字符串」定义为：

仅包含小写字母 ['a', 'b', 'c'].
对所有在 1 到 s.length - 1 之间的 i ，满足 s[i] != s[i + 1] （字符串的下标从 1 开始）。
比方说，字符串 "abc"，"ac"，"b" 和 "abcbabcbcb" 都是开心字符串，但是 "aa"，"baa" 和 "ababbc" 都不是开心字符串。

给你两个整数 n 和 k ，你需要将长度为 n 的所有开心字符串按字典序排序。

请你返回排序后的第 k 个开心字符串，如果长度为 n 的开心字符串少于 k 个，那么请你返回 空字符串 。

示例 1：
输入：n = 1, k = 3
输出："c"
解释：列表 ["a", "b", "c"] 包含了所有长度为 1 的开心字符串。按照字典序排序后第三个字符串为 "c" 。
 */
#include<vector>
#include<string>
using namespace std;
// class Solution {
// public:
//     vector<string> store;
//     void generateAll(int n,string s) {
//         if (s.size()==n) {
//             store.push_back(s);
//             return;
//         }
//         int m = s.size();
//         if (s[m - 1] == 'a') {
//             generateAll(n,s+'b');
//             generateAll(n,s+'c');
//         }else if (s[m - 1] == 'b') {
//             generateAll(n,s+'a');
//             generateAll(n,s+'c');
//         }else if (s[m - 1] == 'c') {
//             generateAll(n,s+'a');
//             generateAll(n,s+'b');
//         }
//     }
//     string getHappyString(int n, int k) {
//         if (n == 1) {
//             if (k>3)return "";
//             else if (k==1)return "a";
//             else if (k==2)return "b";
//             else return "c";
//         }
//         generateAll(n,"a");
//         generateAll(n,"b");
//         generateAll(n,"c");
//         if (k > store.size())return "";
//         return store[k-1];
//     }
// };
//用回溯法生成了所有可能的结果并储存起来

class Solution {
public:
    string getHappyString(int n, int k) {
        int total = 3;
        for(int i=1; i<n; ++i) total *= 2;
        if(k > total) return "";

        string ans;
        char prev = 0; // 记录上一个字符
        k--; // 转换为0下标

        for(int i=0; i<n; ++i){
            // 每一层的分支数量：第一个字符3选1，后面2选1
            int cnt = (i == 0) ? 3 : 2;
            int group = 1 << (n - i - 1); // 每组的字符串数量 2^(n-i-1)

            // 遍历a/b/c，找到对应分组
            for(char ch='a'; ch<='c'; ++ch){
                if(ch == prev) continue; // 不能和上一个相同
                if(k < group){
                    ans += ch;
                    prev = ch;
                    break;
                }
                k -= group;
            }
        }
        return ans;
    }
};