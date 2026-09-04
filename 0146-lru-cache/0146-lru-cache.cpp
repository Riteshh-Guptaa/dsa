class LRUCache {
public:
    int capacity;
    unordered_map<int, pair<int, list<int>::iterator>> mp;
    list<int> lru;
    LRUCache(int capacity) {
        this->capacity = capacity;
    }
    
    int get(int key) {
        if(mp.find(key) == mp.end()){
            return -1;
        }

        lru.erase(mp[key].second);
        lru.push_front(key);
        mp[key].second = lru.begin();
        return mp[key].first;
    }


    
    void put(int key, int value) {
        if(mp.find(key) != mp.end()){
            lru.erase(mp[key].second);
            lru.push_front(key);
            mp[key].first = value;
            mp[key].second = lru.begin();
            return;
        }
        if(mp.size() == capacity){
            int oldKey = lru.back();
            lru.pop_back();

            mp.erase(oldKey);
        }
        lru.push_front(key);
        mp[key] = {value, lru.begin()};
    
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */