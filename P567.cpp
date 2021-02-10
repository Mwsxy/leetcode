#include "header.h"
#include <array>
#include <cstddef>

class Solution {
public:
    array<int, 26> letter1, letter2, t;

    bool checkInclusion(string s1, string s2) {
        letter1.fill(0);
        letter2.fill(0);
        for (const auto &v:s1) {
            letter1[v-'a']++;
        }
        for (const auto &v:s2) {
            letter2[v-'a']++;
        }
        for (size_t i=0; i<26; i++) {
            if (letter2[i]<letter1[i]) 
                return false;
        }
        size_t head,tail;
        head = tail = 0;
        t.fill(0);
        while (tail<s2.size()) {
            size_t c = s2[tail]-'a';
            // cout << head << " "<< tail << endl;

            if (t[c] < letter1[c]) {
                t[c]++;
                tail++;
                if (tail-head == s1.size()) {
                    // cout << head << " "<< tail << endl;
                    return true;
                }
            }
            else if (letter1[c]==0){
                t.fill(0);
                head=tail+1;
                tail=tail+1;
            } 
            else {
                size_t cc = s2[head]-'a';
                t[cc]--;
                head++;
                if (head>tail) tail = head;
            }
        }
        return false;
    }
};

int main() {
    cout << Solution().checkInclusion("ab", "eidbaooo") << endl;
    cout << Solution().checkInclusion("ab", "eidboaooo") << endl;
    cout << Solution().checkInclusion("adc", "dcda") << endl;
    cout << Solution().checkInclusion("aa", "aaaaaa") << endl;
    return 0;
}