#include<iostream>
#include<vector>
#include<string>

using namespace std;

//Thomas Wang's 32 bit Mix Function
/* Thomas Wang's32 bit Mix Function */
unsigned intdictIntHashFunction(unsigned int key)
{
    key += ~(key << 15);
    key ^= (key >> 10);
    key += (key << 3);
    key ^= (key >> 6);
    key += ~(key << 11);
    key ^= (key >> 16);
    return key;
}

class easyhash {
public:
    easyhash(int s=maxSize) {
        size=s;
        if (s>maxSize) s=maxSize;
        a=new struct Date [s];
    }
    int add(int x) {
        unsigned int pos=hashCode(x);
        if (!a[pos].check) {
            a[pos].check=true;
            a[pos].list
        }
    }
private:
    const static unsigned int maxSize = 1<<25;
    struct Date {
        bool check=false;
        int *list=nullptr;//TODO: change it to list rather than int array
    } *a;
    int size;
    unsigned int hashCode(int elem) {
        auto key = intdictIntHashFunction(elem);
        return key%size;
    }
};




class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        
    }
};


int main() {
    return 0;
}