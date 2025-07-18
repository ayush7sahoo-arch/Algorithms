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
    vector<int>h(n);
    for(auto&i:h)cin>>i;
    int now=h[k-1];
    sort(all(h));
    int l=1;
    bool made=false;
    
    for(int i=0;i<n;i++){
        if(h[i]<now)continue;

        if(now==h[n-1]){made=true;break;}
        if(i==n-1){made=true;break;}
        int time=h[i+1]-h[i];
        if(time>h[i]-l+1){break;}
        l+=time;
    }
    if(made)cout<<"YES\n";
    else cout<<"NO\n";
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