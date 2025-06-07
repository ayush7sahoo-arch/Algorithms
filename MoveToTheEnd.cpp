#include<iostream>
#include<vector>
using namespace std;

int main(){
    int t;
    cin>>t;
    for(int i=0;i<t;i++){
        int n;
        cin>>n;
        vector<long long int>a(n);
        vector<long long int>pmax(n+1);
        vector<long long int>psum(n+1);
        for(int j=0;j<n;j++){
            cin>>a[j];
            pmax[j+1]=max(a[j],pmax[j]);
            // psum[j+1]=psum[j]+a[j];
        }
        long long int sum=0;
        for(int j=n;j>0;j--){
            sum+=a[j-1];
            psum[j-1]=sum;
        }

        for(int k=1;k<=n;k++){
            cout<<pmax[n-k+1]+psum[n-k+1]<<" ";
            
        }
        cout<<endl;
        
    }
}