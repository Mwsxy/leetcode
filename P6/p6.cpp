#include<algorithm>
#include<vector>
#include<iostream>
#include<string>

using namespace std;

class Solution {
public:
    string convert(string s, int numRows) {
        string res;
        int k;
        if (numRows<=1) return s;
        for (auto i=0;i<numRows;i++) {
            for (auto t=0;t<s.size();t++) {
                k=t%(2*(numRows-1));
                if (k==i) res+=s[t];
                if (k>=numRows && k%(numRows-1)+i==numRows-1) 
                    res+=s[t];
            }
        }
        return res;
    }
};

int main() {
    string s="LEETCODEISHIRING";
    cout << Solution().convert(s,4);
    return 0;
}