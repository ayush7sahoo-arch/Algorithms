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
    int n;
    cin>>n;
    vector<int>a(n);
    for(auto&i:a)cin>>i;
    vector<int>dp(n,0);
    dp[0]=1;
    for(int i=1;i<n;i++){
        if(a[i]>a[i-1])dp[i]=dp[i-1]+1;
        else dp[i]=1;
    }
    cout<<*max_element(all(dp))<<endl;
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t = 1;
    // cin >> t;
    while(t--){
        solve();
    }

    return 0;
}