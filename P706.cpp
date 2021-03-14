#include "header.h"

class MyHashMap {
    map<int, int> m;
public:
    /** Initialize your data structure here. */
    MyHashMap() {
        m.clear();
    }
    
    /** value will always be non-negative. */
    void put(int key, int value) {
        m[key] = value;
    }
    
    /** Returns the value to which the specified key is mapped, or -1 if this map contains no mapping for the key */
    int get(int key) {
        auto r = m.find(key);
        if (r!=m.end())
            return r->second;
        else 
            return -1;
    }
    
    /** Removes the mapping of the specified value key if this map contains a mapping for the key */
    void remove(int key) {
        m.erase(key);
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */

int main(int argc, char const *argv[])
{
    
    return 0;
}
