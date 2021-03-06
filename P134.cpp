#include "header.h"

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n=gas.size();
        int remain = 0, ans = 0;
        int _min = 0, _min_i = -1;
        for (int i=0; i<n; i++) {
            int t = gas[i]-cost[i];
            remain += gas[i] - cost[i];
            if (remain < _min) {
                _min = remain;
                _min_i = i;
            }
        }
        if (remain < 0) return -1;
        return _min_i+1;
        // -2 -2 -2 3 3 
    }
};

int main() {

    vector<int> gas, cost;
    gas = {1,2,3,4,5};
    cost = {3,4,5,1,2};

    cout << Solution().canCompleteCircuit(gas, cost) << endl;

    return 0;
}