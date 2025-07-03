#include<iostream>
#include <vector>
#include <algorithm>
#include <limits>

using namespace std;

void solve(){
    int n;
    cin>>n;
    vector<int>a(n);
    for(auto &i:a)cin>>i;

    for(int i=0;i<n-1;i++){
        if(abs(a[i]-a[i+1])<=1){
            cout<<0<<endl;
            return;
        }
    }

    if(n==2){
        cout<<-1<<endl;
        return;
    }

    int op=numeric_limits<int>::max();

    for(int i=0;i<n-1;i++){
        int minv=min(a[i],a[i+1]);
        int maxv=max(a[i],a[i+1]);

        if(i==0){
            if(a[i+2]>=minv-1 && a[i+2]<=maxv+1){
            cout<<1<<endl;
            return;}
        }else if(i==n-2){
            if(a[i-1]>=minv-1 && a[i-1]<=maxv+1){
            cout<<1<<endl;
                return;}
        }else{
            if((a[i+2]>=minv-1 && a[i+2]<=maxv+1)||(a[i-1]>=minv-1 && a[i-1]<=maxv+1)){
            cout<<1<<endl;
            return;}
        }
    }
    cout<<-1<<endl;
    
}

int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}