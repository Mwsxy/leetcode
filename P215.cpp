#include <bits/stdc++.h>
#include "header.h"
using namespace std;

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        return findK(nums, k, 0, nums.size()-1);
    }
    int findK(vector<int>& nums, int k, int l, int r)
    {
        int pivot = l + (r-l)/2;
        swap(nums[r], nums[pivot]);

        int i,j;
        i = j = l;
        while (j<r)
        {
            if (nums[j] > nums[r])
            {
                swap(nums[i], nums[j]);
                i++;
            }
            j++;
        }
        swap(nums[i], nums[j]);
        if (i<k-1)
        {
            return findK(nums, k, i+1, r);
        }
        else if (i>k-1)
        {
            return findK(nums, k, l, i-1);
        }
        else
        {
            return nums[i];
        }
    }
};

int main()
{
    vector<int> nums = {3,2,1,5,6,4};
    int k = 2;

    nums = {3,2,3,1,2,4,5,5,6};
    k = 4;
    cout << Solution().findKthLargest(nums, k) << endl;
    return 0;
}