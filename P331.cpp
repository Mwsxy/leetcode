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
        int id = 0;
        while (i<preorder.length())
        {
            int len, num, k;
            len = getNum(preorder, i, num);
            i+=len;
            if (len>0) {
                id++;
            }
            else {
                i++;
                if (id>0)
                    id--;
                else
                    break;
            }
            i += 1;
        }
        // printf("%d\n", i);
        return i==preorder.length() && id==0;
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