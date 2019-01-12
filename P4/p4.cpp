#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;




class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        auto len1=nums1.size();
        auto len2=nums2.size();
        auto mid = (len1+len2)/2;
        
        auto p1=nums1.begin();
        auto p2=nums2.begin();
        auto i=0;
        int select,prev=0;
        while (p1!=nums1.end() || p2!=nums2.end()) {
            prev=select;
            if (p1==nums1.end()) {
                select=*p2;
                p2++;
                goto CHECK;
            }
            if (p2==nums2.end()) {
                select=*p1;
                p1++;
                goto CHECK;
            }
            if (*p1<*p2) {
                select=*p1;
                p1++;
            } 
            else {
                select=*p2;
                p2++;
            }
            CHECK:
            
            if (i==mid) break;
            i++;
        }
        if ((len1+len2)%2!=0) return (double)select;
        return (prev+select)/2.0;

    }
};

int main() {
   
    return 0;
}