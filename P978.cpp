#include "header.h"
#include <vector>

class Solution {
public:
    int maxTurbulenceSize(vector<int>& arr) {
        vector<int> more;
        more.resize(arr.size());
        for (size_t i =0; i<arr.size()-1; i++) {
            int t = arr[i]-arr[i+1];
            if (t==0) more[i] = 0;
            else if (t>0) more[i] = 1;
            else more[i] = -1;
        }
        int ans = 0;
        int i=0,j;
        int state;
        while (i<arr.size()-1) {
            state = more[i]*-1;
            j=i;
            while (j<arr.size() && more[j]*state<0) {
                state = more[j];
                j++;                
            }
            if (j-i+1 > ans) ans = j+1-i;
            if (i!=j) i = j; else i =j+1;
        }
        if (!arr.empty()) ans = max(ans, 1);
        return ans;
    }
};

int main() {
    vector<int> a = {9,4,2,10,7,8,8,1,9};

    cout << Solution().maxTurbulenceSize(a) << endl;
    a = {4,8,12,16};
    cout << Solution().maxTurbulenceSize(a) << endl;
    a={100};
    cout << Solution().maxTurbulenceSize(a) << endl;
    a={0,0,0,0};
    cout << Solution().maxTurbulenceSize(a) << endl;
    a={0,0,0,1,1,1,0,0,0};
    cout << Solution().maxTurbulenceSize(a) << endl;
    a={1,0,1,0,1};
    cout << Solution().maxTurbulenceSize(a) << endl;

    return 0;
}