#include<vector>
#include<iostream>

using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i=1;
        while (i+1<nums.size()) {
            if (nums[i-1]==nums[i] && nums[i]==nums[i+1]) {
                nums.erase(nums.begin()+i);
            }
            else 
                i++;
        }
        return nums.size();
    }
};

int main() {
    vector<int> a={1,1,1,1,1,2,2,2,2,3,3,3,4,4,5};
    int len=Solution().removeDuplicates(a);
    for (int i=0;i<len;i++)
        cout<<a[i]<<" ";
    cout<<endl;
    return 0;
}