#include<iostream>
#include<vector>

using namespace std;

int main(){
    int t;
    cin>>t;
    for(int i=0;i<t;i++){
        int n;
        cin>>n;
        vector<int>arr(n);
        for(int j=0;j<n;j++){
            cin>>arr[j];
        }
        int amax=arr[0];
        int amin=arr[0];
        for(int j=0;j<n;j++){
            if(arr[j]>amax)amax=arr[j];
            if(arr[j]<amin)amin=arr[j];
        }
        cout<<(arr.size()-1)*(amax-amin)<<endl;
    }
}