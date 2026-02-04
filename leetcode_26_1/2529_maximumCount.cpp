//
// Created by zhongjiahui on 26-2-4.
//
/*题面：
给你一个按 非递减顺序 排列的数组 nums ，返回正整数数目和负整数数目中的最大值。
换句话讲，如果 nums 中正整数的数目是 pos ，而负整数的数目是 neg ，返回 pos 和 neg二者中的最大值。
注意：0 既不是正整数也不是负整数。

示例 1：
输入：nums = [-2,-1,-1,1,2,3]
输出：3
解释：共有 3 个正整数和 3 个负整数。计数得到的最大值是 3 。
 */
#include <vector>
#include <algorithm>
#include<iostream>
using namespace std;
class Solution {
public:
    int maximumCount(vector<int>& nums) {
        int n = nums.size();
        int l = 0, r = n - 1;
        int negPos = -1;
        int posPos = n;
        
        // 二分查找最后一个小于0的数的位置
        while(l <= r){
            int mid = l + (r - l) / 2;
            if(nums[mid] < 0){
                 negPos = mid;
                 l = mid + 1;
            }else{
                 r = mid - 1;
            }
        }
        
        l = 0;
        r = n - 1;
        // 二分查找第一个大于0的数的位置
        while(l <= r){
            int mid = l + (r - l) / 2;
            if(nums[mid] > 0){
                 posPos = mid;
                 r = mid - 1;
            }else{
                 l = mid + 1;
            }
        }
        
        return max(negPos + 1, n - posPos);
    }
};

int main(){
    Solution sol;
    vector<int> nums = {-2,-1,2,3};
    int result = sol.maximumCount(nums);
    return 0;
}