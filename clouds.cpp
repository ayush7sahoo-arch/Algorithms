#include<iostream>
#include<vector>
using namespace std;

void solve(){
    int n;
    cin>>n;
    string s;
    cin>>s;
    vector<int>count(26);
    for(int i=1;i<s.length()-1;i++){
        count[s[i]-'a']++;
        if(s[i]==s[0] || s[i]==s[n-1]){
            cout<<"YES"<<endl;
            return;
        }
    }
    for(int i=0;i<26;i++){
        if(count[i]>1){
            cout<<"YES"<<endl;
            return;
        }
    }
    cout<<"NO"<<endl;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}