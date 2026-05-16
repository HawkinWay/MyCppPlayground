#include<list>
#include<unordered_map>

/*

* Core: std::list<std::pair<int, int>> lst;
        std::unordered_map<int, std::list<std::pair<int, int>>::iterator> mp;

*       lst.splice(iterator_position, list, iterator)

*       mp[key] = lst.begin();

*/

class LRUCache {
public:
    LRUCache(int capacity) {
        this->capacity = capacity;
        // lst.resize(capacity);    this will create empty nodes with the number of capacity
    }
    
    int get(int key) {
        if(mp.find(key) != mp.end()){
            lst.splice(lst.begin(), lst, mp[key]);
            return mp[key]->second;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if(mp.find(key) != mp.end()){
            mp[key]->second = value;
            lst.splice(lst.begin(), lst, mp[key]);
        }else{
            if(lst.size() == capacity){
                int del = lst.back().first;
                mp.erase(del);
                lst.pop_back();
            }
            // mp[key]->second = value;     can't use this to initialize
            // lst.splice(lst.begin(), lst, mp[key]);
            lst.push_front({key, value});
            mp[key] = lst.begin();

        }
    }
private:
    int capacity;
    std::list<std::pair<int, int>> lst;
    std::unordered_map<int, std::list<std::pair<int, int>>::iterator> mp;
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */