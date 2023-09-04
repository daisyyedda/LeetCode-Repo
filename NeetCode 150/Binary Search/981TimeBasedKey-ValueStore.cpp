// using map and unordered_map
class TimeMap {
public:
    unordered_map<string, map<int, string>> hash;
    TimeMap() {
    }

    void set(string key, string value, int timestamp) {
        hash[key][timestamp] = value;
    }

    string get(string key, int timestamp) {
        if (hash.find(key) == hash.end()) return "";
        auto it = hash[key].upper_bound(timestamp);
        if (it == hash[key].begin()) return "";
        return prev(it)->second;
    }
};
