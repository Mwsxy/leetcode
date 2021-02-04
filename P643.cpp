#include "header.h"

class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        double sum=0.0;
        double max_sum;
        for (size_t i = 0; i < k; i++)
        {
            sum+=nums[i];
        }
        max_sum = sum;
        for (size_t i = 0; i < nums.size()-k; i++)
        {
            sum+=nums[i+k];
            sum-=nums[i];
            if(sum>max_sum) max_sum = sum;
        }
        return max_sum/k;
    }
};

int main(int argc, char const *argv[])
{
    vector<int> a = {1,2,3,4,5};
    cout << Solution().findMaxAverage(a, 1);
    return 0;
}
