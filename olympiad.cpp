#include<iostream>
#include<vector>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int>a(n);
        vector<int>b(n);
        
        for(int i=0;i<n;i++)cin>>a[i];
        for(int i=0;i<n;i++)cin>>b[i];

        if(n==1)cout<<a[0]<<endl;
        else{
            int ans=a[n-1];
            for(int i=0;i<n-1;i++){
                if(a[i]>b[i+1])ans+=(a[i]-b[i+1]);
            }
            cout<<ans<<endl;
        }

    }
}