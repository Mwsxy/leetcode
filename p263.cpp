#include<iostream>
#include<vector>

using namespace std;

bool check235(int num) {
    int i;

}

class Solution {
public:
    bool isUgly(int num) {
        if (num==0) return false;//!!!!!!!
        while (num%30==0) num/=30;
        while (num%10==0) num/=10;
        while (num%6==0) num/=6;
        while (num%3==0) num/=3;
        while (num%5==0) num/=5;
        while ((num&1)==0) num>>=1;
        if (num==1) return true;
        cout<<num;
        return false;
    }
};