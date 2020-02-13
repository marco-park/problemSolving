#include <iostream>

using namespace std;

int n;
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    int t;
    cin >> t;
    while(t--){
        cin >> n;
        string ret = "";
        if(n%2 == 0){
            for(int i=0;i<n/2;i++)ret+="1";
        }
        else if(n%2==1){
            ret = "7";
            for(int i=0;i<n/2-1;i++)ret+="1";
        }
        cout << ret << '\n';
    }
}