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
    string s,f;
    cin>>s>>f;
    int off=0,s1=0,f1=0;

    for(int i=0;i<n;i++){
        if(s[i]!=f[i])off++;
        if(s[i]=='1')s1++;
        if(f[i]=='1')f1++;
    }
    int ans=abs(s1-f1);
    off-=ans;
    ans+=off/2;
    cout<<ans<<endl;
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