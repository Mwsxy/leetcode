#include<algorithm>
#include<vector>
#include<iostream>
#include<string>
#include<stack>

using namespace std;

class Solution {
public:
    int maxSumTwoNoOverlap(vector<int>& A, int L, int M) {
        int sum[2000];
        int s=0;
        for (int i=0;i<A.size();i++) {
            s+=A[i];
            sum[i]=s;
        }
        int ans=0;
        int N=A.size();
        for (int i=0;i<N-L+1;i++) {
            for (int j=i+L;j<N-M+1;j++) {
                cout<<i<<" "<<j<<endl;
                s=sum[i+L-1]-(i>0?sum[i-1]:0);
                s+=sum[j+M-1]-(j>0?sum[j-1]:0);
                if (s>ans) ans=s;
            }
        }
        
        for (int j=0;j<N-M+1;j++) {
            for (int i=j+M;i<N-L+1;i++) {
                s=sum[i+L-1]-(i>0?sum[i-1]:0);
                s+=sum[j+M-1]-(j>0?sum[j-1]:0);
                if (s>ans) ans=s;
            }
        }
        return ans;
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
    vector<int> a={2,1,5,6,0,9,5,0,3,8};

    auto res = Solution().maxSumTwoNoOverlap(a,4,3);
    cout << res <<endl;
    return 0;
}