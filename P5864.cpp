#include "header.h"

struct rec
{
    int val;
    int id;
    rec(int v, int i):val(v), id(i) {}
    bool operator < (const rec& b)
    {
        return this->val < b.val;
    }
};

class Solution {
public:
    int numberOfWeakCharacters(vector<vector<int>>& properties) {
        vector<int> atkOrd(100001, false), defOrd(10001, false);
        vector<rec> atk, def;
        atk.reserve(properties.size());
        def.reserve(properties.size());
        for (int i=0; i<properties.size(); i++)
        {
            atk.emplace_back(properties[i][0], i);
            def.emplace_back(properties[i][1], i);
        }
        sort(atk.begin(), atk.end());
        sort(def.begin(), def.end());
        int n = properties.size();
        int curA = 0, cntA = 0, ordA = 0;
        int curD = 0, cntD = 0, ordD = 0;
        int numA[10001], numD[10001];
        for (int i=0; i<n; i++)
        {
            if (atk[i].val>curA)
            {
                ordA += cntA;
                cntA = 0;
            }
            cntA++;
            numA[atk[i].id] = ordA;

            if (def[i].val>curD)
            {
                ordD += cntD;
                cntD = 0;
            }
            cntD++;
            numD[def[i].id] = ordD;
        }
        cout << cntA << " " << cntD << endl;
        for (int i=0; i<n; i++)
            cout << numA[i] << " " << numD[i] << endl;

        return 0;
    }
};