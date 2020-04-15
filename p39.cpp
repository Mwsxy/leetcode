#include<algorithm>
#include<vector>
#include<iostream>
#include<string>

using namespace std;

class Solution {
public:
    void dfs(vector<vector<int>> &res,
             vector<int> &d,
             int target,
             int n,
             vector<int> &tmp) {
        if (target==0) {
            res.push_back(tmp);
            return;
        }
        if (n>=d.size()) return;
        for (int i=n;i<d.size();i++) {
            for (int k=1;k<=target/d[i];k++) {    
                for (int j=0;j<k;j++)
                    tmp.push_back(d[i]);
                dfs(res,d,target-d[i]*k,i+1,tmp);
                for (int j=0;j<k;j++)
                    tmp.pop_back();        
            }
        }
        return ;
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> d,tmp;
        vector<vector<int>> result;
        
        for (int i=0;i<candidates.size();i++) {
            if (candidates[i]<=target) d.push_back(candidates[i]);
        }
        if (d.empty()) return result;
        dfs(result,d,target,0,tmp);
        return result;
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
    vector<int> can={2,3,5};
    auto res = Solution().combinationSum(can,8);
    for (auto i:res) {
        cout<<"[";
        for (auto v:i)
            cout<<v<<",";
        cout<<"]"<<endl;
    }
    return 0;
}