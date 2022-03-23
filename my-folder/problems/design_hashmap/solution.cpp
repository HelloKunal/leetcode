class MyHashMap {
public:
    vector<list<pair<int, int>>> HashArray;
    MyHashMap() {
        HashArray.assign(10000, list<pair<int, int>>());
    }
    
    void put(int key, int value) {
        int superkey = key % 10000;
        bool done = false;
        for(auto &item : HashArray[superkey]) {
            if(item.first == key) {
                item.second = value;
                done = true;
                break;
            }
        }  
        if(!done) HashArray[superkey].push_front({key, value});
    }
    
    int get(int key) {
        int superkey = key % 10000;
        for(auto item : HashArray[superkey]) {
            if(item.first == key) return item.second;
        }
        return -1;
    }
    
    void remove(int key) {
        int superkey = key % 10000;
        for(auto item : HashArray[superkey]) {
            if(item.first == key) {
                HashArray[superkey].remove(item);
                break;
            }
        }  
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */