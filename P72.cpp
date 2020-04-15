#include<iostream>
#include<string>
#include<algorithm>

using namespace std;


class Solution {
public:
    int minDistance(string word1, string word2) {
        int f[100][100][100];
        int len1,len2,len;
        string w1,w2;
        if (word1.length() > word2.length()) {
            w1=word2;
            w2=word1;
        }
        else {
            w1=word1;
            w2=word2;
        }
        len1 = w1.length();
        len2 = w2.length();
        cout << "length: " << len1 << " " << len2 << endl;
        cout << "word: " << word1 << " " << word2 << endl;
        len = max(len1,len2);
        for (int i=0;i<=len;i++)
            for (int j=0;j<=len;j++) {
                for (int k=0;k<=len;k++)
                    f[i][j][k]=k;
                if (i<len1 && j<len2 && w1[i]==w2[j])
                    f[i][j][1]=0;
            }
        for (int l=2;l<=len;l++) {
            for (int i=0;i<len1-l+1;i++)
                for (int j=0;j<len2-l+1;j++) {
                    for (int k=0;k<l;k++) {
                        // transfer
                        f[i][j][l] = min(f[i][j][l], f[i][j][k] + f[i + k][j + k][l - k]);
                        // 1. change
                        f[i][j][l] = min(f[i][j][l], f[i][j][k] + f[i + k + 1][j + k + 1][l - k - 1] + 1);
                        // 2. del
                        f[i][j][l] = min(f[i][j][l], f[i][j][k] + f[i + k + 1][j + k][l - k] + 1);
                        // 3. add has 
                        f[i][j][l] = min(f[i][j][l], f[i][j][k] + f[i + k][j + k + 1][l - k - 1] + 1);
                    }
                }

        }
        return f[0][0][len2];
    }

    void test() {
        string s1("horse"),s2("ros");
        cout << minDistance(s1, s2) << endl;
        cout << minDistance("ros", "horse") << endl;
        cout << minDistance("horse", "ros") << endl;
        cout << minDistance("ros", "horse") << endl;
        cout << minDistance("intention", "execution") << endl;
        cout << minDistance("sea", "ate") << endl;
        return ;
    }
};

int main()
{
    Solution().test();
    return 0;
}
