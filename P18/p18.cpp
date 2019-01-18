#include<algorithm>
#include<vector>
#include<iostream>
#include<string>

using namespace std;

bool cmp(const vector<int> &a,const vector<int> &b) {
    if (a.size()!=b.size()) return a.size()<b.size();
    for (int i=0;i<a.size();i++) 
        if (a[i]!=b[i]) return a[i]<b[i];
    return true;
}

bool eq(vector<int> &a,vector<int> &b) {
    if (a.size()!=b.size()) return false;
    for (auto i=0;i<a.size();i++)
        if (a[i]!=b[i]) return false;
    return true;
}

class Solution {
public:
vector<vector<int> > fourSum(vector<int>& nums, int target) {
    sort(nums.begin(),nums.end());
    vector<int>::iterator left,right;
    vector<vector<int>> res;
    // vector<int> count(nums.size(),1);
    // int i=0;
    // while (i<nums.size()) {
    //     if (i+1<nums.size() && nums[i]==nums[i+1]) {
    //         nums.erase(nums.begin()+i+1);
    //         count[i]++;
    //     }
    //     else 
    //         i++;
    // }
    if (nums.size()<4) return res;
    int sum;
    for (auto i = nums.begin() + 1; i < nums.end() - 1; i++) {
        for (auto j = i + 1; j < nums.end() - 1; j++) {
            left=nums.begin();
            right=nums.end()-1;
            while (left<right) {
                sum=*i+*j+*left+*right;
                if (sum==target) {
                    vector<int> t={*left,*i,*j,*right};
                    sort(t.begin(),t.end());
                    res.push_back(t);
                    break;
                }
                else if (sum>target) right--;
                else if (sum<target) left++;
                if (i==left || j==left) left++;
                if (i==right || j==right) right--;
            }
            
        }
    }
        for (int i=0;i<res.size();i++) {
        for (int j=0;j<res[i].size();j++)
            cout<<res[i][j]<<" ";
        cout<<endl;
    }
    cout<<"size:"<<res.size()<<endl;
    cout<<"size[1]:"<<res[0].size()<<endl;
    sort(res.begin(),res.end(),cmp);
    cout<<"size:"<<res.size()<<endl;
    cout<<"size[1]:"<<res[0].size()<<endl;
    for (int i=0;i<res.size();i++) {
        for (int j=0;j<res[i].size();j++)
            cout<<res[i][j]<<" ";
        cout<<endl;
    }
 
    unique(res.begin(),res.end(),eq);
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
    vector<int> nums={0,7,8,8,-10,1,8,-1,7,-10,-7};
    int target=7;
    auto res = Solution().fourSum(nums,target);
    cout << res.size() << endl;
    for (auto &v:res) {
        if (v.size()!=0) {
            for (auto &i:v) 
                cout<<i<<" ";
            cout<<endl;
        }
    }
    return 0;
}