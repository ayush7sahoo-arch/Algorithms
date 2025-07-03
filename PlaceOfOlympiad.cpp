#include<iostream>
#include<math.h>
using namespace std;
#define ll long long
#define dd double

void solve(){
    ll n,m,k;
    cin>>n>>m>>k;

    ll col=(k-1)/n+1;
    ll gap=m-col;
    ll ans=ceil((dd)col/(dd)(gap+1));

    cout<<ans<<endl;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}