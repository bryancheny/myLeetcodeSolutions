class LRUCache {
public:
    LRUCache(int capacity) {
        cap = capacity;
    }
    
    int get(int key) {
        if(hash.find(key) == hash.end()) return -1;
        auto it = hash[key];
        recencylist.splice(recencylist.begin(),recencylist,it);
        return it->second;
    }
    
    void put(int key, int value) {
        if (hash.find(key) != hash.end()) {
            hash[key]->second = value;
            recencylist.splice(recencylist.begin(),recencylist,hash[key]);
            return;
        }
        if (recencylist.size() == cap) {
            hash.erase(recencylist.back().first);
            recencylist.pop_back();
        }
        recencylist.push_front({key,value});
        hash[key] = recencylist.begin();
    }
private:
    list <pair<int,int>> recencylist;
    unordered_map<int,list<pair<int,int>>::iterator> hash;
    int cap;
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
