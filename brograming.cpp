#include<iostream>
using namespace std;

void solve(){
    int n;
    cin>>n;
    string s;
    cin>>s;
    int flips=0;
    for(int i=0;i<s.size()-1;i++){
        if(s[i]!=s[i+1])flips++;
    }
    cout<<flips+(s[0]=='1')<<endl;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}