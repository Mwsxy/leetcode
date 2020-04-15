#include<algorithm>
#include<vector>
#include<iostream>
#include<string>

using namespace std;

bool cmp(const vector<int> &a, const vector<int> &b) {
	if (a.size() != b.size()) return a.size() < b.size();
	else 
		for (int i = 0; i < a.size(); i++)
			if (a[i] != b[i]) return a[i] < b[i];
	return false;
}

bool eq(const vector<int> &a, const vector<int> &b) {
	if (a.size() != b.size()) return false;
	for (auto i = 0; i < a.size(); i++)
		if (a[i] != b[i]) return false;
	return true;
}

class Solution {
public:
	vector<vector<int> > fourSum(vector<int>& nums, int target) {
		sort(nums.begin(), nums.end());
		vector<int>::iterator left, right;
		vector<vector<int> > res;
		if (nums.size() < 4) return res;
		int sum;
		for (auto i = nums.begin() + 1; i < nums.end() - 2; i++) {
			for (auto j = i + 1; j < nums.end() - 1; j++) {
				left = nums.begin();
				right = nums.end() - 1;
				while (left < right) {
					sum = *i + *j + *left + *right;
					if (sum == target) {
						vector<int> t = { *left,*i,*j,*right };
						sort(t.begin(), t.end());
						res.push_back(t);
						left++;
						right--;
					}
					else if (sum > target) right--;
					else if (sum < target) left++;
					while (i == left || j == left) left++;
					while (i == right || j == right) right--;
				}

			}
		}
		sort(res.begin(), res.end(), cmp);
		auto e=unique(res.begin(), res.end(), eq);
		res.resize(distance(res.begin(), e));
		// int i=0;
		// while (i<res.size()) {
		//     if (i+1<res.size() && eq(res[i],res[i+1])==true) res.erase(res.begin()+i+1);
		//     else i++;
		// }
		return res;
	}

};

static const auto io_sync_off = []()
{
	// turn off sync
	std::ios::sync_with_stdio(false);
	// untie in/out streams
	std::cin.tie(nullptr);
	return nullptr;
}();


int main() {
    vector<int> nums={-1,-2,-5,3,-4};
    int target=-1;
    auto res = Solution().threeSumClosest(nums,target);
    cout << res <<endl;
    return 0;
}