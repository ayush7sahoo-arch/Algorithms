#include<iostream>
using namespace std;

void solve(){
    long long int x,y,a;
    cin>>x>>y>>a;
    a%=(x+y);
    bool b=true;
    while(a>=0){
        a-=(b?x:y);
        b=!b;
    }
    cout<<(b?"YES\n":"NO\n");
}

int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}