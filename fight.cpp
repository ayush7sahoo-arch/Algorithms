#include<iostream>
#include<vector>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        long long n;
        cin>>n;
        vector<long long>p(n);
        for(int i=0;i<n;i++){
            cin>>p[i];
        }
        // int left=0;
        for(int i=0;i<n-2;i++){
            p[n-2]-=p[i];
        }
        cout<<p[n-1]-p[n-2]<<endl;
    }
}