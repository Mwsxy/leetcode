#include "header.h"
#include <cstdlib>
#include <vector>


class Solution {
public:
    int cost(const char &a, const char &b) {
        int c = (int)a-(int)b;
        return abs(c);
    }
    int equalSubstring(string s, string t, int maxCost) {
        int n = s.size();
        vector<int> c(n);
        for (int i=0; i<n; i++) {
            c[i] = cost(s[i], t[i]);
        }
        int maxDist = 0, currCost;
        int head, tail;
        head = tail = 0;
        currCost = 0;
        while (tail < n) {
            while (tail<n && c[tail]+currCost <= maxCost) {
                currCost += c[tail];
                tail++;
            }
            if (tail-head > maxDist)
                maxDist = tail-head;
            currCost-=c[head];
            head++;
            if (head>tail) {
                tail = head;
                currCost = 0;
            }
        }
        return maxDist;
    }
};

int main() {
    cout << Solution().equalSubstring("abcd", "bcdf", 3) << endl;
    cout << Solution().equalSubstring("abcd", "cdef", 3) << endl;
    cout << Solution().equalSubstring("abcd", "acde", 0) << endl;
    cout << Solution().equalSubstring("krrgw", "zjxss", 19) << endl;
    cout << Solution().equalSubstring("abcd", "acde", 0) << endl;
}