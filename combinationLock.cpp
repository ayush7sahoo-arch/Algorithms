#include<iostream>
#include<vector>
using namespace std;

void solve(){
    int n;
    cin>>n;
    if(n%2==0){
        cout<<-1<<endl;
        return;
    }
    // vector<int>a(n);
    // for(int i=0;i<n;i++){
    //     cin>>a[i];
    // }
    //pritn all the odd no. 
    for(int i=1;i<=n;i+=2){
        cout<<i<<" ";
    }
    //print all the even no.
    for(int i=2;i<=n;i+=2){
        cout<<i<<" ";
    }
    cout<<endl;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}