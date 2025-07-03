#include<iostream>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n,k;
        cin>>n>>k;
        string ans="";
        if(n==k && n!=0)for(int i=0;i<n;i++)ans+="1";
        else if(k==0)for(int i=0;i<n;i++)ans+="0";
        else{
            ans+="1";
            for(int i=0;i<n-k-1;i++)ans+="0";
            for(int i=0;i<k-1;i++)ans+="1";
            ans+="0";
        }
        cout<<ans<<endl;
    }
}