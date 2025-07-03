#include<iostream>
#include<vector>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n,k;
        cin>>n>>k;
        if(k==0){
            cout<<0<<endl;
        }else{
            int d=1;
            k-=n;
            int i=1;
            while(k>0 && i<=n-1){
                k-=(n-i);
                d++;
                if(k>0){
                    k-=(n-i);
                    d++;
                }else{
                    break;
                }
                i++;
            }
            cout<<d<<endl;
        }
    }
}