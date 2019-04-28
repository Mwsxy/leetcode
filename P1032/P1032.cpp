#include<algorithm>
#include<vector>
#include<iostream>
#include<string>
#include<stack>

using namespace std;

class StreamChecker {
public:
    StreamChecker(vector<string>& words) {
        this->words=words;
        buffer="";
        for (auto w:words) {
            reverse(w.begin(),w.end());
            this->rwords.push_back(w);
        }
    }
    
    bool query(char letter) {
        buffer=letter+buffer;
        int n;
        for (auto v:this->rwords) {
            n=cmp(buffer,v);
            if (n==v.size()) return true;
        }
        return false;        
    }
private:
    vector<string> words;
    vector<string> rwords;
    string buffer;
    int cmp(const string a,const string b) {
        if (a.empty() || b.empty()) return -1;
        int i=0;
        while (i<a.size() && i<b.size() && a[i]==b[i])
            ++i;
        return i;
    }
};

/**
 * Your StreamChecker object will be instantiated and called as such:
 * StreamChecker* obj = new StreamChecker(words);
 * bool param_1 = obj->query(letter);
 */
static const auto io_sync_off = []()
{
    // turn off sync
    std::ios::sync_with_stdio(false);
    // untie in/out streams
    std::cin.tie(nullptr);
    return nullptr;
}();


int main() {
    vector<string> a= {"words","123"};
    StreamChecker* obj = new StreamChecker(a);
    cout<< obj->query('w') << endl;
    cout<< obj->query('o') << endl;
    cout<< obj->query('r') << endl;
    cout<< obj->query('d') << endl;
    cout<< obj->query('s') << endl;
    cout<< obj->query('w') << endl;
    return 0;
}