#include<iostream>
using namespace std;
#define ll long long

void solve(){
    ll n,k;
    cin>>n>>k;

    if(n%2==0){
        // n-=(k-1);
        ll ans=(n-1)/(k-1)+1;
        cout<<ans<<endl;
    }else{
        n-=k;
        ll ans=1;
        if(n>0){
            ans+=(n-1)/(k-1)+1;
        }
        cout<<ans<<endl;
    }
}

int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}