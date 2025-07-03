#include<iostream>
#include<vector>
using namespace std;

void solve(){
    int n;
    cin>>n;
    vector<long long int>a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    vector<long long int>rp(n+1,0);
    vector<long long int>lp(n+1,0);
    for(int i=n-1;i>=0;i--){
        if(a[i]<0){
            rp[i]=rp[i+1]+a[i];
        }else{
            rp[i]=rp[i+1];
        }
    }
    
    for(int i=1;i<n+1;i++){
        if(a[i-1]>0){
            lp[i]=lp[i-1]+a[i-1];
        }else{
            lp[i]=lp[i-1];
        }
    }
    // for(int i=0;i<n+1;i++){
    //     cout<<rp[i]<<" ";
    // }
    
    long long ans=0;
    for(int i=0;i<n+1;i++){
        ans=max(lp[i]+abs(rp[i]),ans);
    }
    cout<<ans<<endl;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}