#include "header.h"
class MyHashSet {
    unordered_set<int> h;
public:
    /** Initialize your data structure here. */
    MyHashSet() {
        h.clear();
    }
    
    void add(int key) {
        h.insert(key);
    }
    
    void remove(int key) {
        h.erase(key);
    }
    
    /** Returns true if this set contains the specified element */
    bool contains(int key) {
        return h.find(key)!=h.end();
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */