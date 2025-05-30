#include<iostream>
#include<string>
#include <vector>
using namespace std;

int main(){
    int t;
    cin>>t;
    vector<string> ans(t);
    for(int i=0;i<t;i++){
        int n, m, p, q;
        cin>>n>>m>>p>>q;
        if(n%p==0 && n/p*q!=m){
            ans[i]="NO";
        }else{
            ans[i]="YES";
        }
        
    }
    
    for(int i=0;i<t;i++){
        cout<<ans[i]<<endl;
    }
    return 0;
}