#include "header.h"
#include <unordered_map>
#include <vector>

class Solution {
private:
    inline int getHash(const string &s) {
        int h=0;
        for (const auto &c:s) {
            h |= 1 << (c - 'a');
        }
        return h;
    }
public:
    vector<int> findNumOfValidWords(vector<string>& words, vector<string>& puzzles) {
        unordered_map<int, int> words_hash;
        for (const auto &w:words) {
            int h = getHash(w);
            words_hash[h]++;
        }
        vector<int> ans(puzzles.size(), 0);
        for (int j=0; j<puzzles.size(); j++) {
            int &&puzzle_hash = getHash(puzzles[j]);
            int &&first = 1<<(puzzles[j][0]-'a');
            int k=0;
            for (int i=puzzle_hash; i; i=(i-1)&puzzle_hash)
                if ((i&first)!=0) ans[j] += words_hash[i];
        }
        return ans;
    }
};

int main() {
    vector<string> words, puzzles;
    
    words = {"aaaa","asas","able","ability","actt","actor","access"};
    puzzles = {"aboveyz","abrodyz","abslute","absoryz","actresz","gaswxyz"};
    print(Solution().findNumOfValidWords(words, puzzles));
    return 0;
}