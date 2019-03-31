#include<algorithm>
#include<vector>
#include<iostream>
#include<string>
#include<stack>

using namespace std;

bool eq(vector<int>,vector<int>);

class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ret;
        // sort(nums.begin(),nums.end());

        int len=nums.size();
        auto flag = new bool [len+1];
        for (int i=0;i<len;i++)
            flag[i]=false;
        int n=0;
        int select;
        vector<int> tmp;
        stack<int> st;
        int last=0;
        st.push(-1);
        do {
            select=-1;
            for (int i=last;i<len;i++)
                if (flag[i]==false) {
                    select=i;
                    break;
                }
            if (select!=-1) {
                flag[select]=true;
                tmp.push_back(nums[select]);
                st.push(select);
                last=0;
            }
            else {
                if (st.size()==len+1) ret.push_back(tmp);
                tmp.pop_back();
                last=st.top();
                st.pop();
                if (last==-1) break;
                flag[last]=false;
                last++;
            }
        }while (!st.empty());

        auto e=unique(ret.begin(),ret.end(),eq);
        ret.resize(e-ret.begin());
        return ret;
    }
};

bool eq(const vector<int> a, const vector<int> b) {
    if (a.size()!=b.size()) return false;
    for (int i=0;i<a.size();i++) 
        if (a[i]!=b[i]) return false;
    return true;
}
static const auto io_sync_off = []()
{
    // turn off sync
    std::ios::sync_with_stdio(false);
    // untie in/out streams
    std::cin.tie(nullptr);
    return nullptr;
}();


int main() {
    vector<int> input={1,1,1};
    auto res = Solution().permute(input);
    for (auto i:res) {
        for (auto j:i)
            cout <<j<<" ";
        cout<<endl;
    }
    return 0;
}