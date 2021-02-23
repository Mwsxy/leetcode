#include "header.h"


class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int X) {
        int hap = 0;
        for (int i=0; i<customers.size(); i++) {
            if (grumpy[i]==0) hap+=customers[i];
        }
        int win,h,t;
        h=0; t=X; win=0;
        for (int i=h; i<t && i<customers.size(); i++) {
            if (grumpy[i]==1) win+=customers[i];
        }
        int maxWin = win;
        while (t<customers.size()) {
            if (grumpy[t]==1) win+=customers[t];
            if (grumpy[h]==1) win-=customers[h];
            t++; h++;
            if (win>maxWin) maxWin = win;  
        }
        return hap+maxWin;
    }
};



int main() {
    vector<int> customers, grumpy;
    int X;
    customers = {1,0,1,2,1,1,7,5};
    grumpy    = {0,1,0,1,0,1,0,1};
    X = 3;
    cout << Solution().maxSatisfied(customers, grumpy, X) << endl;
    return 0;
}