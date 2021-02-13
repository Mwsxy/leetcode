#include "header.h"
#include <unordered_set>
#include <unordered_map>

struct BitMap {
    size_t n;
    unsigned char *a;
    BitMap(size_t N) {
        n = N;
        a = new unsigned char [n/8+1]();
    }
    bool operator() (size_t i) {
        const size_t &r = i>>3;
        const size_t &c = i&7U;
        return (a[r]&(1U<<c)) > 0;
    }
    bool get (size_t i) {
        const size_t &r = i>>3;
        const size_t &c = i&7U;
        return (a[r]&(1U<<c)) > 0;
    }
    void set(size_t i) {
        const size_t &r = i>>3;
        const size_t &c = i&7U;
        a[r] |= 1u<<c;
    }
    void unset(size_t i) {
        const size_t &r = i>>3;
        const size_t &c = i&7U;
        a[r] &= ~(1u<<c);
    }
    int longestConsecuteBit() {
        size_t i, r, c;
        int ans = 0;
        i = r = c = 0;
        while (i<n) {
            if (get(i)) {
                size_t j = i+1;
                while (get(j)) {
                    j++;
                }
                if (j-i > ans) ans = j-i;
                i = j;
            }
            else
                i++;

        }
        return ans;
    }
};

class Solution_old {
public:
    int longestConsecutive(vector<int>& nums) {
        
        int _min, _max;
        if (nums.empty()) 
            return 0;
        _min = _max = nums[0];
        for (const auto &v:nums) {
            if (v>_max) _max = v;
            if (v<_min) _min = v;
        }
        BitMap bm(_max-_min+1);
        for (const auto &v:nums) {
            size_t i = v-_min;
            bm.set(i);
        }
        return bm.longestConsecuteBit();
    }
};


class Solution {
public:
    unordered_map<int, int> s, cnt;
    int get(int i) {
        if (s[i]!=i) s[i]=get(s[i]);
        else return i;
        return s[i];
    }
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        for (int i:nums) {
            s[i]=i;
            cnt[i]=1;
        }
        if (nums.empty()) return 0;
        int ans=1;
        for (int i:nums) {
            if (s[i]==i && s.find(i+1)!=s.end()) {
                int p1, p2;
                p1 = get(i);
                p2 = get(i+1);
                cnt[p2] += cnt[p1];
                ans = max(ans, cnt[p2]);
                s[p1] = s[p2];
            }
        }
        return ans;
    }
};

int main() {
    vector<int> nums;
    nums = {100, 4, 200, 1, 3, 2};
    cout << Solution().longestConsecutive(nums) << endl;
    nums = {0,3,7,2,5,8,4,6,0,1};
    cout << Solution().longestConsecutive(nums) << endl;
    // nums = {0,1,2,3,4,5,6,7,8,9};
    // cout << Solution().longestConsecutive(nums) << endl;
    // nums = {9,8,7,6,5,4,3,2,1,0};
    // cout << Solution().longestConsecutive(nums) << endl;
    nums.clear();

    for (int i=0; i<5000; i++) {
        nums.push_back(-(1<<30)+i);
        nums.push_back((1<<30)+i);   
    }
    // cout << "[0";
    // for (auto v:nums)
    //     cout << "," << v;
    // cout << "]" << endl;

    // cout << Solution().longestConsecutive(nums) << endl;
    return 0;
}