#include<iostream>
#include<vector>
#include<string>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> lastPos(128,-1);
        int i;
        unsigned char c;
        int begin=-1;
        int maxLen=0;
        for (i=0;i<s.size();i++) {
            c=s[i];
            begin = begin>lastPos[c]?begin:lastPos[c];
            lastPos[c]=i;
            if (i-begin>maxLen) {
                maxLen = i-begin;
            }
        }
        return maxLen;
    }
};


int main() {
    string s;
    cin>>s;
    cout << Solution().lengthOfLongestSubstring(s)<<endl;
    return 0;
}