#include<iostream>
#include<vector>
#include<math.h>
using namespace std;


void solve(){
    vector<int>a(100000);
    int n;
    cin>>n;
    a[1]=1;
    int b=1,i=2,d=3;
    while(b<=100000){
        a[i]=a[i-1]+d;
        b=a[i];d*=2;
        // cout<<a[i]<<" ";
        i++;
    }
    int ans=1;
    while(a[ans]<n)ans++;
    cout<<ans<<endl;
    
}

int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}