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
             vector<int> &tmp,
             vector<int> &cnt) {
        if (target==0) {
            res.push_back(tmp);
            return;
        }
        if (target<0) return;
        if (n>=d.size()) return;
        for (int i=n;i<d.size();i++) {
            for (int k=1;k<=cnt[i];k++) {    
                for (int j=0;j<k;j++)
                    tmp.push_back(d[i]);
                dfs(res,d,target-d[i]*k,i+1,tmp,cnt);
                for (int j=0;j<k;j++)
                    tmp.pop_back();        
            }
        }
        return ;
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<int> d,tmp;
        vector<vector<int>> result;
        
        for (int i=0;i<candidates.size();i++) {
            if (candidates[i]<=target) d.push_back(candidates[i]);
        }
        if (d.empty()) return result;
        sort(d.begin(),d.end());
        vector<int> cnt(d.size(),1); 
        int i=1;
        while (i<d.size()) {
            while (i<d.size() && d[i]==d[i-1]) {
                d.erase(d.begin()+i);
                cnt[i-1]++;
            }
            i++;
        }
        dfs(result,d,target,0,tmp,cnt);
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
    //vector<int> can={10,1,2,7,6,1,5};
    vector<int> can={29,19,14,33,11,5,9,23,23,33,12,9,25,25,12,21,14,11,20,30,17,19,5,6,6,5,5,11,12,25,31,28,31,33,27,7,33,31,17,13,21,24,17,12,6,16,20,16,22,5};

    auto res = Solution().combinationSum2(can,28);
    for (auto i:res) {
        cout<<"[";
        for (auto v:i)
            cout<<v<<",";
        cout<<"]"<<endl;
    }
    return 0;
}