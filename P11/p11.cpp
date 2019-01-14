#include<algorithm>
#include<vector>
#include<iostream>
#include<string>

using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        long long area;
        long long maxarea=0;
        auto left=height.begin();
        auto right=--height.end();
        while (left<right) {
            area = min(*left,*right)*(right-left);
            if (area>maxarea) maxarea=area;
            *left<*right?left++:right--;
        }
        return maxarea;
        
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
    vector<int> h={1,8,6,2,5,4,8,3,7};
    auto res = Solution().maxArea(h);
    cout << res <<endl;
    return 0;
}