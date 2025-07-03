#include<iostream>
#include<vector>
using namespace std;

void solve(){
    string s;
    cin>>s;
    bool firstZero=false;
    int zeros=0;
    int ones=0;
    for(int i=0;i<s.length();i++){
        if(s[i]=='0'){
            firstZero=true;
        }
        if(s[i]=='0' && firstZero){
            zeros++;
        }
        if(firstZero && s[i]=='1'){
            break;
        }
        if(!firstZero && s[i]=='1'){
            ones++;
        }
    }
    
    if(ones==s.length()){
        cout<<1<<" "<<s.length()<<" "<<1<<" "<<1<<endl;
    }else if(ones<=zeros){
        cout<<1<<" "<<s.length()<<" "<<1<<" "<<s.length()-ones<<endl;
    }else{
        cout<<1<<" "<<s.length()<<" "<<ones-zeros+1<<" "<<s.length()-zeros<<endl;
    }
}

int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}