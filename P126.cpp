#include "header.h"
#include <array>
#include <bits/c++config.h>
#include <cstddef>
#include <cstring>
#include <iostream>
#include <vector>


#define LEN 5001
class Solution {
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        const size_t &n = wordList.size();
        bool *end = new bool[n]();
        bool *visited = new bool[n]();
        bool begin;
        bool hasEnd = false;
        queue<pair<int, vector<int>>> q;
        for (size_t i=0; i<wordList.size(); i++) {
            if (transfer(beginWord, wordList[i])) begin = true;
            else begin=false;
            if (transfer(endWord, wordList[i])) end[i] = true;
            if (endWord == wordList[i]) hasEnd = true;
            if (begin) {
                vector<int> r = {(int)i};
                q.emplace(i,r);
                // visited[i] = true;
            }
        }
        if (!hasEnd) return {};
        if (transfer(beginWord, endWord)) {
            vector<vector<string>> ret;
            ret.push_back({beginWord, endWord});
            return ret;
        }
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
        bool found = false;
        int minStep = 100;

        vector<vector<string>> ret;
        
        while (!q.empty()) {
            int _last = q.front().first;
            vector<int> _step = q.front().second;
            visited[_last] = true;
            if (end[_last]&& _step.size()<=minStep) {
                minStep = _step.size();
                found = true;
                vector<string> a;
                a.push_back(beginWord);
                for (const auto &i:_step)
                    a.push_back(wordList[i]);
                a.push_back(endWord);
                ret.push_back(a);
            }
            else if (!found || _step.size()<=minStep)
                for (int i=1; i<=map[_last][0]; i++) {
                    int j = map[_last][i];
                    if (!visited[j]) {
                        _step.push_back(j);
                        q.emplace(j, _step);
                        _step.pop_back();
                    }
                }
            q.pop();
        }
        return ret;
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
    string beginWord = "red";
    string endWord = "tax";
    vector<string> wordList = {"ted","tex","red","tax","tad","den","rex","pee"};
    auto s = Solution().findLadders(beginWord, endWord, wordList);
    for (auto v1:s) {
        for (auto v2:v1) {
            cout << v2 << " ";
        }
        cout << endl;
    }

    return 0;
}