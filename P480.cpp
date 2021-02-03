#include "header.h"
#include <algorithm>


bool cmp1(const int &x, const int &y) {
    return x<y;
}

bool cmp2(const int &x, const int &y) {
    return (x>y);
}

double getMid(int k, vector<int> &big, vector<int> small) {
    if (k==1) return small.front();
    if (k%2==0) {
        return ((double)big.front()+(double)small.front())/2.0;
    }
    else {
        return small.front();
    }
}
void printVec(vector<int> v) {
    for (size_t i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";
    }
    cout << endl;
}

class Solution {
public:    
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        vector<int> big, small, nums1;
        nums1 = vector<int>(nums.begin(), nums.begin()+k);
        make_heap(nums1.begin(), nums1.begin()+k, cmp1);
        sort_heap(nums1.begin(), nums1.begin()+k, cmp1);
        size_t mid = k/2;

        big = vector<int>(nums1.begin(), nums1.begin()+mid);
        small = vector<int>(nums1.begin()+mid, nums1.begin()+k);
        make_heap(big.begin(), big.end(), cmp1);
        make_heap(small.begin(), small.end(), cmp2);
        vector<double> ans;
        ans.push_back(getMid(k,big,small));
        for (size_t i=0; i<nums.size()-k; i++) {
            // printVec(big);
            // printVec(small);
            // cout << endl;
            int prev = nums[i];
            int next = nums[i+k];
            if (k==1) {
                ans.push_back(next);
                continue;
            }
            if ((double)prev<ans.back()) {
                auto itr = find(big.begin(), big.end(), prev);
                pop_heap(itr, big.end(), cmp1);
                big.back() = next;
                push_heap(big.begin(), big.end(), cmp1);  
            }
            else
            {
                auto itr = find(small.begin(), small.end(), prev);
                pop_heap(itr, small.end(), cmp2);
                small.back() = next;
                push_heap(small.begin(), small.end(), cmp2); 
            }

            if (big.front() > small.front()) {
                swap(big.front(), small.front());
                make_heap(big.begin(), big.end(), cmp1);
                make_heap(small.begin(), small.end(), cmp2);
            }
            ans.push_back(getMid(k,big,small));

        }

        return ans;
    }
};

int main() {
    vector<int> a = {1,3,-1,-3,5,3,6,7};
    auto ret = Solution().medianSlidingWindow(a, 1);
    for (size_t i = 0; i < ret.size(); i++)
    {
        cout << ret[i] << " ";
    }
    cout << endl;
    
    return 0;
}

