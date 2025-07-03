#include<iostream>
using namespace std;

    string conv(int n){
        string ans="";
        while(n>0){
            ans.insert(0,1,'A'+n%26);
            n=n/26;
        }


        return ans;
    }

void solve(){
    string n;
    cin>>n;
    if(n[0]=='R' && n[1]!='C'){
        string r="";
        for(int i=1;n[i]!='C';i++){
            r+=n[i];
        }
        string c="";
        for(int i=n.find('C')+1;i<n.length();i++){
            c+=n[i];
        }
        
    }
    
}

int main(){
    int t;
    cin>>t;
    while(t--){
        // solve();
        cout<<conv(702)<<endl;
    }
}