#include<iostream>
#include<vector>
#include<algorithm>
#define ll long long
using namespace std;

void solve(){
    int n,k;
    cin>>n>>k;
    vector<ll>a(n);
    for(auto &i:a)cin>>i;
    vector<ll>dum=a;
    sort(dum.begin(),dum.end());
    ll ans=0;
    for(int i=0;i<k;i++){
        ans+=dum[n-1-i];
    }
    ans+=dum[n-k-1];
    cout<<ans<<endl;
    

}

int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}