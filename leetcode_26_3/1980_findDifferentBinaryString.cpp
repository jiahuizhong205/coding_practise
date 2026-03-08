//
// Created by zhongjiahui on 26-3-8.
//
/*
给你一个字符串数组 nums ，该数组由 n 个 互不相同 的二进制字符串组成，且每个字符串长度都是 n 。请你找出并返回一个长度为 n 且
没有出现 在 nums 中的二进制字符串。如果存在多种答案，只需返回 任意一个 即可。

示例 1：

输入：nums = ["01","10"]
输出："11"
解释："11" 没有出现在 nums 中。"00" 也是正确答案。
示例 2：

输入：nums = ["00","01"]
输出："11"
解释："11" 没有出现在 nums 中。"10" 也是正确答案。
 */
#include <set>
#include<vector>
#include<string>
#include <valarray>
using namespace std;
class Solution {
public:
    int TurnToTen(string a,int n) {
        int res = 0;
        int power = 1;
        for (int i = n - 1;i >= 0;i--) {
            res += power * (a[i] - '0');
            power *= 2;
        }
        return res;
    }
    string TurnToTwo(int a,int n) {
        string res = "";
        if (a == 0) {
            res = string (n,'0');
            return res;
        }
        while (a > 0) {
            res += a % 2 + '0';
            a = a >> 1;
        }
        while (res.size()< n) {
            res += '0';
        }
        reverse(res.begin(),res.end());
        return res;
    }
    string findDifferentBinaryString(vector<string>& nums) {
        int n = nums[0].size();
        int m = nums.size();
        set<int> s;
        for(int i = 0;i < m;i++) {
            s.insert(TurnToTen(nums[i],n));
        }
        int max_num = (1 << n) - 1;
        for (int i = 0; i < max_num; i++) {
            if (s.find(i)==s.end()) {
                return TurnToTwo(i,n);
            }
        }
        return string(n,'1');
    }
};
/*主函数中的逻辑是将字符串先转换为以10为基数的int并且放入set，再枚举查询，
 *最后将查询到的值转为二进制string
 */