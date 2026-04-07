//
// Created by zhongjiahui on 26-4-1.
//
/*
现有 n 个机器人，编号从 1 开始，每个机器人包含在路线上的位置、健康度和移动方向。

给你下标从 0 开始的两个整数数组 positions、healths 和一个字符串 directions
（directions[i] 为 'L' 表示 向左 或 'R' 表示 向右）。 positions 中的所有整数 互不相同 。

所有机器人以 相同速度 同时 沿给定方向在路线上移动。如果两个机器人移动到相同位置，则会发生 碰撞 。

如果两个机器人发生碰撞，则将 健康度较低 的机器人从路线中 移除 ，并且另一个机器人的健康度 减少 1 。
幸存下来的机器人将会继续沿着与之前 相同 的方向前进。如果两个机器人的健康度相同，则将二者都从路线中移除。

请你确定全部碰撞后幸存下的所有机器人的 健康度 ，并按照原来机器人编号的顺序排列。
即机器人 1 （如果幸存）的最终健康度，机器人 2 （如果幸存）的最终健康度等。 如果不存在幸存的机器人，则返回空数组。
在不再发生任何碰撞后，请你以数组形式，返回所有剩余机器人的健康度（按机器人输入中的编号顺序）。
注意：位置  positions 可能是乱序的。

示例 1：
输入：positions = [5,4,3,2,1], healths = [2,17,9,15,10], directions = "RRRRR"
输出：[2,17,9,15,10]
解释：在本例中不存在碰撞，因为所有机器人向同一方向移动。所以，从第一个机器人开始依序返回健康度，[2, 17, 9, 15, 10] 。
 */

#include<vector>
#include<string>
#include<stack>
#include<algorithm>
#include <numeric>
using namespace std;
class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {
        int n = positions.size();
        vector<int> idx(n);
        iota(idx.begin(), idx.end(), 0);
        sort(idx.begin(), idx.end(), [&](int a, int b) {
            return positions[a] < positions[b];
        });

        vector<tuple<int, int, char>> alive;
        for (int i : idx) {
            int cur_id = i,cur_health = healths[i];
            char cur_dir = directions[i];
            while (!alive.empty()) {
                auto [prev_id, prev_health, prev_dir] = alive.back();
                if (prev_dir == 'R' && cur_dir == 'L') {
                    alive.pop_back();
                    if (prev_health > cur_health) {
                        cur_id = prev_id;
                        cur_health = prev_health - 1;
                        cur_dir = 'R';
                    }else if (prev_health < cur_health) {
                        cur_health -= 1;
                    }else {
                        cur_id = -1;
                        break;
                    }
                }else {
                    break;
                }
            }
            if (cur_id != -1) {
                alive.emplace_back(cur_id, cur_health, cur_dir);
            }
        }
        sort(alive.begin(), alive.end());
        vector<int> ans;
        for (auto&[id,hp,dir] : alive) {
            ans.push_back(hp);
        }

        return ans;
    }
};