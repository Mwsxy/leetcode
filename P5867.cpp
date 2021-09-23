#include "header.h"

class Solution {
public:
    string reversePrefix(string word, char ch) {
        auto e = word.find_first_of(ch);
        size_t b = 0;
        while (b<e && e!=word.npos)
            swap(word[b++], word[e--]);
        return word;
    }
};