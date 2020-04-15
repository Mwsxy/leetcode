#include<algorithm>
#include<vector>
#include<iostream>
#include<string>
#include<stack>

using namespace std;

/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
struct Interval {
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};

bool cmpS(const Interval &a, const Interval &b) {
    return a.start<b.start;
}

class Solution {
public:
    vector<Interval> merge(vector<Interval>& intervals) {
        if (intervals.empty() || intervals.size()<=1) return intervals;
        sort(intervals.begin(),intervals.end(),cmpS);
        vector<Interval> ans;
        auto i=intervals.begin();
        int s,e;
        s=i->start;e=i->end;
        i++;
        while (i!=intervals.end()) {
            if (e>=i->start) {
                e=max(e,i->end);
            }
            else {
                ans.push_back(Interval(s,e));
                s=i->start;
                e=i->end;
            }
            i++;
        }
        ans.push_back(Interval(s,e));
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
    a.push_back(Interval(1,4));
    a.push_back(Interval(4,5));
    a.push_back(Interval(5,6));
    a.push_back(Interval(2,3));
    a.push_back(Interval(7,8));
    auto res = Solution().merge(a);
    for (auto v:res)
        cout << v.start << " " << v.end<< endl;
    return 0;
}