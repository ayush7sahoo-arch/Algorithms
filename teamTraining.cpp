#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void solve(){
    int n,x;
    cin>>n>>x;
    vector<int>p(n);
    for(int i=0;i<n;i++){
        cin>>p[i];
    }
    sort(p.begin(),p.end());
    int team=0;
    for(int j=n-1,i=n-1;i>=0 && j>=0;i--){
        int r=j-i+1;
        if(r*p[i]>=x){
        team++;
        j=i-1;
        }
    }
    cout<<team<<endl;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }

}