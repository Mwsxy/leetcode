#include<algorithm>
#include<vector>
#include<iostream>
#include<string>
#include<stack>


using namespace std;

class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
       vector<vector<int>> ans;
        sort(nums.begin(),nums.end());
        vector<int> sign=nums;
        reverse(sign.begin(),sign.end());
        while(nums!=sign)
        {
            ans.push_back(nums);
            nums=next(nums);
        }
        ans.push_back(sign);
        return ans;
    }
    
    
    
    vector<int> next(vector<int> & input)
    {
        int i=0;
        for(;i<input.size()-1;i++)
        {
            if(input[i+1]>input[i])
                break;
        }
        if(i==input.size()-1)
        {
            vector<int>res=input;
            sort(res.begin(),res.end());
            return res;
        }
        else
        {
            int j=input.size()-1;
            for(;j>=1;j--)
            {
                if(input[j]>input[j-1])
                    break;
            }
            j--;
            int m=input.size()-1;
            for(;m>j;m--)
            {
                if(input[m]>input[j])
                    break;
            }
            swap(input[j],input[m]);
            sort(input.begin()+j+1,input.end());
            return input;
        }
        
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
    vector<int> input={3,3,1,2,3,2,3,1};
    auto res = Solution().permuteUnique(input);
    for (auto i:res) {
        for (auto j:i)
            cout <<j<<" ";
        cout<<endl;
    }
    return 0;
}