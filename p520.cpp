#include<cctype>
#include<string>
using namespace std;
class Solution {
public:
    bool detectCapitalUse(string word) {
        if (word.size()<=1) return true;
        auto low=islower(word[1]);
        for (auto i=2;i<word.size();i++)
            if (low!=islower(word[i])) return false;
        if (!low && islower(word[0])) return false;
        return true;
    }
};