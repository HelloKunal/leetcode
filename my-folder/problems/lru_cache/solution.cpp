class LRUCache {
public:
    list<int> lst;
    unordered_map<int, pair<int, list<int>::iterator>> ump;
    int csize;
    LRUCache(int capacity) {
        csize = capacity;
    }
    
    int get(int key) {
        if(ump.find(key) != ump.end()) {
            lst.erase(ump[key].second);
            lst.push_front(key);
            ump[key].second = lst.begin();
            
            return ump[key].first;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if(ump.find(key) == ump.end()) {
            if(lst.size() == csize) {
                int last = lst.back();
                lst.pop_back();
                ump.erase(last);
            }
        } else {
            lst.erase(ump[key].second);
        }
        
        lst.push_front(key);
        ump[key].first = value;
        ump[key].second = lst.begin();
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */