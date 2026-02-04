//
// Created by zhongjiahui on 26-2-1.
//
/*二分法
 要求的是非严格递增数组中target值的开头index和结尾index
 用了两个二分函数，其实方法大差不差，可以修改为一个函数（但是比较懒所以还是写了两个，逻辑更清晰些嘿嘿）
 在基础的二分法上对于nums[mid] == target的情况来加一个判断
 时间复杂度log（n）
 */
#include<vector>
using namespace std;
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0, r = nums.size() - 1;
        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (nums[mid] == target) {
                if (mid - 1 >= 0 && nums[mid - 1] != target)return mid;
                if (mid - 1<0)return 0;
                r = mid - 1;
            }
            if (nums[mid] < target) {
                l = mid + 1;
            }
            else {
                r = mid - 1;
            }
        }
        return -1;
    }
    int search2(vector<int>& nums, int target) {
        int l = 0, r = nums.size() - 1;
        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (nums[mid] == target) {
                if (mid + 1 < nums.size() && nums[mid + 1] != target)return mid;
                if (mid + 1 >= nums.size())return nums.size() - 1;
                l = mid + 1;
            }
            if (nums[mid] > target) {
                r = mid - 1;
            }
            else {
                l = mid + 1;
            }
        }
        return -1;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        int res_left = 0, res_right = 0;
        int l = 0, r = nums.size() - 1;
        res_left = search(nums, target);
        res_right = search2(nums, target);
        return {res_left, res_right};
    }
};