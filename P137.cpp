#include "header.h"

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int a,b;
        a = b = 0;
        for (const int &x:nums) {
            a = (a ^ x) & ~b;
            b = (b ^ x) & ~a;
        }
        return a;
    }
};

int main() {
    return 0;
}