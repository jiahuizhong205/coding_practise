//
// Created by zhongjiahui on 26-4-15.
//
/*
请你设计一个数据结构来高效管理网络路由器中的数据包。每个数据包包含以下属性：

source：生成该数据包的机器的唯一标识符。
destination：目标机器的唯一标识符。
timestamp：该数据包到达路由器的时间戳。
实现 Router 类：

Router(int memoryLimit)：初始化路由器对象，并设置固定的内存限制。

memoryLimit 是路由器在任意时间点可以存储的 最大 数据包数量。
如果添加一个新数据包会超过这个限制，则必须移除 最旧的 数据包以腾出空间。
bool addPacket(int source, int destination, int timestamp)：将具有给定属性的数据包添加到路由器。

如果路由器中已经存在一个具有相同 source、destination 和 timestamp 的数据包，则视为重复数据包。
如果数据包成功添加（即不是重复数据包），返回 true；否则返回 false。
int[] forwardPacket()：以 FIFO（先进先出）顺序转发下一个数据包。

从存储中移除该数据包。
以数组 [source, destination, timestamp] 的形式返回该数据包。
如果没有数据包可以转发，则返回空数组。
int getCount(int destination, int startTime, int endTime)：

返回当前存储在路由器中（即尚未转发）的，且目标地址为指定 destination 且时间戳在范围 [startTime, endTime]（包括两端）内的数据包数量。
注意：对于 addPacket 的查询会按照 timestamp 的非递减顺序进行。
示例 1：
输入：
["Router", "addPacket", "addPacket", "addPacket", "addPacket", "addPacket", "forwardPacket", "addPacket", "getCount"]
[[3], [1, 4, 90], [2, 5, 90], [1, 4, 90], [3, 5, 95], [4, 5, 105], [], [5, 2, 110], [5, 100, 110]]
输出：
[null, true, true, false, true, true, [2, 5, 90], true, 1]
解释：
Router router = new Router(3); // 初始化路由器，内存限制为 3。
router.addPacket(1, 4, 90); // 数据包被添加，返回 True。
router.addPacket(2, 5, 90); // 数据包被添加，返回 True。
router.addPacket(1, 4, 90); // 这是一个重复数据包，返回 False。
router.addPacket(3, 5, 95); // 数据包被添加，返回 True。
router.addPacket(4, 5, 105); // 数据包被添加，[1, 4, 90] 被移除，因为数据包数量超过限制，返回 True。
router.forwardPacket(); // 转发数据包 [2, 5, 90] 并将其从路由器中移除。
router.addPacket(5, 2, 110); // 数据包被添加，返回 True。
router.getCount(5, 100, 110); // 唯一目标地址为 5 且时间在 [100, 110] 范围内的数据包是 [4, 5, 105]，返回 1。
 */
#include <algorithm>
#include <map>
#include <queue>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include<vector>
using namespace std;
class Router {
private:
    int mem_limit;
    // 1. 主队列：维护FIFO顺序，存储完整数据包
    queue<tuple<int, int, int>> packet_queue;
    // 2. 去重集合：O(1)判断重复
    unordered_set<string> unique_set;
    // 3. 优化核心：目标地址 -> 时间戳有序数组
    // key: destination, value: 该目标所有未转发数据包的timestamp(严格递增)
    unordered_map<int, vector<int>> dest_ts_map;

    // 生成唯一键
    string getKey(int s, int d, int t) {
        return to_string(s) + "_" + to_string(d) + "_" + to_string(t);
    }

    // 从索引中删除一个旧数据包（内存满/转发时调用）
    void removeFromIndex(int d, int t) {
        auto& ts_list = dest_ts_map[d];
        // 有序数组，找到第一个等于t的位置删除
        auto it = lower_bound(ts_list.begin(), ts_list.end(), t);
        if (it != ts_list.end() && *it == t) {
            ts_list.erase(it);
        }
        // 如果列表为空，清理key节省空间
        if (ts_list.empty()) {
            dest_ts_map.erase(d);
        }
    }

public:
    Router(int memoryLimit) : mem_limit(memoryLimit) {}

    bool addPacket(int source, int destination, int timestamp) {
        string key = getKey(source, destination, timestamp);
        if (unique_set.count(key)) {
            return false;
        }

        // 内存满：删除最旧数据包
        if (packet_queue.size() >= mem_limit) {
            auto old_pkt = packet_queue.front();
            packet_queue.pop();
            int old_s = get<0>(old_pkt);
            int old_d = get<1>(old_pkt);
            int old_t = get<2>(old_pkt);
            // 同步删除去重集合 + 索引
            unique_set.erase(getKey(old_s, old_d, old_t));
            removeFromIndex(old_d, old_t);
        }

        // 添加新数据包
        packet_queue.emplace(source, destination, timestamp);
        unique_set.insert(key);
        // 同步维护索引：时间戳非递减，直接push_back即可保持有序
        dest_ts_map[destination].push_back(timestamp);
        return true;
    }

    vector<int> forwardPacket() {
        if (packet_queue.empty()) {
            return {};
        }

        auto pkt = packet_queue.front();
        packet_queue.pop();
        int s = get<0>(pkt);
        int d = get<1>(pkt);
        int t = get<2>(pkt);

        // 同步删除
        unique_set.erase(getKey(s, d, t));
        removeFromIndex(d, t);

        return {s, d, t};
    }
    
    int getCount(int destination, int startTime, int endTime) {
        // 目标不存在，直接返回0
        if (!dest_ts_map.count(destination)) {
            return 0;
        }
        const auto& ts_list = dest_ts_map[destination];
        // 二分查找：第一个 >= startTime
        auto left = lower_bound(ts_list.begin(), ts_list.end(), startTime);
        // 二分查找：第一个 > endTime
        auto right = upper_bound(ts_list.begin(), ts_list.end(), endTime);
        // 数量 = 右指针 - 左指针
        return right - left;
    }
};

/**
 * Your Router object will be instantiated and called as such:
 * Router* obj = new Router(memoryLimit);
 * bool param_1 = obj->addPacket(source,destination,timestamp);
 * vector<int> param_2 = obj->forwardPacket();
 * int param_3 = obj->getCount(destination,startTime,endTime);
 */