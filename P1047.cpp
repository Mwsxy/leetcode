#include "header.h"
#include <stack>
#include <string>

class Solution {
public:
    string removeDuplicates(string S) {
        string st;
        for (int i=0; i<S.length();) {
            if (st.empty() || st.back()!= S[i]) {
                st.push_back(S[i]);
                i++;
            }
            else {
                if (S[i]==st.back()) {
                    i++;
                    st.pop_back();
                }
            }
        }
        return st;
    }
};

int main() {
    string S;
    S = "aaaaaaa";
    cout << Solution().removeDuplicates(S) << endl;
    return 0;
}