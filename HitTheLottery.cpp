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
    int ans=0;
    ans+=n/100;n%=100;
    ans+=n/20;n%=20;
    ans+=n/10;n%=10;
    ans+=n/5;n%=5;
    ans+=n;

    cout<<ans<<endl;

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