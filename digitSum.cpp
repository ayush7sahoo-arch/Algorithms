#include<iostream>
using namespace std;

void solve(){
    int x,y;
    cin>>x>>y;
    if(y>x && y-x==1)cout<<"YES";
    else if(y<x && (x-y)%9==8)cout<<"YES";
    else cout<<"NO";
    cout<<endl;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}