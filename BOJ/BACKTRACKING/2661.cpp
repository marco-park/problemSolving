#include <iostream>
#include <string>

using namespace std;
int n;

bool foo(int idx,string s){
    for(int len = 1;len<=s.size()/2;len++){
        for(int start = 0;start+2*len-1<s.size();start++){
            if(s.substr(start,len)==s.substr(start+len,len))return false;
        }
    }
    if(idx==n){
        cout << s << '\n';
        return true;
    }
    for(int i=1;i<=3;i++){
        if(foo(idx+1,s+to_string(i)))return true;
    }
    return false;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    foo(0,"");
}
