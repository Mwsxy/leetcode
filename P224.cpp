#include "header.h"
#include <algorithm>
#include <cctype>
#include <stack>
#include <vector>

class Solution {
    bool A_first(char a, char b) {
        int v1,v2;
        switch (a) {
            case '(':
                {v1 = 3;break;}
            case '+':
                {v1 = 4;break;}
            case '-':
                {v1 = 5;break;}
            case ')':
                {v1 = 6;break;}
        }
        switch (b) {
            case '(':
                {v2 = 3;break;}
            case '+':
                {v2 = 4;break;}
            case '-':
                {v2 = 5;break;}
            case ')':
                {v2 = 6;break;}
        }
        return v1/2<=v2/2;
    }
public:
    // fin:100 +- 10  () 1 
    int calculate(string s) {
        vector<int> digit, dig_head, opt_head;
        vector<char> opt;
        // opt.push_back(100);
        dig_head.push_back(0);
        opt_head.push_back(0);
        for (int i=0; i<s.length(); ) {
            if (s[i] == ' ') {
                i++;
                continue;
            }
            if (s[i]>='0' && s[i]<='9') {
                int t=i, val=0;
                while (t<s.length() && s[t]>='0' && s[t]<='9') {
                    val= val*10 + (s[t]-'0');
                    t++;
                }
                i = t;
                digit.push_back(val);
            }
            else {
                while (opt.size()-opt_head.back()>0 && (A_first(opt.back(), s[i]))) {
                    switch (opt.back()) {
                        case '+':    // +
                        case '-': {  // -
                            int n1=0,n2;
                            if (digit.size()-dig_head.back()>=2) {
                                n2 = digit.back(); digit.pop_back();
                                n1 = digit.back(); digit.pop_back();
                            }
                            else {
                                n2 = digit.back(); digit.pop_back();
                            }
                            if (opt.back()=='+') {
                                n1 = n1+n2;
                            }
                            else if (opt.back()=='-') {
                                n1 = n1-n2;
                            }
                            digit.push_back(n1);
                            break;
                        }
                    }
                    opt.pop_back();
                }
                if (s[i]=='(') {
                    dig_head.push_back(digit.size());
                    opt_head.push_back(opt.size());
                }
                else if (s[i]==')') {
                    dig_head.pop_back();
                    opt_head.pop_back();
                }
                else opt.push_back(s[i]);                    
                i++;
            }
        }
        while (opt.size()-opt_head.back()>0) {
            switch (opt.back()) {
                case '+':    // +
                case '-': {  // -
                    int n1=0,n2;
                    if (digit.size()-dig_head.back()>=2) {
                        n2 = digit.back(); digit.pop_back();
                        n1 = digit.back(); digit.pop_back();
                    }
                    else {
                        n2 = digit.back(); digit.pop_back();
                    }
                    if (opt.back()=='+') {
                        n1 = n1+n2;
                    }
                    else if (opt.back()=='-') {
                        n1 = n1-n2;
                    }
                    digit.push_back(n1);
                    break;
                }
            }
            opt.pop_back();
        }
        // cout << "--- " << opt.size() <<" --- "<< digit.size() << " --- " << endl;
        // print(opt);
        // print(digit);
        return digit.back();
    }
};

int main() {
    string s = "1 + 1";
    // cout << Solution().calculate(s) << endl;
    s = " 2-1 + 2 ";
    cout << Solution().calculate(s) << endl;
    s = "(1+(4+5+2)-3)+(6+8)";
    cout << Solution().calculate(s) << endl;
    s = "2147483647";
    cout << Solution().calculate(s) << endl;
    s = "1+(-6+8)";
    cout << Solution().calculate(s) << endl;
    s = "-1";
    cout << Solution().calculate(s) << endl;
    return 0;
}