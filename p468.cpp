#include<iostream>
#include<string>
#include<vector>
#include<cctype>

using namespace std;

int checkIPtype(string IP) {
    int dot=0;
    int colon=0;
    int letter=0;
    int num=0;
    int neither=0;
    for (auto v:IP) { 
        switch (v)
        {
            case '.':
                dot++;
                break;
            case ':':
                colon++;
                break;
            default:
                if (isdigit(v)) num++;
                else if ((v>='a' && v<='f')||
                         (v>='A' && v<='F')) letter++;
                else neither++;
                break;
        }
    }
    if (neither!=0) return -1;
    if (dot!=0 && (colon!=0 || letter!=0)) return -1;
    if (dot==3 && letter==0 && colon==0 && num>0) return 4;
    if (dot==0 && colon==7 && (letter>0 || num>0)) return 6;
    return -1;
}


class Solution {
public:
    string validIPAddress(string IP) {
        static string IPV4 = "IPv4";
        static string IPV6 = "IPv6";
        static string NEITHER = "Neither";

        auto tp=checkIPtype(IP);
        if (tp<0) return NEITHER;

        auto pos=IP.begin();
        auto pre=pos;
        string tmp;
        int len;
        if (tp==4) {
            int k;
            for (auto i=0;i<4;i++) {
                for (;*pos!='.'&&pos!=IP.end();pos++);  //split find seg
                if (pre==pos) return NEITHER;   //..1.2.3
                tmp=IP.substr(pre-IP.begin(),pos-pre);
                // cout<<tmp<<endl;
                len=pos-pre;
                if (tmp=="" || (tmp[0]=='0' && len!=1 )) return NEITHER;
                if (len>3) return NEITHER;  //maxmium is 255
                
                sscanf(tmp.c_str(),"%d",&k);    //string to int
                if (k>255) return NEITHER;  //<=255
                pre=++pos;
            }
            return IPV4;
        }
        else {
            int dcolon=0;
            for (auto i=0;i<8;i++) {
                for (;*pos!=':'&&pos!=IP.end();pos++);
                len=pos-pre;
                if (len>4) return NEITHER;
                if (len==0) {
                    dcolon++;
                    //:: is forbiden
                    if (dcolon>0) return NEITHER;
                }
                tmp=IP.substr(pre-IP.begin(),pos-pre);
                // cout<<tmp<<endl;
                pre=++pos;
            }
            return IPV6;
        }
    }
};

int main() {
    string test1=string("172.16.254.1");
    cin>>test1;
    auto c=new(Solution);
    string a=c->validIPAddress(test1);
    cout<<a<<endl;
    return 0;
}