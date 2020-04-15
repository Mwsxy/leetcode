#include<algorithm>
#include<vector>
#include<iostream>
#include<string>

using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string res="";
        int i=0;
        bool stop=false;
        while (stop==false && strs.size()!=0) {
            char k=0;
            for (auto st:strs) {
                if (i<st.size()) {
                    if (k==0) k=st[i];
                    else if (k!=st[i]) {
                        stop=true;
                        break;
                    }
                }
                else stop=true;
            }
            if (stop==false) {
                res=res+k;
                i++;
            }
        }
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
    return 0;
}