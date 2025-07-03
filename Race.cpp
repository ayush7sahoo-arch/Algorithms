#include<iostream>
using namespace std;

void solve(){
    int a,x,y;
    cin>>a>>x>>y;
    if(a<x && a<y)cout<<"YES"<<endl;
    else if(a>x && a>y)cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
}

int main(){
    int x;
    cin>>x;
    while(x--){
        solve();
    }
}