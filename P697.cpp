#include "header.h"
#include <bits/types/__locale_t.h>
#include <unordered_map>
#include <unordered_set>

class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        unordered_map<int, int> _first, _last, _count;

        for (int i=0; i<nums.size(); i++) {
            int &x=nums[i];
            if (_count.find(x)==_count.end()) {
                _first[x]=i;
                _last[x] =i;
                _count[x]=1;
            }
            else {
                _last.find(x)->second=i;
                _count.find(x)->second++;
            }
        }
        int ans = 0;
        pair<int, int> _maxDegree(0, 0);
        for (const auto &itr:_count) {
            if (itr.second > _maxDegree.second) {
                _maxDegree = itr;
            }
            else if (itr.second == _maxDegree.second) {
                const int &x1 = itr.first, &x2 = _maxDegree.first;
                int len1 = _last.find(x1)->second - _first.find(x1)->second;
                int len2 = _last.find(x2)->second - _first.find(x2)->second;
                if (len1<len2) {
                    _maxDegree = itr;
                }
            }
        }
        int x = _maxDegree.first;
        // cout << "x="<<x << endl;
        ans = _last.find(x)->second - _first.find(x)->second+1;

        // for (auto p:_count) {
            // cout << "(" << p.first << ", " << p.second << ") ";
        // }
        // cout << endl;
        return ans;
    }
};

int main() {
    vector<int> a;
    a = {1,2,2,3,1};

    cout << Solution().findShortestSubArray(a) << endl;

    a = {1,2,2,3,1,4,2};

    cout << Solution().findShortestSubArray(a) << endl;
    return 0;
}