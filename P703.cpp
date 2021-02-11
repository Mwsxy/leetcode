#include "header.h"
#include <bits/c++config.h>
#include <cstddef>
#include <vector>

class KthLargest {
public:
    int knums[20000], nk;
    int K;
    KthLargest(int k, vector<int>& nums) {
        nk = 0;
        K = k;
        if (nums.empty()) return;
        sort(nums.begin(), nums.end(), greater<int>());
        int n = min<int>(k, nums.size());
        for (int i=0; i<n ; i++)
            knums[nk++] = nums[i];
        // print(knums);
    }
    
    int add(int val) {
        if (nk >= K && val<=knums[nk-1]) 
            return knums[nk-1];
        if (nk <K) 
            knums[nk++] = val;
        int i=nk-1;
        while (i>0 && val>knums[i-1]) {
            knums[i] = knums[i-1];
            i--;
        }
        knums[i] = val;
        // print(knums);
        return knums[K-1];
    }

};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */

int main() {
    int k = 1;
    vector<int> nums = {};
    KthLargest *obj = new KthLargest(k, nums);
    cout << obj->add(-3) << endl;
    cout << obj->add(-2) << endl;
    cout << obj->add(-4) << endl;
    cout << obj->add(0) << endl;
    cout << obj->add(4) << endl; 
    return 0;
}