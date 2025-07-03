#include<iostream>
#include<vector>
using namespace std;

void solve(){
    int n,s;
    cin>>n>>s;
    vector<int>p(n);
    for(int i=0;i<n;i++){
        cin>>p[i];
    }

    if(s >= p[0] && s <= p[n-1]){
        cout << (p[n-1] - p[0]) + min(s - p[0], p[n-1] - s) << "\n";
    }else if(s < p[0]){
        cout << p[n-1] - s << "\n";
    }else{
        cout << s - p[0] << "\n";
    }
}


int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}