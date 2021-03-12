#include "header.h"

class Solution {
    int getNum(const string &s, int p, int &num) {
        while (p<s.length() && s[p]==' ') p++;
        if (s[p]=='#') return 0;
        num = 0;
        int i=p;
        while (i<s.length() && s[i]!=',')
        {
            num = num*10 + (s[i]-'0');
            i++;
        }
        return i-p;
    }
public:
    bool isValidSerialization(string preorder) {
        int i=0;
        stack<int> id;
        while (i<preorder.length())
        {
            int len, num, k;
            len = getNum(preorder, i, num);
            i+=len;
            if (len>0) {
                id.push(num);
            }
            else {
                i++;
                if (!id.empty())
                    id.pop();
                else
                    break;
            }
            i += 1;
        }
        // printf("%d\n", i);
        return i==preorder.length() && id.empty();
    }
};

int main() {
    string s;
    s = "9,3,4,#,#,1,#,#,2,#,6,#,#";
    cout << Solution().isValidSerialization(s) << endl;
    s = "1,#";
    cout << Solution().isValidSerialization(s) << endl;
    s = "9,#,#,1";
    cout << Solution().isValidSerialization(s) << endl;
    return 0;
}