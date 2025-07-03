#include <bits/stdc++.h>

using namespace std;

#define int long long
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()
#define F first
#define S second
#define endl '\n'

const int MOD = 1073741824;
const int INF = 1e18;

#ifdef LOCAL_DEBUG
#define debug(x) cerr << #x << " = " << x << endl
#else
#define debug(x) 
#endif


int calDev(int n){
    int c=0;
    for(int i=1;i<sqrt(n);i++){
        if(n%i==0)c++;
    }
    int s=(int)sqrt(n);
    
    return 2*c+(s*s==n);
}


void solve(){
    int a,b,c;
    cin>>a>>b>>c;
    int ans=0;
    vector<int>dp(1000001,0);

    for(int i=1;i<=a;i++){
        for(int j=1;j<=b;j++){
            for(int k=1;k<=c;k++){
                if(dp[i*j*k]==0){
                    dp[i*j*k]=calDev(i*j*k)%MOD;
                }
                ans+=dp[i*j*k]%MOD;
                ans%=MOD;
            }
        }
    }
    cout<<ans%MOD<<endl;
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // int t = 1;
    // cin >> t;
    // while(t--){
        solve();
    // }
    // cout<<calDev(20)<<endl;

    return 0;
}