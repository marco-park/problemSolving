#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <stack>
#include <string>

using namespace std;

bool cmp(string s){
    stack<char> st;
    for(int i=0;s[i];i++){
        if(!st.empty()){
            char t = st.top();
            if(t=='(' && s[i] == ')')st.pop();
            if(t=='(' && s[i] == '(')st.push(s[i]);
            if(t==')' && s[i] == '(')return false;
            if(t==')' && s[i] == ')')st.push(s[i]);
        }else st.push(s[i]);
    }
    return st.empty();
}

bool cmp2(string s){
    int a=0,b=0;
    for(auto c:s)
        if(c=='(')a++;else b++;
    return a==b;
}

string solution(string s){
    if(cmp(s))return s;
    string ret = "";
    if(!s.size())return "";
    for(int i=0;i<s.size();i++){
        string u = s.substr(0,i+1);
        string v = s.substr(i+1);
        if(!cmp2(u) || !cmp2(v))continue;
        if(cmp(u)){
            return ret+=u+solution(v);
        }else{
            string tmp = "";
            tmp+="(";
            tmp+=solution(v);
            tmp+=")";
            u = u.substr(1,u.size()-2);
            for(int i=0;i<u.size();i++){
                if(u[i]=='(')tmp+=")";
                else tmp+="(";
            }
            return tmp;
        }
    }
    return ret;
}