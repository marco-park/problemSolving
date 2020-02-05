#include <iostream>
#include <vector>
 
using namespace std;
 
int arr[200001];
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    int n,a,b,k;
    cin >> n >> a >> b >> k;
    vector<int>p;
    for(int i=0;i<n;i++)cin >> arr[i];
    int ret = 0;
    for(int i=0;i<n;i++){
        if(arr[i]<=a || (arr[i]%(a+b)<=a && arr[i]%(a+b)))ret++;
        else {
            if(arr[i]%(a+b))p.push_back(arr[i]%(a+b));
            else p.push_back(a+b);
        }
    }
    sort(p.begin(),p.end());
    for(int i=0;i<p.size();i++){
        if(k<=0)break;
        if(p[i]%a==0){
            if(k-(p[i]/a-1)<0)break;
            k-=(p[i]/a-1);
        }else{
            if(k-p[i]/a<0)break;
            k-=(p[i]/a);
        }
        ret++;
    }
    cout << ret << '\n';
}