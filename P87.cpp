#include<iostream>
#include<algorithm>
#include<string>

using namespace std;


#define XSUM(_x,_start,_len) (_x[(_start)+(_len)-1]^((_start)==0?0:_x[(_start)-1]))

class Solution {
public:
    bool isScramble(string s1, string s2) {
        len = s1.length();
        if (len != s2.length())
            return false;
        st1 = s1;
        st2 = s2;

        xsum1 = new int[len+1];
        xsum2 = new int[len+1];
        xsum1[0]=s1[0]*s1[0];
        xsum2[0]=s2[0]*s2[0];
        for (int i=1; i<len; i++) {
            xsum1[i]=xsum1[i-1]^(s1[i]*s1[i]);
            xsum2[i]=xsum2[i-1]^(s2[i]*s2[i]);
        }
        for (int i=0;i<len;i++)
            for (int j=0;j<len;j++) {
                for (int k=0;k<=len;k++)
                    //f[i][j][k]=-1;
                    f[i][j][k]=false;
                if (s1[i]==s2[j])
                    f[i][j][1]=true;
            }
        return checkDP(0,0,len);
    }
    bool checkDP(int h1, int h2, int hlen) {
        for (int l = 2; l <= hlen; l++)
            for (int i = 0; i < hlen-l+1; i++)
                for (int j = 0; j < hlen-l+1; j++) {
                    if (check(i, j, l) == false) {
                        f[i][j][l] == false;
                        continue;
                    }
                    f[i][j][l]=false;
                    for (int k=1;k<l;k++) {
                        if (f[i][j][k] && f[i+k][j+k][l-k]) {
                            f[i][j][l]=true;
                            break;
                        } else if (f[i][j+(l-k)][k] && f[i+k][j][l-k]) {
                            f[i][j][l]=true;
                            break;
                        }
                    }
                    
                }
        return f[h1][h2][hlen];
    }
    bool checkSplit(int h1, int h2, int hlen) {
        int l1,l2,l3;
        if (f[h1][h2][hlen]!=-1)
            return f[h1][h2][hlen]==1;
        bool basic;
        basic = check(h1, h2, hlen);
        if (!basic) {
            f[h1][h2][hlen] = 0;
            return false;
        }
        else if (hlen<=3) {
            f[h1][h2][hlen] = 1;
            return true;
        }
        for (l1=1;l1<hlen;l1++)
            for (l2=1;l2<hlen-l1;l2++) {
                l3 = hlen-l1-l2;
                
                bool status=false;
                status = testSplit(h1, h2, hlen, l1, l2, l3);
                if (status) {
                    cout << h1 << " " << h2 << " " << hlen << endl;
                    cout << l1 << " " << l2 << " " << l3 << endl;
                    f[h1][h2][hlen] = 1;
                    return true;
                }
            }
        f[h1][h2][hlen] = 0;
        return false;
    }
    bool check(int h1,int h2,int hlen) {
        if ((XSUM(xsum1,h1,hlen)^XSUM(xsum2,h2,hlen))!=0)
            return false;
        string t1=st1.substr(h1,hlen);
        string t2=st2.substr(h2,hlen);
        sort(t1.begin(),t1.end());
        sort(t2.begin(),t2.end());
        return t1==t2;        
    }
    bool testSplit(int h1,int h2, int hlen, int l1, int l2,int l3) {
        bool res = false;
        bool cb[9];
        int a = h1, b = h1 + l1, c = h1 + l1 + l2;
        //123
        res = checkSplit(a, h2, l1) && 
              checkSplit(b, h2 + l1, l2) && 
              checkSplit(c, h2 + l1 + l2, l3);
        if (res) return true;
        //132
        res = checkSplit(a, h2, l1) &&
              checkSplit(b, h2 + l1 + l3, l2) &&
              checkSplit(c, h2 + l1, l3);
        if (res) return true;
        //213
        res = checkSplit(a, h2 + l2, l1) &&
              checkSplit(b, h2, l2) &&
              checkSplit(c, h2 + l2 + l1, l3);
        if (res) return true;
        //231
        res = checkSplit(a, h2 + l2 + l3, l1) &&
              checkSplit(b, h2, l2) &&
              checkSplit(c, h2 + l2, l3);
        if (res) return true;
        //312
        res = checkSplit(a, h2 + l3, l1) &&
              checkSplit(b, h2 + l3 + l1, l2) &&
              checkSplit(c, h2, l3);
        if (res) return true;
        //321
        res = checkSplit(a, h2 + l3 + l2, l1) &&
              checkSplit(b, h2 + l3, l2) &&
              checkSplit(c, h2, l3);
        if (res) return true;
        return false;
    }

    void test() {
        string s1;
        string s2;
        //cin>>s1>>s2;
        s1="abcdefghijklmnopq";
        s2="efghijklmnopqcadb";

        cout << isScramble(s1,s2) << endl;
        return;
    }
    void test1() {
        string s1="cbcbabc";
        string s2="bbbccca";

        cout << isScramble(s1,s2)<<endl;
        return;
    }

private:
    string st1,st2;
    int *xsum1, *xsum2;
    int len;
    int f[100][100][100];
};

int main() {
    Solution().test();
    Solution().test1();
    return 0;
}