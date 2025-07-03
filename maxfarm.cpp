#include<iostream>
#include<vector>
using namespace std;

void solve(){
    int n,m;
    cin>>n>>m;
    vector<vector<int>> f(n, vector<int>(m));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>f[i][j];
        }
    }

    vector<vector<int>>dp(n,vector<int>(m));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(i==0 || j==0)dp[i][j]=f[i][j];
            else{
                if(f[i][j]==1){
                    if(dp[i-1][j]==0 ||dp[i][j-1]==0||dp[i-1][j-1]==0)dp[i][j]=1;
                    else{
                    int k=min(dp[i-1][j],dp[i][j-1]);
                    dp[i][j]=k+(f[i-k][j-k]==1);
                    }
                }else{
                    dp[i][j]=0;
                }
            }
        }
    }
    int x=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            x=max(x,dp[i][j]);
        }
    }
    cout<<x<<endl;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}