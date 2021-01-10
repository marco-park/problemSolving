#include <iostream>
#include <string>
#include <cstring>

using namespace std; 
int a[300001],c[300001];


bool cmp(int i){
    return (a[i]>a[i+1] && a[i]>a[i-1]) || (a[i]<a[i+1] && a[i]<a[i-1]);
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while(t--){
       int n;
       cin >> n;
       int ret=0,ma=0;

       memset(c,0,sizeof(c));
       for(int i=0;i<n;i++)cin >> a[i];
       for(int i=1;i<n-1;i++){
           if(cmp(i)){
               ret++;c[i]++;c[i+1]++;c[i-1]++;
           }
       }
  
       for(int i=2;i<n-2;i++){
            bool flag = true;
            int t = a[i];
            a[i] = a[i-1];
            flag &= cmp(i+1);
            a[i] = a[i+1];
            flag &= cmp(i-1);
            a[i] = t;
            c[i]-=flag;
       }
       for(int i=0;i<n;i++){
           ma = max(ma,c[i]);
       }
       
       cout << ret-ma << '\n';
    }
}