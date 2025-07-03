#include<iostream>
using namespace std;

void solve(){
    int l,r,u,d;
    cin>>l>>r>>d>>u;
    if(l==r && u==d && l==u){
        cout<<"YES"<<endl;
    }else{
        cout<<"NO"<<endl;
    }

}

int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}