class LRUCache {
private:
    int cap;
    list<pair<int,int>> dll; 
    unordered_map<int, list<pair<int,int>>::iterator> mp;

public:
    LRUCache(int capacity) {
        cap = capacity;
    }

    int get(int key) {
        if (mp.find(key) == mp.end())
            return -1;

        // Move accessed node to front (MRU)
        auto it = mp[key];
        int value = it->second;
        dll.erase(it);
        dll.push_front({key, value});
        mp[key] = dll.begin();

        return value;
    }

    void put(int key, int value) {
        // If key already exists, remove old node
        if (mp.find(key) != mp.end()) {
            dll.erase(mp[key]);
        }
        // If capacity exceeded, remove LRU
        else if (dll.size() == cap) {
            auto lru = dll.back();
            mp.erase(lru.first);
            dll.pop_back();
        }

        // Insert new node at front
        dll.push_front({key, value});
        mp[key] = dll.begin();
    }
};