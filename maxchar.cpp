#include <iostream>
#include <string>
using namespace std;

int calMax(string a,int s,int e){
    int z=0,o=0;
    int n=(e-s)+1;
    for(int i=s;i<=e;i++){
        if(a[i]=='0'){
            z++;
        }
        else{
            o++;
        }
    }
    return max(o,z);
}

void solve(){
    int n;
    cin>>n;
    string a;
    cin>>a;
    int ans=0;
    for(int i=0;i<a.length();i++){
        for(int j=i;j<a.length();j++){
            ans+=calMax(a,i,j);
        }
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
