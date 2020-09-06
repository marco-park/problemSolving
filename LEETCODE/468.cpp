#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    const string ERR = "Neither";
    bool checkIPv4(string s){
        if(!s.size() || s.size()>3)return false;
        int ret = 0;
        for(int i=0;i<s.size();i++){
            char c=s[i];
            if(!(
                c>='0' && c<='9'
                ))return false;
            if(c=='0' && !i && s.size()!=1)return false;
            ret*=10;
            ret+=(c-'0');
        }
        return (ret>=0 && ret<=255);
    }

    bool checkIPv6(string s){
        if(!s.size() || s.size()>4)return false;
        for(auto c:s){ 
            if(!(
                (c>='a' && c<='f') || 
                (c>='A' && c<='F') || 
                (c>='0' && c<='9') 
                ))return false;
        }
        return true;
    }
    
    string validIPAddress(string IP) {
        int ipv4=0,ipv6=0;
        int ipv4Len=4,ipv6Len=8;
        for(auto c:IP){
            if(c=='.')ipv4++;
            else if(c==':')ipv6++;
        }
        if(!(
            (ipv4==ipv4Len-1 && !ipv6) || 
            (ipv6==ipv6Len-1 && !ipv4)
        ))return ERR;
        vector<string>p;

        char splt = ipv4 ? '.' : ':';
        int len = ipv4 ? ipv4Len : ipv6Len;
        string ret = ipv4? "IPv4" : "IPv6";

        IP+=splt;
        string str = "";
        for(auto c:IP){
            if(c==splt) p.push_back(str),str="";
            else str+=c;
        }
        if(p.size()!=len)return ERR;
        if(ipv4) {for(auto x:p)if(!checkIPv4(x))return ERR;}
        else {for(auto x:p)if(!checkIPv6(x))return ERR;}
        return ret;
    }
};