#include "header.h"
#include <array>
#include <bits/c++config.h>
#include <cstddef>
#include <cstring>
#include <vector>


#define LEN 5001
class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        array<bool, LEN> end;
        array<bool, LEN> visited;
        visited.fill(false);
        bool begin;
        bool hasEnd = false;
        end.fill(false);
        queue<pair<int, int>> q;
        for (size_t i=0; i<wordList.size(); i++) {
            if (transfer(beginWord, wordList[i])) begin = true;
            else begin=false;
            if (transfer(endWord, wordList[i])) end[i] = true;
            if (endWord == wordList[i]) hasEnd = true;
            if (begin) {
                q.emplace(i,2);
                visited[i] = true;
            }
        }
        if (!hasEnd) return 0;
        if (transfer(beginWord, endWord)) return 2;
        const size_t &n = wordList.size();
        static int map[LEN][LEN];
        for (size_t i=0; i<n; i++) 
            map[i][0] = 0;
        for (size_t i=0; i<n; i++) {
            for (size_t j=i+1; j<n; j++) {
                if (transfer(wordList[i], wordList[j])) {
                    map[i][++map[i][0]] = j;
                    map[j][++map[j][0]] = i;
                }
            }
        }
        
        while (!q.empty()) {
            int _last = q.front().first;
            int _step = q.front().second;
            if (end[_last]) {
                return _step+1;
            }

            for (int i=1; i<=map[_last][0]; i++) {
                int j = map[_last][i];
                if (!visited[j]) {
                    q.emplace(j, _step+1);
                    visited[j] = true;
                }
            }
            q.pop();
        }
        return 0;
    }
private:
    bool transfer(const string &a,const string &b) {
        int differ = 0;
        if (a.size()!=b.size()) return false;
        for (size_t i=0; i<a.size(); i++)
            if (a[i]!=b[i]) {
                differ++;
                if (differ>1) return false;
            }
        if (differ==1) 
            return true;
        else 
            return false;
    }
};

int main() {
    string beginWord = "a";
    string endWord = "c";
    vector<string> wordList = {"a", "b", "c"};
    cout << Solution().ladderLength(beginWord, endWord, wordList) << endl;

    return 0;
}