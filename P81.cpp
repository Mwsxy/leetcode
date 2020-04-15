#include<iostream>
#include<algorithm>
#include<vector>
#include<cstdlib>

using namespace std;

class Solution {
public:
	bool search(vector<int>& nums, int target) {
		if (nums.size() == 0) return false;
		return srch(nums.begin(), nums.end(), target);
	}
	bool srch(vector<int>::iterator beg, vector<int>::iterator end, int target) {
		vector<int>::iterator l, r, m, p;
		l = beg;
		r = end-1;
		// at beginning, a[r]<=a[l]
		// [l, r]   [beg, end)
		while (l <= r)
		{
			m = l + (r - l) / 2;
			if (*m == target) return true;
			if (*l < *m) {
				p = search_n(l, m, 1, target);
				if (p != m) return true;
				l = m + 1;
			}
			else if (*l != *m) { //l>m
				p = search_n(m, r + 1, 1, target);
				if (p != r + 1) return true;
				r = m - 1;
			}
			else if (*m == *r) {
				auto k = srch(l, m, target);
				if (k) return k;
				k = srch(m + 1, r+1, target);
				if (k) return k;
				return false;
			}
			else if (*m > * r) {
				l = m + 1;
			}
			else {
				//cout << "???????ERR????" << endl;
				p = search_n(l, r + 1, 1, target);
				if (p != r + 1) return true;
				return false;
			}
		}
		return false;
	}
};

int main() {
    vector<int> nums={2,5,6,0,0,1,2};
    cout<< Solution().search(nums,3) << endl;
    return 0;
}