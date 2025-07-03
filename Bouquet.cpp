#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n,m;
        cin>>n>>m;
        vector<int>f(n);
        for(int i=0;i<n;i++){
            cin>>f[i];
        }
        sort(f.begin(),f.end());
        int ans=0;
        for(int i=n-1;i>=0;i--){
            int j=i;
            int sum=f[j];
            int cur=f[j];j--;
            while(j>=0 && cur-f[j]<=1 && sum<=m){
                sum+=f[j];
                j--;
            }
            if(sum>m){
                sum-=f[j+1];
            }
            ans=max(ans,sum);
        }
        cout<<ans<<endl;
    }
}