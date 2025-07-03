#include<iostream>
#include<vector>
using namespace std;

int solve(){
    int n,k;
    cin>>n>>k;
    vector<int>a(n);
    for(auto &i:a)cin>>i;

    for(int i=0;i<n;i++){
        bool div=false;
        for(int j=0;j<n;j++){
            if(i==j)continue;
            if(abs(a[i]-a[j])%k==0)div=true;
        }
        if(!div)return i+1;
    }
    return -1;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        int temp=solve();
        if(temp==-1){
            cout<<"NO\n";
        }else{
            cout<<"YES\n"<<temp<<"\n";
        }
    }
}