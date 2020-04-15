#include<algorithm>
#include<vector>
#include<iostream>
#include<string>
#include<stack>

using namespace std;

class Solution {
public:
    bool isNumber(string s) {
        if (s.empty()) return false;
        while (s[s.length()-1]==' ') s.pop_back();
        while (s[0]==' ') s.erase(s.begin());
        size_t pos_e = s.find('e');
        if (pos_e==string::npos) return isNumber_noE(s);
        string s1,s2;
        s1 = s.substr(0,pos_e);
        s2 = s.substr(pos_e+1);
        if (s2.find('e')!=string::npos) return false;
        if (s2.find('.')!=string::npos) return false;
        //  noE   e   noDot
        return isNumber_noE(s1) && isNumber_noE(s2);
    }
private:
    bool isNumber_noE(string s) {
        if (s.empty()) return false;
        if (s.find('e')!=string::npos) 
            return false;

        size_t pos_z = s.find('+');
        size_t pos_f = s.find('-');
        if (pos_f==string::npos && pos_z==string::npos) 
            return isNumber_noSig(s);
        if (pos_f!=string::npos && pos_z!=string::npos)
            return false;
        size_t pos = pos_z!=string::npos?pos_z:pos_f;
        string s1,s2;
        s1 = s.substr(0,pos);
        s2 = s.substr(pos+1);
        if (s1.empty()==false) return false;
        return isNumber_noSig(s2);
    }
    bool isNumber_noSig(string s) {
        if (s.empty()) return false;
        size_t pos_z = s.find('+');
        size_t pos_f = s.find('-');
        if (pos_f!=string::npos || pos_z!=string::npos) 
            return false;
        size_t pos_dot = s.find('.');
        if (pos_dot==string::npos) return isNumber_noDot(s);
        string s1,s2;
        s1 = s.substr(0,pos_dot);
        s2 = s.substr(pos_dot+1);
        if (s1.empty()) return isNumber_noDot(s2);
        if (s2.empty()) return isNumber_noDot(s1);
        return isNumber_noDot(s1) && isNumber_noDot(s2);
    }
    bool isNumber_noDot(string s) {
        if (s.empty()) return false;
        for (auto c:s)
            if (c<'0' || c>'9') return false;
        return true;
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
    string s;
    cout << Solution().isNumber("1 ")<<endl;
    cout << Solution().isNumber("+.1 ")<<endl;
    cout << Solution().isNumber(" +1 ")<<endl;
    while (true) {
        cin>> s;
        auto res = Solution().isNumber(s);
        cout <<res<<endl;
    }
    return 0;
}