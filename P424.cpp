#include "header.h"
#include <array>
#include <cstdlib>

#define N 10001

class Solution {
public:
    int characterReplacement(string s, int k) {
        int head, tail, n;
        array<bool, 26> letterSet;
        letterSet.fill(false);
        n = s.size();
        for (int i=0; i<n; i++)
            letterSet[s[i]-'A'] = true;
        int maxDist = 0;
        for (int t=0; t<26; t++) {
            if (letterSet[t] == false) continue;
            head = tail = 0;
            int currTransfer = 0;
            int dist = 0;
            while (tail < n) {
                if (head>tail) {
                    tail=head;
                    currTransfer = 0;
                }
                if (currTransfer+1 <= k) {
                    if (s[tail]-'A' != t) currTransfer++;
                    tail++;
                }
                else {
                    if (s[tail]-'A' == t) {
                        tail++;
                    }
                    else {
                        if (s[head]-'A'!=t) currTransfer--;
                        head++;
                    }
                }
                if (tail-head > dist) dist = tail-head;
            }
            maxDist = max(maxDist, dist);
        }
        return maxDist;

    }
};

int main(int argc, char const *argv[])
{
    string s = "AAABBBABCAABVC";
    int k = 4;
    cout << Solution().characterReplacement(s,k) << endl;
    cout << Solution().characterReplacement("ABAB",2) << endl;
    cout << Solution().characterReplacement("AABABBA",1) << endl;
    cout << Solution().characterReplacement("ABAA",0) << endl;
    return 0;
}
