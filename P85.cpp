#include "mhead.h"

using namespace std;

class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int m=matrix.size();
        if (m==0) return 0;
        int n=matrix[0].size();
        if (n==0) return 0;

        int **f = new int *[m];
        for (int i=0;i<m;i++) f[i]=new int[n];
        for (int i=0;i<m;i++)
            for (int j=0;j<n;j++) f[i][j]=matrix[i][j]-'0';


                int s1,s2;
                for (int i=0;i<m;i++)
                for (int j=0;j<n;j++) {
                for (int ri=0;ri<m;ri++)
                for (int rj=0;rj<n;rj++)
                    {
                        int x=i+ri,y=j+rj;
                        if (x==i && y==j) continue;
                        if (x>=m || y>=n) continue;
                        if (matrix[x][y]==0) {
                            f[x][y]=f[x-1][y-1];
                            continue;
                        }
                        s1=0;
                        if (ri>0 && y-1>=0) {
                            for (int k=i;k<=x-1;k++) s1+=matrix[k][y];
                            if (s1==x-i) {
                                if (f[x-1][y-1]==(ri)*(rj))
                                    f[x-1][y] = max(f[x-1][y],f[x-1][y-1]+s1);
                                else
                                    f[x-1][y] = max(f[x-1][y],s1);
                            }
                            else
                                f[x-1][y] = max(f[x-1][y],f[x-1][y-1]);
                        }
                        s2=0;
                        if (rj>0 && x-1>=0) {
                            for (int k=j;k<=y-1;k++) s2+=matrix[x][k];
                            if (s2==y-j) {
                                if (f[x-1][y-1]==(ri)*(rj))
                                    f[x][y-1] = max(f[x][y-1],f[x-1][y-1]+s2);
                                else
                                    f[x][y-1] = max(f[x][y-1],s2);
                            }
                            else
                                f[x][y-1] = max(f[x][y-1],f[x-1][y-1]);
                        }
                        if (ri>0 && rj>0) {
                            if (s1==x-i && s2==y-j) {
                                if (f[x-1][y-1]==ri*rj)
                                    f[x][y] = max(f[x][y],f[x-1][y-1]+s1+s2+1);
                                else
                                    f[x][y] = max(f[x][y],max(s1,s2)+1);
                            }
                            else
                                f[x][y] = max(f[x][y],f[x-1][y-1]);
                        }
                    }
                    for (int i1=0;i1<m;i1++) {
                        for (int i2=0;i2<n;i2++)
                            cout << f[i1][i2] << " ";
                        cout << endl;
                    }
                    cout << i << " : "<< j << endl;
                }
        return f[m-1][n-1];

    }
    void SolutionTest() {
        vector<vector<char>> a={
  {'1','0','1','0','0'},
  {'1','0','1','1','1'},
  {'1','1','1','1','1'},
  {'1','0','0','1','0'}
};
        auto k = maximalRectangle(a);
        cout<<k<<endl;
        return;
    }
};
