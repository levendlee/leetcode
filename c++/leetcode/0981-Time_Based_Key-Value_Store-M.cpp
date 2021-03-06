// 981 Time Based Key-Value Store
// https://leetcode.com/problems/time-based-key-value-store

// version: 1; create time: 2019-10-22 21:39:18;
class TimeMap {
private:
    unordered_map<string, map<int, string>> tree_map_;

public:
    /** Initialize your data structure here. */
    TimeMap() {

    }

    void set(string key, string value, int timestamp) {
        if (tree_map_.count(key)) {
            auto& sub_map = tree_map_[key];
            sub_map[timestamp] = value;
        } else {
            tree_map_.insert({key, {{timestamp, value}}});
        }
    }

    string get(string key, int timestamp) {
        if (tree_map_.count(key)) {
            auto& sub_map = tree_map_[key];
            auto iter = sub_map.upper_bound(timestamp);
            if (iter == sub_map.begin()) {
                return "";
            }
            return (--iter)->second;
        } else {
            return "";
        }
    }
};
