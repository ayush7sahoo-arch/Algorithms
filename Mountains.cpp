#include <bits/stdc++.h>

using namespace std;

#define int long long
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()
#define F first
#define S second
#define endl '\n'

const int MOD = 1e9 + 7;
const int INF = 1e18;

#ifdef LOCAL_DEBUG
#define debug(x) cerr << #x << " = " << x << endl
#else
#define debug(x) 
#endif

void solve(){
    int n,k;
    cin>>n>>k;
    vector<int>a(n);
    for(auto&i:a)cin>>i;

    vector<int>dp(n,0);
    int state=0;

    for(int i=0;i<n;i++){
        if(a[i]==0)state++;
        
        // if(state>=k || a[i])state=0;

        if(state>=k){
            state=0;
            if(i>0){dp[i]=dp[i-1]+1;}
            else{dp[i]=1;}
            if(i<n-1){dp[i+1]=dp[i];i++;}
        }else if(i>0){
            dp[i]=dp[i-1];
        }

        if(a[i])state=0;

    }

    // for(auto i:dp)cout<<i<<" ";
    // cout<<endl;
    cout<<dp[n-1]<<endl;
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t = 1;
    cin >> t;
    while(t--){
        solve();
    }

    return 0;
}