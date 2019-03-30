#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;


class Solution {
public:
    int trap(vector<int>& height) {
        vector<int>::const_iterator left,right;
        if (height.empty()) return 0;
        left=height.begin();
        right=height.end()-1;
        int off=0;
        int ret=0;
        while (left<right) {
            while (left<right && *left<=off) {
                if (off!=0) ret+=off-*left;
                left++;
            }
            while (left<right && *right<=off) {
                if (off!=0) ret+=off-*right;
                right--;
            }
            if (*left==0||*right==0) break;
            off=min(*left,*right);
        }
        return ret;
    }
};

class Solution1 {
public:
    int trap(vector<int>& height) {
        int left,right;
        if (height.empty()) return 0;
        left=0;
        right=height.size()-1;
        int off=0;
        int ret=0;
        while (left<right) {
            while (left<right && height[left]<=off) {
                ret+=off-height[left];
                left++;
            }
            while (left<right && height[right]<=off) {
                ret+=off-height[right];
                right--;
            }
            off=min(height[left],height[right]);
        }
        return ret;
    }
};