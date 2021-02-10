#include "header.h"

class Solution {
public:
    inline bool inbound(const char &c) {
        if ((c>='0' && c<='9') ||
            (c>='a' && c<='z') ||
            (c>='A' && c<='Z'))
            return true;
        else return false;
    }
    inline bool equal(const char &_a, const char &_b) {
        if (_a==_b) return true;
        char a,b;
        if (_a>='A' && _a<='Z') 
            a = _a-'A'+'a';
        else 
            a = _a;
        if (_b>='A' && _b<='Z') 
            b = _b-'A'+'a';
        else 
            b = _b;

        return a==b;
    }
    bool isPalindrome(string s) {
        if (s.empty())  return true;
        int i,j;
        i=0;
        j=s.size()-1;
        while (i<j) {
            while (i<s.size() && !inbound(s[i])) i++;
            while (j>=0 && !inbound(s[j])) j--;
            if (i>=s.size() || j<0) break;
            if (!equal(s[i],s[j])) return false;
            i++;j--;
        }
        return true;
    }
};
int main() {
    cout << Solution().isPalindrome("A man, a plan, a canal: Panama") << endl;
cout << Solution().isPalindrome("race a car") << endl;
cout << Solution().isPalindrome("aBba") << endl;
cout << Solution().isPalindrome(".,") << endl;

    return 0;
}