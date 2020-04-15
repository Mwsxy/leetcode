/*
 * @lc app=leetcode.cn id=43 lang=cpp
 *
 * [43] 字符串相乘
 *
 * https://leetcode-cn.com/problems/multiply-strings/description/
 *
 * algorithms
 * Medium (37.41%)
 * Total Accepted:    9.4K
 * Total Submissions: 25.1K
 * Testcase Example:  '"2"\n"3"'
 *
 * 给定两个以字符串形式表示的非负整数 num1 和 num2，返回 num1 和 num2 的乘积，它们的乘积也表示为字符串形式。
 * 
 * 示例 1:
 * 
 * 输入: num1 = "2", num2 = "3"
 * 输出: "6"
 * 
 * 示例 2:
 * 
 * 输入: num1 = "123", num2 = "456"
 * 输出: "56088"
 * 
 * 说明：
 * 
 * 
 * num1 和 num2 的长度小于110。
 * num1 和 num2 只包含数字 0-9。
 * num1 和 num2 均不以零开头，除非是数字 0 本身。
 * 不能使用任何标准库的大数类型（比如 BigInteger）或直接将输入转换为整数来处理。
 * 
 * 
 */
#include<iostream>
#include<string>
#include<algorithm>
#include<cstring>

using namespace std;

class Solution {
public:
    string multiply(string num1, string num2) {
        int ret[300];
        const int ten[5]={1,10,100,1000,10000};
        if (num1[0]=='0' || num2[0]=='0') return "0";
        int l1,l2;
        l1=num1.size();
        l2=num2.size();
        memset(ret,0,(l1+l2)*sizeof(int));
        int off,tmp,pos;
        for (int i=l1-1;i>=0;i--) {
                    // for (int p=0;p<l1+l2;p++)
                    //     cout << ret[p] << " ";
                    // cout<<endl;
            
            off=l1-1-i;
            for (int j=l2-1;j>=0;j--) {
                tmp=(num1[i]-'0')*(num2[j]-'0');
                pos=l2-1-j+off;
                ret[pos/4]+=tmp*(ten[pos%4]);
            }
            
        }

        // for (int p=0;p<(l1+l2)/4+1;p++)
        //     cout << ret[p] << " ";
        // cout<<endl;
        string r="";
        for (int i=0;i<=(l1+l2)/4;i++) {
            ret[i+1]+=ret[i]/ten[4];
            ret[i]%=ten[4];
        }
        int n=(l1+l2)/4;
        while (ret[n]==0) n--;
        r=to_string(ret[n]);
        n--;
        char t[10];
        while (n>=0) {
            sprintf(t,"%04d",ret[n]);
            n--;
            r=r+string(t);
        }
        return r;
    }
};

int main() {
    string num1="10000";
    string num2="1";
    auto k=Solution().multiply(num1,num2);
    cout <<k<<endl;
    cout<<endl;
    return 0;
}

