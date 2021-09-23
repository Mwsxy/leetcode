#include<bits/stdc++.h>

using namespace std;



class LRUCache {
public:
    using KV = pair<int, int>;
    LRUCache(int capacity) {
        capacity_ = capacity;
    }
    
    int get(int key) {
        auto res = hashtable_.find(key);
        if (res == hashtable_.end())
        {
            return -1;
        }
        else
        {
            int value = res->second->second;
            table_.erase(res->second);
            table_.emplace_back(key, value);
            auto itr = table_.end();
            res->second = --itr;
            return value;
        }
    }
    
    void put(int key, int value) {
        auto res = hashtable_.find(key);
        if (res == hashtable_.end())
        {
            table_.emplace_back(key, value);
            list<KV>::iterator itr = table_.end();
            hashtable_[key] = --itr;
            if (table_.size() > capacity_)
            {
                auto k = table_.front();
                hashtable_.erase(hashtable_.find(k.first));
                table_.pop_front();
            }
        }
        else
        {
            table_.erase(res->second);
            table_.emplace_back(key, value);
            list<KV>::iterator itr = table_.end();
            res->second= --itr;
        }
    }
private:
    int oldest_, capacity_;
    list<KV> table_;
    unordered_map<int, list<KV>::iterator> hashtable_;
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */