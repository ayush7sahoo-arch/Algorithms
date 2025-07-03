#include<iostream>
using namespace std;

void solve(){
    int n;
    cin>>n;
    int sum=0;
    for(int i=0;i<n;i++){
        int temp;
        cin>>temp;
        sum+=temp;
    }
    cout<<sum-(n-1)<<endl;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}