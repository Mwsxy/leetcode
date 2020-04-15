#include<algorithm>
#include<vector>
#include<iostream>
#include<string>
#include<stack>

using namespace std;
struct Interval {
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};


class Solution {
public:
    vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
        vector<Interval> ans;

        if (intervals.empty()) {
            ans.push_back(newInterval);
            return ans;
        }
        int s,e;
        s=newInterval.start;
        e=newInterval.end;
        bool mged=false;
        for (auto v:intervals) {
            if (v.end<s || v.start>e) {
                if (v.start>e && !mged) {
                    ans.push_back(Interval(s,e));
                    mged=true;
                }
                ans.push_back(v);
            }
            else {
                s=min(s,v.start);
                e=max(e,v.end);
            }
        }
        if (!mged) {
            ans.push_back(Interval(s,e));
        }
        return ans;
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
    vector<Interval> a;
    a.push_back(Interval(1,5));
    // a.push_back(Interval(3,5));
    // a.push_back(Interval(6,7));
    // a.push_back(Interval(8,10));
    // a.push_back(Interval(12,16));
    Interval b(2,3);

    auto res = Solution().insert(a,b);
    for (auto v:res)
        cout << v.start<<" "<<v.end <<endl;
    return 0;
}