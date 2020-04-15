#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        return nums;
    }
};

int main() {
    vector<int> a={5,4,4,1,3,2,0,0};
    Solution().sortArray(a);
    for (auto v:a)
        cout<<v<<" ";
    cout<<endl;
    return 0;
}